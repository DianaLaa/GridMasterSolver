/*
* Einstein Grid Master is an Android game.
* The aim of this little program: To find a solution to the Einstein Grid Master game.
*
* The aim of the game:
* Einstein Grid Master consists of a 100x100 grid. 
* Initially, the player must click a cell in the grid, in order to place the number (1)
* From then on, the player may click to place the succeeding number (2, 3, 4, etc) in another cell as follows:
*
* Given that (i) is placed in cell (x,y) and (i+1) is not yet present in the grid, (i+1) may be placed in a cell that is
* - Not yet occupied by a number
* - At any of the following eight places: (x-3,y), (x+3,y), (x,y-3), (x,y+3), (x+2,y+2), (x-2, y+2), (x-2, y-2), (x+2,y-2)
*
* Goal of the game: To occupy each cell in the grid with a number [0,100] according to these rules.
*/

#include "solver.h"
#include <stdio.h>

int main()
{
	Solver s;
	if (s.solve(10, 10))
	{
		printf("Solved!");
	}
	else
	{
		printf("No solution found...\n");
	}
	return(0);
}
