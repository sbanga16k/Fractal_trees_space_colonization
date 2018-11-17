// Code for declaring functions for leaf class to enable random distribution in
// the beginning and deletion as branch colonization takes place
#pragma once

#include<iostream>
#include <vector>
const double PI = 3.14159265359;

using namespace std;

// Transforms model coordinates to screen coordinates s.t origin lies in bottom right corner of graphics window
void getScreenCoords(double modelX, double modelY, double &screenX, double &screenY);

class Leaf {
private:
	int x, y, radius;			// x, y coordinates & radius of a leaf (represented as a point)
	int winWidth, winHeight;	// Width, height of graphics window
	bool reached;				// Flag indicated whether branch has reached close enough to leaf

public:
	Leaf();						// Default constructor
	void getPos(int &x_, int &y_);		// Function to get values of x, y coordinates of the leaf
	void setLeafReached();		// Sets flag indicator to true when branch reaching close enough to leaf
	bool getLeafReached();		// Returns value of 'reached' attribute
	void draw();				// Draws a leaf point on the graphics window
};