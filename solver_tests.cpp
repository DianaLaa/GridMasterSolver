#include "gtest/gtest.h"
#include "solver.h"

TEST(Solver, Solve_ZeroByZeroGrid_ReturnsFalse) 
{
	// Arrange
	Solver s;

	// Act
	bool result = s.solve(0, 0);

	// Assert
	ASSERT_FALSE(result);
}

TEST(Solver, Solve_ZeroByOneGrid_ReturnsFalse) 
{
	// Arrange
	Solver s;

	// Act
	bool result = s.solve(0, 1);

	// Assert
	ASSERT_FALSE(result);
}

TEST(Solver, Solve_OneByZeroGrid_ReturnsFalse) 
{
	// Arrange
	Solver s;

	// Act
	bool result = s.solve(1, 0);

	// Assert
	ASSERT_FALSE(result);
}

TEST(Solver, Solve_OneByOneGrid_ReturnsTrue) 
{
	// Arrange
	Solver s;

	// Act
	bool result = s.solve(1, 1);	

	// Assert
	ASSERT_TRUE(result);
}