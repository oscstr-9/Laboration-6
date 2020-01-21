#include "Circle.h"
#include "SDL.h"
#include <IOstream>
#include <math.h>

Circle::Circle(int rgbaIn[4], int radiusIn, Point2D positionIn) :Shape(rgbaIn, positionIn) {
	radius = radiusIn;
}

void Circle::Render(SDL_Renderer *renderer) {
	int numOfLines = 32;

	SDL_SetRenderDrawColor(renderer, rgba[0], rgba[1], rgba[2], rgba[3]);//set color

	//draw lines to form circle
	for (int i = 0; i <= numOfLines; i++) {
		SDL_RenderDrawLine(renderer, position.getX() + radius * cos((2 * M_PI / numOfLines)*i), position.getY() + radius * sin((2 * M_PI / numOfLines)*i),
			position.getX() + radius * cos((2 * M_PI / numOfLines)*(i + 1)), position.getY() + radius * sin((2 * M_PI / numOfLines)*(i + 1)));

	}
}

Circle::~Circle() {
}
