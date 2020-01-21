#include "Shape.h"
#include <IOstream>

using namespace std;

Shape::Shape(int rgbaIn[4], Point2D positionIn) {
	position = positionIn;
	setRgba(rgbaIn);
}

void Shape::setRgba(int newRgba[4]) {

	if (newRgba[0] > 255 || newRgba[1] > 255 || newRgba[2] > 255 || newRgba[3] > 255) { //if too much color, stop
		cout << "Can't comprehend such color!" << endl;
	}
	else {
		for (int i = 0; i < 4; i++) {
			rgba[i] = newRgba[i];
		}
	}
}


void Shape::setPosition(Point2D newPosition) {
	position = newPosition;
}

Point2D Shape::getPosition() {
	return position;
}


Shape::~Shape() {

}
