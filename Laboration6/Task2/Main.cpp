#include "Shape.h"
#include "Circle.h"
#include "SDL.h"
#include "Player.h"
#include "Enemy.h"
#include"GameObject.h"

#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

void renderingEnemy(vector<Enemy*> enemies, SDL_Renderer *renderer ) { //renders full vector of enemies and send them to update
	for (int i = 0; i < enemies.size(); i++) {
		enemies[i]->renderEnemy(renderer);
		enemies[i]->update();
	}
}

int main(int argc, char *argv[]) {
	vector<Enemy*> enemies;
	int spawnTimer = 0, numOfEnemies = 10;
	int windowWidth = 1200, windowHeight = 800, size = 50, x = windowWidth / 2, y = windowHeight / 2;
	int playerSpeed = 5;
	bool up = false, down = false, left = false, right = false;
	Player player(Point2D (x,y));
	GameObject::setWindowHeight(windowHeight);
	GameObject::setWindowWidth(windowWidth);
	SDL_Event event;

	int scoreTimer = 0;
	
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *window = SDL_CreateWindow("This is window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_RenderClear(renderer);

	while (true) {
		
		scoreTimer++;

		SDL_SetRenderDrawColor(renderer, 60, 60, 60, 255);//set background color
		SDL_RenderClear(renderer);

		//Keyboard inputs for movement
		while (SDL_PollEvent(&event)) {
			switch (event.type)
			{
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{

				case SDLK_w: {
					up = true;
					break;
				}

				case SDLK_a: {
					left = true;
					break;
				}
				case SDLK_s: {
					down = true;
					break;
				}
				case SDLK_d: {
					right = true;
					break;
				}
				case SDLK_q: {
					return 0;
				}
				}
				break;

			case SDL_KEYUP:
				switch (event.key.keysym.sym)
				{

				case SDLK_w: {
					up = false;
					break;
				}
				case SDLK_a: {
					left = false;
					break;
				}
				case SDLK_s: {
					down = false;
					break;
				}
				case SDLK_d: {
					right = false;
					break;
				}
				}
				break;
			}
		}

		if (up) {
			player.setVerticalVelocity(-playerSpeed);
		}
		if (down) {
			player.setVerticalVelocity(playerSpeed);
		}
		if (left) {
			player.setHorizontalvelocity(-playerSpeed);
		}
		if (right) {
			player.setHorizontalvelocity(playerSpeed);
		}
		player.update();

		player.renderPlayer(renderer);

		//call enemy class and create an enemy after set amount of time
		if (enemies.size() < numOfEnemies) {
			spawnTimer++;
		}

		if (spawnTimer >= 60) {
			
			enemies.push_back(new Enemy());//send enemy into enemy vector for later rendering and collision checking
			spawnTimer = 0;
		}
		renderingEnemy(enemies, renderer);

		SDL_RenderPresent(renderer);

		if (player.enemyCol(&enemies) == false) {// if player collides with enemy, end game en print score
			cout << "Your score is: " << scoreTimer / 10 << "!";
			return 0;
		}

		SDL_Delay(17);
	}
	for (int i = 0; i < enemies.size(); i++) {
		delete enemies[i];
	}
	return 0;
}