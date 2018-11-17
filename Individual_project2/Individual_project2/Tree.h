// Code for declaring functions for tree class to keep track of leaves
// and branches position, and grow as per space colonization algorithm
#pragma once

#include<vector>
#include"Branch.h"
#include"Leaf.h"

using namespace std;

class Tree {
private:
	double winWidth, winHeight;	// Specifies width & height of graphics window
	int minDist, maxDist;		// Distance bounds for a leaf to influence growth direction of branch
	int numLeaves;				// Specified number of leaf points for the branch to "colonize"
	vector<Leaf> allLeaves;		// Container for all leaf objects
	Branch *root;				// Specifies root branch for the tree
	vector<Branch*> branches;	// Container for all branch objects

public:
	Tree(int minDist_, int maxDist_, double width = 800., double height = 600.);	// default constructor
	void grow();
	void draw();		// Draws the leaf points & branch segments on the graphics window
};