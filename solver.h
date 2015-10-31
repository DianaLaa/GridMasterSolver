#pragma once

#include "grid.h"

class Solver
{
public:
	bool solve(int width, int height, IRuleSet& ruleSet);
private:
	bool solve(Grid& grid);
};
