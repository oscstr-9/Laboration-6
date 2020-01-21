#pragma once
#include "Circle.h"
#include "GameObject.h"

class Enemy:public GameObject
{
	Circle* enemyShape;
	int rgbArr[4] = { 255,0,0,255 };
	int verticalVelocity = 0;
	int horizontalVelocity = 0;
	Point2D *enemySpawnPos;

public:
	Enemy();
	void renderEnemy(SDL_Renderer *renderer);
	void setVerticalVelocity(int velocity);
	void setHorizontalvelocity(int velocity);
	Point2D getPosition();

	void update();
	~Enemy();
};

