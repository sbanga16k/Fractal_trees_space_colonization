// Code containing bodies of functions declared in the 'Branch.h' header file

#include<iostream>
#include"fssimplewindow.h"
#include"Branch.h"
#include"Leaf.h"

using namespace std;

// Default constructor for setting parameters of branch
Branch::Branch(double x_, double y_, vector<double> growthDir_, Branch *parent_)
{
	x = x_;
	y = y_;
	//cout << "New Branch X" << x_ << " Y " << y_ << endl;
	growthDir = growthDir_;
	origDir = growthDir_;
	parent = parent_;
	nearestLeafCount = 0;
	//if (parent != nullptr)
	//	cout << "Parent X" << parent_->x << " Y " << parent_->y << endl;
}


// Function for extracting coords of base of the branch
void Branch::getBasePos(double & x_, double & y_) {
	x_ = x; y_ = y;
}

void Branch::setDir(vector<double> dir_) {
	growthDir = dir_;
}

vector<double> Branch::getDir() {
	return growthDir;
}


int Branch::getCount() {
	return nearestLeafCount;
}

void Branch::incrementCount() {
	nearestLeafCount++;
}

void Branch::reset() {
	growthDir = origDir;
	nearestLeafCount = 0;
}


void Branch::draw()
{	
	double sCurrentX, sCurrentY;					// Store screen coords for current branch
	double parentX, parentY, sParentX, sParentY;	// Store physical & screen coords for parent branch
	if (parent != nullptr) {
		parent->getBasePos(parentX, parentY);

		// Obtaining screen coords using model coords for drawing branch
		getScreenCoords(x, y, sCurrentX, sCurrentY);
		getScreenCoords(parentX, parentY, sParentX, sParentY);

		glColor3f(1.0, 1.0, 1.0);	// Setting line color to white

		// Drawing the line from current to parent base point
		glBegin(GL_LINES);
		glVertex2d(sCurrentX, sCurrentY);
		glVertex2d(sParentX, sParentY);
		glEnd();
	}
}


// Function for creating the next branch using the attributes of the current branch
Branch* Branch::next()
{
	// Computing position of base for the next branch
	double nextPosX = x + growthDir[0]*2;
	double nextPosY = y + growthDir[1]*2;

	// Creating the next branch
	return new Branch(nextPosX, nextPosY, growthDir, this);
}