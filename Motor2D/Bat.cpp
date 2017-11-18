#include "j1App.h"
#include "Bat.h"
#include "j1Textures.h"
#include "j1Map.h"
#include "j1Render.h"
#include "j1Pathfinding.h"
#include "J1Player.h"
#include "j1Enemies.h"




Bat::Bat(int x, int y) : Enemy(x, y)
{
	position.x = fpos.x = x;
	position.y = fpos.y = y;
	LoadAnimation();
	CurrentAnim = &Idle;
}

void Bat::Move(float dt)
{
	x = position.x;
	iPoint player_pos;
	iPoint enemy_pos = App->map->GetPosition(App->map->data.tilesets.start->data, position.x, position.y);
	if (enemy_pos == PosTogo) {
		player_pos = App->map->GetPosition(App->map->data.tilesets.start->data, App->player->x, App->player->y);
		

		App->pathfinding->CreatePath(enemy_pos, player_pos, BAT);
		path = App->pathfinding->GetLastPath();
		path->Flip();
		path->Pop(PosTogo);
		path->Pop(PosTogo);
		
		App->pathfinding->last_path.Clear();

		//position = App->map->MapToWorld(enemy_pos.x, enemy_pos.y);
				
		pf.Start();
	}

		if (enemy_pos.x > PosTogo.x) {
			fpos.x -= 100 * dt;
		}
		else if (enemy_pos.x < PosTogo.x) {
			fpos.x += 100 * dt;
		}
		if (enemy_pos.y < PosTogo.y) {
			fpos.y += 100 * dt;
		}
		else if (enemy_pos.y > PosTogo.y) {
			fpos.y -= 100 * dt;
		}

		position.x = fpos.x;
		position.y = fpos.y;

		if (x == position.x)
			CurrentAnim = &Idle;
		else if (x >= position.x)
			CurrentAnim = &Left;
		else if (x <= position.x)
			CurrentAnim = &Right;
}

void Bat::Draw(SDL_Texture* texture) {
	App->render->Blit(texture, position.x, position.y, &CurrentAnim->GetCurrentFrame(), 1);
}


void Bat::LoadAnimation() {

	for (int i = 14; i < 18; i++) {
		Idle.PushBack({ App->enemies->animation_x[i],App->enemies->animation_y[i],App->enemies->animation_w[i],App->enemies->animation_h[i] });
	}
	Idle.loop = true;
	Idle.speed = 1.5f;

	for (int i = 18; i < 22; i++) {
		Left.PushBack({ App->enemies->animation_x[i],App->enemies->animation_y[i],App->enemies->animation_w[i],App->enemies->animation_h[i] });
	}
	Left.loop = true;
	Left.speed = 1.5f;

	for (int i = 22; i < 26; i++) {
		Right.PushBack({ App->enemies->animation_x[i],App->enemies->animation_y[i],App->enemies->animation_w[i],App->enemies->animation_h[i] });
	}
	Right.loop = true;
	Right.speed = 1.5f;
}

