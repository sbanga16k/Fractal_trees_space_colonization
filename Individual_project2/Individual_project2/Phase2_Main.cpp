// Program for performing space colonization algorithm for drawing branches
// to span a tree using the randomly generated points on the screen

#include<iostream>
#include<stdlib.h>
#include<time.h>
#include"fssimplewindow.h"
#include "Tree.h"
#include "Branch.h"
#include"Leaf.h"

using namespace std;

int main() {

	srand((unsigned int)(time(NULL)));	// Set seed for random number generator
	
	// Specifies min & max dist for leaf point to influence direction of branch segment growth
	int minDist = 10, maxDist = 100;

	// Initialize tree object
	Tree theTree(minDist, maxDist);

	// Program for executing program control in terms of termination
	bool terminate = false;

	FsOpenWindow(16, 16, 800, 600, 1);		// Using double buffer for animation
	glClearColor(0.0, 0.0, 0.0, 0.0);		// Set background color for graphics window to black

	while (!terminate) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		FsPollDevice();
		// Checking for program termination command
		if (FsGetKeyState(FSKEY_ESC))
			terminate = true;

		theTree.draw();		// Draws the tree as it grows
		theTree.grow();		// Makes the tree grow using space colonization algorithm

		FsSleep(10);
		FsSwapBuffers();
	}

	return 0;
}