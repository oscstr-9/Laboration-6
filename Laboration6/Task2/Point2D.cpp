#include <math.h>
#include "Point2D.h"

using namespace std;

//default constructor
Point2D::Point2D() {
	float pX = 0;
	float pY = 0;
}
//perameter constructor
Point2D::Point2D(float xIn, float yIn) {
	x = xIn;
	y = yIn;
}
//copy constructor
Point2D::Point2D(const Point2D &p) {
	x = p.x;
	y = p.y;
}

float Point2D::DistanceOfPoints(const Point2D &p) {
	float dist = abs(sqrt(pow(x - p.x, 2) + pow(y - p.y, 2)));
	return dist;
}

string Point2D::toString() {
	string stringPoint = to_string(x) + ", " + to_string(y);
	return stringPoint;
}

Point2D Point2D::operator+(const Point2D &p) {
	Point2D point;
	point.x = this->x + p.x;
	point.y = this->y + p.y;

	return point;
}
Point2D Point2D::operator=(const Point2D &p) {
	x = p.x;
	y = p.y;

	return *this;
}
bool Point2D::operator==(const Point2D &p) {
	return (x == p.x && y == p.y);
}

float Point2D::getX() {
	return x;
}
float Point2D::getY() {
	return y;
}
float Point2D::setX(float newX) {
	x = newX;
	return x;
}
float Point2D::setY(float newY) {
	y = newY;
	return y;
}
Point2D::~Point2D() {

}
