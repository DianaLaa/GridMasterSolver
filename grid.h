#pragma once

#include <vector>

enum Direction
{
	TOP = 0,
	TOP_RIGHT,
	RIGHT,
	BOTTOM_RIGHT,
	BOTTOM,
	BOTTOM_LEFT,
	LEFT,
	TOP_LEFT
};

class Grid
{
public:
	Grid(unsigned int width, unsigned int height);
	~Grid();

	void Start(unsigned int x, unsigned int y); // Place the first numbre at the given coordinate
	bool Test(Direction direction); // Test whether the next number may be placed
	void Next(Direction direction); // Place the next number
	void Previous(); // Remove the last number

	bool Validate(); // Determine whether the grid has any solutions left (any free cell that doesn't have two free neighbours disqualifies the solution)
	bool IsSolved(); 
private:
	unsigned int mWidth, mHeight; 	
	unsigned int mLastX, mLastY; // Last (x,y) coordinate at which a number was placed, (-1, -1) if n/a	
	unsigned int** mGrid; // 2D array of unsigned integers of dimensions mWidth * mHeight

	unsigned int NextX(Direction direction); // Returns the x-coordinate for the given direction. Returns (-1,-1) if Start has not been called yet.
	unsigned int NextY(Direction direction); // Returns the x-coordinate for the given direction. Returns (-1,-1) if Start has not been called yet.
};
