#pragma once

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

// Pure virtual interface for classes defining the rules by which the next digits may be placed in the grid
class INext
{
public:
	virtual ~INext() {};
	virtual int NextX(unsigned int currentX, Direction direction) = 0; // Returns the x-coordinate for the given direction. Returns -1 if currentX equals -1.
	virtual int NextY(unsigned int currentY, Direction direction) = 0; // Returns the y-coordinate for the given direction. Returns -1 if currentY equals -1.
};

// The rules used in the original game
class DefaultNext : public INext
{
public:
	int NextX(unsigned int currentX, Direction direction);
	int NextY(unsigned int currentY, Direction direction);
};

