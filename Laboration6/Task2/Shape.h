#pragma once
#include "Point2D.h"
#include "Shape.h"
#include "SDL.h"



class Shape {

protected:
	Point2D position;
	int rgba[4];

public:
	Shape(int rgbaIn[4], Point2D positionIn);
	~Shape();

	virtual void Render(SDL_Renderer *renderer) = 0;
	void setRgba(int newRgba[4]);
	void setPosition(Point2D newPosition);
	Point2D getPosition();
};

