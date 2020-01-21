#include "Enemy.h"
#include "Point2D.h"
#include"GameObject.h"
#include <time.h>




Enemy::Enemy():GameObject(25){
	srand((unsigned int)time(NULL));
	enemySpawnPos = new Point2D(rand() % (windowWidth - rand() % (300)) , rand() %(windowHeight - rand()%(200)) );
	enemyShape = new Circle(rgbArr, radius, *enemySpawnPos);
	setVerticalVelocity(rand() % 20 - 10 );
	setHorizontalvelocity(rand() % 20 - 10);
	while (verticalVelocity == 0 || horizontalVelocity == 0) { // if enemy is not moving enough, reroll its velocity
		setVerticalVelocity(rand() % 20 - 10);
		setHorizontalvelocity(rand() % 20 - 10);
	}
}

void Enemy::renderEnemy(SDL_Renderer *renderer) {
	enemyShape->Render(renderer);
}

void Enemy::setVerticalVelocity(int velocity) {
	verticalVelocity = velocity;
}

void Enemy::setHorizontalvelocity(int velocity) {
	horizontalVelocity = velocity;
}

Point2D Enemy::getPosition() {
	return enemyShape->getPosition();
}

void Enemy::update() {
	Point2D pos = enemyShape->getPosition();

	float tempX = pos.getX() + (float)horizontalVelocity;
	float tempY = pos.getY() + (float)verticalVelocity;

	//wall collision
	if (tempX > windowWidth - radius || tempX < 0 + radius) {
		setHorizontalvelocity(-horizontalVelocity);
	}
	if (tempY > windowHeight - radius || tempY < 0 + radius) {
		setVerticalVelocity(-verticalVelocity);
	}

	//set movement direction
	pos.setX(pos.getX() + (float)horizontalVelocity);
	pos.setY(pos.getY() + (float)verticalVelocity);

	enemyShape->setPosition(pos);//set new position


}


Enemy::~Enemy()
{
	delete enemyShape;
	delete enemySpawnPos;
}
