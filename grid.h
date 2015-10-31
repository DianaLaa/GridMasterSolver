#pragma once

#include <vector>
#include "ruleset.h"

class Grid
{
public:
	Grid(unsigned int width, unsigned int height, IRuleSet& ruleSet);
	~Grid();

	void Start(unsigned int x, unsigned int y); // Place the first number at the given coordinate
	bool Test(Direction direction); // Test whether the next number may be placed
	void Next(Direction direction); // Place the next number
	void Previous(); // Remove the last number

	bool CanContinue(); // Determine whether the grid has any solutions left. Returns true if there is at most one free cell that doesn't have at least two free neighbours. Returns false otherwise.
	bool IsSolved(); 
	void Print();
private:
	unsigned int mWidth, mHeight; 	
	unsigned int mLastX, mLastY; // Last (x,y) coordinate at which a number was placed, (-1, -1) if n/a	
	unsigned int** mGrid; // 2D array of unsigned integers of dimensions mWidth * mHeight
	IRuleSet& mRuleSet; // Generates next (x,y) coordinate based on mLastX/mLastY
};
