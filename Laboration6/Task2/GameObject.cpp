#include "GameObject.h"

int GameObject::windowWidth = 0;
int GameObject::windowHeight = 0;

GameObject::GameObject(int raiusIn){
	radius = raiusIn;
}

void GameObject::setWindowWidth(int windowWidthIn) {
	windowWidth = windowWidthIn;
}

void GameObject::setWindowHeight(int windowHeightIn) {
	windowHeight = windowHeightIn;
}
