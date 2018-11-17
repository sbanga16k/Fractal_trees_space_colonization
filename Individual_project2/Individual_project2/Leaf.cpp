// Code containing bodies of functions declared in the 'Leaf.h' header file

#include<iostream>
#include<stdlib.h>
#include"fssimplewindow.h"
#include"Leaf.h"

using namespace std;

// Transforms model coordinates to screen coordinates s.t origin lies in bottom right corner of graphics window
void getScreenCoords(double modelX, double modelY, double &screenX, double &screenY)
{
	double screenOriginX = 0, screenOriginY = 600;		/* Coordinates of origin of model in pixels */

														// Conversion to transform model coordinates to pixel coordinates
	screenX = (modelX + screenOriginX);
	screenY = (-modelY + screenOriginY);
}


// Draws filled circle at specified location with specified radius
void drawCircle(double centerX, double centerY, double radius)
{
	double screenX, screenY;			// Variables for pixel coordinates

	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);

	// Drawing an approximate circle using the below coordinates
	for (int i = 0; i < 60; i++) {
		double angle = double(i) * PI / 30.0;
		double x = double(centerX) + cos(angle)*double(radius);
		double y = double(centerY) + sin(angle)*double(radius);

		getScreenCoords(x, y, screenX, screenY);
		glVertex2d(screenX, screenY);
	}

	glEnd();
}


Leaf::Leaf() {
	// Setting height & width of graphics window
	winWidth = 800;
	winHeight = 600;

	x = rand() % winWidth;				// range of x is full width of window
	// range of y is 60% of window height starting from top
	y = int(rand() % (winHeight*3/5) + (winHeight*0.4));
	radius = 2;
	reached = false;

	//cout << "X " << x << " Y " << y << endl;
}

void Leaf::getPos(int &x_, int &y_) {
	x_ = x;	y_ = y;
}

void Leaf::setLeafReached() {
	reached = true;
}

// Returns value of 'reached' attribute
bool Leaf::getLeafReached() {
	return reached;
}

void Leaf::draw() {
	drawCircle(x, y, radius);
}