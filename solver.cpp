#include "solver.h"

bool Solver::solve(int width, int height)
{
	// Only test approx. one-eight of the grid's starting positions, because all others are equivalent due to symmetry.
	for (int x = 0; x < (width + 1) / 2; ++x)
	{
		for (int y = 0; y < (height + 1) / 2; ++y)
		{
			if (y <= x)
			{
				// If a solution was found, stop
				Grid grid(width, height);
				grid.Start(x, y);
				if (solve(grid))
				{
					return true;
				}
				// No solution found for this starting position, continue trying others.
			}
		}
	}
	
	return false;
}


bool Solver::solve(Grid& grid)
{
	if (grid.IsSolved())
	{
		return true;
	}

	// Precondition: At least one index has already been placed	
	// Place the first available number: recursively try out all possibilities until a solution is found.	
	for (int i = 0; i < 8; i ++)
	{
		if (grid.Test((Direction)i))
		{
			grid.Next((Direction)i);

			//	If we're finished, return true
			if (grid.IsSolved())
			{
				return true;
			}
			// Otherwisee, check if we can still move forward and if so, recursively call solve
			else if (grid.Validate())
			{
				if (solve(grid))
				{
					return true;
				}
			}
			grid.Previous();
		}
	}
		
	return false;
}
