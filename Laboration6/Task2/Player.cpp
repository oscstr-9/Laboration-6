#include "Player.h"
#include "Point2D.h"
#include"GameObject.h"
#include <vector>
#include <iostream>


Player::Player(Point2D positionIn):GameObject(25)
{
	shape = new Circle(rgbArr, radius, positionIn);
}

void Player::renderPlayer(SDL_Renderer *renderer) {
	shape->Render(renderer);
}

void Player::setVerticalVelocity(int velocity) {
	verticalVelocity = velocity;
}

void Player::setHorizontalvelocity(int velocity) {
	horizontalVelocity = velocity;
}

void Player::update() {
	Point2D pos = shape->getPosition();
	float tempX = pos.getX() + (float)horizontalVelocity;
	float tempY = pos.getY() + (float)verticalVelocity;

	// wall collison
	if (tempX < windowWidth - radius && tempX > 0 + radius) {
		pos.setX(pos.getX() + (float)horizontalVelocity);
	}
	if (tempY < windowHeight - radius && tempY > 0 + radius) {
		pos.setY(pos.getY() + (float)verticalVelocity);
	}

	shape->setPosition(pos);// move player to new location
	//reset velocity
	verticalVelocity = 0;
	horizontalVelocity = 0;
}

int Player::enemyCol(std::vector<Enemy*> *enemies) {
	Point2D pos = shape->getPosition();

	for (int i = 0; i < enemies->size(); i++) {
		// set colision distance from enemies
		if (pow((*enemies)[i]->getPosition().getX() - pos.getX(),2) + pow((*enemies)[i]->getPosition().getY() - pos.getY(),2) <= pow(radius*2.0f,2)) {
			return 0;
		}
	}
}

Player::~Player(){
	delete shape;
}