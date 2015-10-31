#include "grid.h"
#include <stdio.h>
#include <string>

Grid::Grid(unsigned int width, unsigned int height, IRuleSet& ruleSet) :
	mWidth(width),
	mHeight(height),
	mLastX(-1),
	mLastY(-1),
	mGrid(new unsigned int* [mWidth]),
	mRuleSet(ruleSet)
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

	int nextX = mRuleSet.NextX(mLastX, direction);
	int nextY = mRuleSet.NextY(mLastY, direction);

	if (nextX >= 0 && (unsigned int)nextX < mWidth && nextY >= 0 && (unsigned int)nextY < mHeight)
	{
		if (mGrid[(unsigned int)nextX][(unsigned int)nextY] == (unsigned int)-1)
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
	int nextX = mRuleSet.NextX(mLastX, direction);
	int nextY = mRuleSet.NextY(mLastY, direction);

	if (nextX >= 0 && (unsigned int)nextX < mWidth && nextY >= 0 && (unsigned int)nextY < mHeight)
	{
		mGrid[(unsigned int)nextX][(unsigned int)nextY] = nextNumber;
		mLastX = nextX;
		mLastY = nextY;
	}
}

void Grid::Previous()
{
	if (mLastX == (unsigned int)-1 || mLastY == (unsigned int)-1)
	{
		return;
	}

	// Find the previous index by inspecting all directions.
	for (int i = 0; i < 8; i ++)
	{
		Direction direction = static_cast<Direction>(i);
		int nextX = mRuleSet.NextX(mLastX, direction);
		int nextY = mRuleSet.NextY(mLastY, direction);

		if (nextX >= 0 && (unsigned int)nextX < mWidth && nextY >= 0 && (unsigned int)nextY < mHeight)
		{
			if (mGrid[(unsigned int)nextX][(unsigned int)nextY] == mGrid[mLastX][mLastY] - 1)
			{
				mGrid[mLastX][mLastY] = -1;
				mLastX = nextX;
				mLastY = nextY;
				return;
			}
		}
	}

	// If there's nothing to go back to, reset mLastX/mLastY to -1
	mGrid[mLastX][mLastY] = -1;
	mLastX = -1;
	mLastY = -1;
}

bool Grid::CanContinue()
{
	if (IsSolved())
	{
		return false;
	}

	if (mLastX == (unsigned int)-1 || mLastY == (unsigned int)-1)
	{
		// Game wasn't started yet, of course we can still continue.
		return true;
	}

	// When are we sure that we can not continue?
	// 1. When there are two or more cells that are not reachable from the last position, that have at most one free neighbour

	int terminalCells = 0; // Number of cells that do not have at least two free neighbours and are not reachable from the last position
	int emptyCells = 0;
	for(unsigned int w = 0; w < mWidth; ++w)
	{
		for (unsigned int h = 0; h < mHeight; ++h)
		{
			// Only consider empty cells
			if (mGrid[w][h] != (unsigned int)-1)
			{
				continue;
			}

			emptyCells++;

			// Determine how many neighbours it can reach that are empty
			// Note: This assumes symmetrical rules
			int reachableNeighbours = 0;
			bool lastCellReachable = false;
			for (int i = 0; i < 8; i ++)
			{
				Direction direction = static_cast<Direction>(i);
				int nextX = mRuleSet.NextX(w, direction);
				int nextY = mRuleSet.NextY(h, direction);

				if (nextX >= 0 && (unsigned int)nextX < mWidth && nextY >= 0 && (unsigned int)nextY < mHeight)
				{
					if (mGrid[(unsigned int)nextX][(unsigned int)nextY] == (unsigned int)-1)
					{
						reachableNeighbours++;
					}
					if ((unsigned int)nextX == mLastX && (unsigned int)nextY == mLastY)
					{
						lastCellReachable = true;
					}
				}
			}

			if (reachableNeighbours < 2 && lastCellReachable == false)
			{
				terminalCells++;
			}
		}
	}

	if (terminalCells > 1 || terminalCells == emptyCells)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Grid::IsSolved()
{
	if (mWidth == 0 || mHeight == 0)
	{
		return true;
	}

	if (mLastX != (unsigned int)-1 && mLastY != (unsigned int)-1)
	{
		return  mGrid[mLastX][mLastY] == mWidth * mHeight;
	}

	return false;
}

template <class T>
int numDigits(T number)
{
    int digits = 0;
    if (number < 0) digits = 1;
    while (number) {
        number /= 10;
        digits++;
    }
    return digits;
}


void Grid::Print()
{
	for (unsigned int h = 0; h < mHeight; ++h)
	{
		for(unsigned int w = 0; w < mWidth; ++w)
		{
			// Create the formatstring that prefixes the numbers with enough spaces to align the rows and columns
			char buffer[10];
			sprintf(buffer, "%%%ii ", numDigits(mWidth * mHeight));
			buffer[10] = 0;

			std::string foo;
			foo.resize(10);
			int num_bytes = snprintf(&foo[0], 10, "%%%ii ", numDigits(mWidth * mHeight));
			if(num_bytes < 10)
			{
				foo.resize(num_bytes);
			}

			printf(foo.c_str(), mGrid[w][h]);
		}
		printf("\n");
	}
}
