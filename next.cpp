#include "next.h"

//////////////////////////////////////////////////////////////////
// public class DefaultNext
//////////////////////////////////////////////////////////////////

int DefaultNext::NextX(unsigned int currentX, Direction direction)
{
	if (currentX == (unsigned int)-1)
	{
		return -1;
	}

	int result = currentX;

	switch (direction)
	{
		case TOP: 
			result = currentX;
			break;
		case TOP_RIGHT:
			result = currentX + 2;
			break;
		case RIGHT: 
			result = currentX + 3;
			break;
		case BOTTOM_RIGHT: 
			result = currentX + 2;
			break;
		case BOTTOM: 
			result = currentX;
			break;
		case BOTTOM_LEFT: 
			result = currentX - 2;
			break;
		case LEFT: 
			result = currentX - 3;
			break;
		case TOP_LEFT: 
			result = currentX - 2;
			break;
		default: break;
	}

	return result;
}


int DefaultNext::NextY(unsigned int currentY, Direction direction)
{
	if (currentY == (unsigned int)-1)
	{
		return -1;
	}

	int result = currentY;

	switch (direction)
	{
		case TOP: 
			result = currentY - 3;
			break;
		case TOP_RIGHT:
			result = currentY - 2;
			break;
		case RIGHT: 
			result = currentY;
			break;
		case BOTTOM_RIGHT: 
			result = currentY + 2;
			break;
		case BOTTOM: 
			result = currentY + 3;
			break;
		case BOTTOM_LEFT: 
			result = currentY + 2;
			break;
		case LEFT: 
			result = currentY;
			break;
		case TOP_LEFT: 
			result = currentY - 2;
			break;
		default: break;
	}

	return result;
}
