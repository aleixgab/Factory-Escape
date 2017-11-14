#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "p2Point.h"
#include "Animation.h"

struct SDL_Texture;
struct Collider;

class Enemy
{
protected:
	Animation* animation = nullptr;
	

public:
	iPoint position;
	SDL_Texture* textureGhost;
	uint hitpoints = 2;
	Collider* collider = nullptr;
public:
	Enemy(int x, int y);
	virtual ~Enemy();



	virtual void Move(float dt) {};
	virtual void Draw(SDL_Texture* sprites);

};

#endif // __ENEMY_H__