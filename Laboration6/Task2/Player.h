#pragma once
#include "Circle.h"
#include "Enemy.h"
#include <vector>
#include "GameObject.h"

class Player: public GameObject
{
	Circle* shape;
	int rgbArr[4] = { 50,100,200,255 };
	int verticalVelocity = 0;
	int horizontalVelocity = 0;
	int playerHealth = 1;
public:
	Player(Point2D positionIn);
	void renderPlayer(SDL_Renderer *renderer);
	void setVerticalVelocity(int velocity);
	void setHorizontalvelocity(int velocity);
	void update();
	int enemyCol(std::vector<Enemy*> *enemies);
	~Player();
};

