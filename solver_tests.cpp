#include "gtest/gtest.h"
#include "solver.h"

// All directions one step, resulting in complete freedom
class FreedomRuleSet : public IRuleSet
{
public:
	int NextX(unsigned int currentX, Direction direction)
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
				result = currentX + 1;
				break;
			case RIGHT: 
				result = currentX + 1;
				break;
			case BOTTOM_RIGHT: 
				result = currentX + 1;
				break;
			case BOTTOM: 
				result = currentX;
				break;
			case BOTTOM_LEFT: 
				result = currentX - 1; 
				break;
			case LEFT: 
				result = currentX - 1;
				break;
			case TOP_LEFT: 
				result = currentX - 1;
				break;
			default: break;
		}

		return result;
	};

	int NextY(unsigned int currentY, Direction direction)
	{
		if (currentY == (unsigned int)-1)
		{
			return -1;
		}

		int result = currentY;

		switch (direction)
		{
			case TOP: 
				result = currentY - 1;
				break;
			case TOP_RIGHT:
				result = currentY - 1;
				break;
			case RIGHT: 
				result = currentY;
				break;
			case BOTTOM_RIGHT: 
				result = currentY + 1;
				break;
			case BOTTOM: 
				result = currentY + 1;
				break;
			case BOTTOM_LEFT: 
				result = currentY + 1;
				break;
			case LEFT: 
				result = currentY;
				break;
			case TOP_LEFT: 
				result = currentY - 1;
				break;
			default: break;
		}

		return result;
	};
};

TEST(Solver, Solve_DefaultRules_ZeroByZeroGrid_ReturnsFalse) 
{
	// Arrange
	DefaultRuleSet ruleSet;
	Solver s;

	// Act
	bool result = s.solve(0, 0, ruleSet);

	// Assert
	ASSERT_FALSE(result);
}

TEST(Solver, Solve_DefaultRules_ZeroByOneGrid_ReturnsFalse) 
{
	// Arrange
	DefaultRuleSet ruleSet;
	Solver s;

	// Act
	bool result = s.solve(0, 1, ruleSet);

	// Assert
	ASSERT_FALSE(result);
}

TEST(Solver, Solve_DefaultRules_OneByZeroGrid_ReturnsFalse) 
{
	// Arrange
	DefaultRuleSet ruleSet;
	Solver s;

	// Act
	bool result = s.solve(1, 0, ruleSet);

	// Assert
	ASSERT_FALSE(result);
}

TEST(Solver, Solve_DefaultRules_OneByOneGrid_ReturnsTrue) 
{
	// Arrange
	DefaultRuleSet ruleSet;
	Solver s;

	// Act
	bool result = s.solve(1, 1, ruleSet);	

	// Assert
	ASSERT_TRUE(result);
}

TEST(Solver, Solve_FreedomRuleSet_TwoByTwoGrid_ReturnsTrue)
{
	// Arrange
	FreedomRuleSet ruleSet;
	Solver s;

	// Act
	bool result = s.solve(2, 2, ruleSet);

	// Assert
	ASSERT_TRUE(result);
}
