#include "grid.h"
#include <stdio.h>

Grid::Grid(unsigned int width, unsigned int height) : 
	mWidth(width),
	mHeight(height),
	mLastX(-1),
	mLastY(-1),
	mGrid(new unsigned int* [mWidth])
{
	for(unsigned int w = 0; w < mWidth; ++w)
	{
		mGrid[w] = new unsigned int[mHeight];
		for (unsigned int h = 0; h < mHeight; ++h)
		{
			mGrid[w][h] = (unsigned int)-1;
		}
	}
}

Grid::~Grid()
{
	delete [] mGrid;
}


void Grid::Start(unsigned int x, unsigned int y)
{
	if (x >= mWidth || y >= mHeight)
	{
		return;
	}

	if (mLastX == (unsigned int)-1 || mLastY == (unsigned int)-1)
	{
		mGrid[x][y] = 1;
		mLastX = x;
		mLastY = y;
	}
	// Calling Start a second time has no effect
}

bool Grid::Test(Direction direction)
{
	if (mLastX == (unsigned int)-1 || mLastY == (unsigned int)-1)
	{
		return false;
	}

	unsigned int nextX = NextX(direction);
	unsigned int nextY = NextY(direction);

	if (nextX >= 0 && nextX < mWidth && nextY >= 0 && nextY < mHeight)
	{
		if (mGrid[nextX][nextY] == (unsigned int)-1)
		{
			return true;
		}
	}

	return false;
}

void Grid::Next(Direction direction)
{
	if (!Test(direction))
	{
		return;
	}

	unsigned int nextNumber = mGrid[mLastX][mLastY] + 1;
	unsigned int nextX = NextX(direction);
	unsigned int nextY = NextY(direction);
	mGrid[nextX][nextY] = nextNumber;
}

void Grid::Previous()
{
	if (mLastX == (unsigned int)-1 || mLastY == (unsigned int)-1)
	{
		return;
	}

	mGrid[mLastX][mLastY] = -1;
	// Find the previous index by inspecting all directions. If there's nothing to go back to, reset mLastX/mLastY to -1
	for (int i = 0; i < 8; i ++)
	{
		// TODO 
	}
}

bool Grid::Validate()
{
	// TODO
	return false;
}

bool Grid::IsSolved()
{
	if (mLastX != (unsigned int)-1 && mLastY != (unsigned int)-1)
	{
		return  mGrid[mLastX][mLastY] == mWidth * mHeight;
	}

	return false;
}

unsigned int Grid::NextX(Direction direction)
{
	if (mLastX == (unsigned int)-1 || mLastY == (unsigned int)-1)
	{
		return -1;
	}

	unsigned int result = mLastX;

	switch (direction)
	{
		case TOP: 
			result = mLastX;
			break;
		case TOP_RIGHT:
			result = mLastX + 2;
			break;
		case RIGHT: 
			result = mLastX + 3;
			break;
		case BOTTOM_RIGHT: 
			result = mLastX + 2;
			break;
		case BOTTOM: 
			result = mLastX;
			break;
		case BOTTOM_LEFT: 
			result = mLastX -2;
			break;
		case LEFT: 
			result = mLastX - 3;
			break;
		case TOP_LEFT: 
			result = mLastX - 2;
			break;
		default: break;
	}

	return result;
}

unsigned int Grid::NextY(Direction direction)
{
	if (mLastX == (unsigned int)-1 || mLastY == (unsigned int)-1)
	{
		return (unsigned int)-1;
	}

	unsigned int result = mLastY;

	switch (direction)
	{
		case TOP: 
			result = mLastY - 3;
			break;
		case TOP_RIGHT:
			result = mLastY - 2;
			break;
		case RIGHT: 
			result = mLastY;
			break;
		case BOTTOM_RIGHT: 
			result = mLastY + 2;
			break;
		case BOTTOM: 
			result = mLastY + 3;
			break;
		case BOTTOM_LEFT: 
			result = mLastY + 2;
			break;
		case LEFT: 
			result = mLastY;
			break;
		case TOP_LEFT: 
			result = mLastY - 2;
			break;
		default: break;
	}

	return result;
}

