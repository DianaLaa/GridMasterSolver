#pragma once

#include "grid.h"

class Solver
{
public:
	bool solve(int width, int height);
private:
	bool solve(Grid& grid);
};
