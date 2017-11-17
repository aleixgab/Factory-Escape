#ifndef __BLOP_H__
#define __BLOP_H__

#include "Enemy.h"
#include "p2Point.h"
#include "p2DynArray.h"
#include "j1Render.h"

class Blop : public Enemy
{
private:

	int x;
	int Tile_h = 62;
	Animation Idle;
	Animation Walk;
	Animation* CurrentAnim = nullptr;

	//SDL_RendererFlip flip = SDL_FLIP_NONE;

	iPoint originalpos;

	void LoadAnimation();

public:
	Blop(int x, int y);

	p2DynArray<iPoint>* path;
	j1Timer pf;
	SDL_RendererFlip flip;
	//	void OnCollision(Collider* c1, Collider* c2);

	void Move(float dt);
	void Draw(SDL_Texture* texture);
};

#endif