#pragma once
#include <string>

class Point2D {

	float x;
	float y;

public:
	Point2D();
	Point2D(float xIn, float yIn);
	Point2D(const Point2D &p);
	~Point2D();

	Point2D operator+(const Point2D &p);
	Point2D operator=(const Point2D &p);
	bool operator==(const Point2D &p);
	float DistanceOfPoints(const Point2D &p);

	float getX();
	float getY();

	float setX(float newX);
	float setY(float newY);

	std::string toString();
};

