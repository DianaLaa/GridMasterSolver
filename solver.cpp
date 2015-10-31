#include "solver.h"
#include "ruleset.h"
#include <stdio.h>

bool Solver::solve(int width, int height, IRuleSet& ruleSet)
{
	// Only test approx. one-eight of the grid's starting positions, because all others are equivalent due to symmetry.
	for (int x = 0; x < (width + 1) / 2; ++x)
	{
		for (int y = 0; y < (height + 1) / 2; ++y)
		{
			if (y <= x)
			{
				// If a solution was found, stop
				printf("Start position (%i, %i)\n", x, y);
				Grid grid(width, height, ruleSet);
				grid.Start(x, y);
				if (solve(grid))
				{
					printf("Solved!\n");
					grid.Print();
					return true;
				}
				else
				{
					printf("No solution found...\n");
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
	for (int i = 0; i < 8; i++)
	{
		Direction direction = static_cast<Direction>(i);
		if (grid.Test(direction))
		{
			grid.Next(direction);

			//	If we're finished, return true
			if (grid.IsSolved())
			{
				return true;
			}
			// Otherwise, check if we can still move forward and if so, recursively call solve
			else if (grid.CanContinue())
			{
				if (solve(grid))
				{
					return true;
				}
			}
			
			grid.Previous();
		}
		// If all directions have been tried but none were accessible, returns from this branch with 'false'
	}
		
	return false;
}
