#include "gtest/gtest.h"
#include "grid.h"

// All directions one step, resulting in complete freedom
class FreeRuleSet : public IRuleSet
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

//////////////////////////////////////////////////////////////////
// bool Test(Direction direction);
//////////////////////////////////////////////////////////////////

TEST(Grid, Test_TwoByTwo_LastCellAccessible)
{
	// Arrange
	FreeRuleSet ruleSet;
	Grid grid(2, 2, ruleSet);
	grid.Start(0, 0);
	grid.Next(RIGHT);
	grid.Next(BOTTOM);
	
	// Act
	bool result = grid.Test(LEFT);
	
	// Assert
	ASSERT_TRUE(result);
}

TEST(Grid, Test_ThreeByThree_NoIndexPlaced_ReturnsFalse) 
{
	// Arrange
	DefaultRuleSet ruleSet;
	Grid grid(3, 3, ruleSet);
	
	// Act
	bool result = grid.Test(TOP);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_ThreeByThree_TopLeftIndexPlaced_Top_ReturnsFalse) 
{
	// Arrange
	DefaultRuleSet ruleSet;
	Grid grid(3, 3, ruleSet);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.Test(TOP);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_ThreeByThree_TopLeftIndexPlaced_TopRight_ReturnsFalse) 
{
	// Arrange
	DefaultRuleSet ruleSet;
	Grid grid(3, 3, ruleSet);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.Test(TOP_RIGHT);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_DefaultRuleSet_ThreeByThree_TopLeftIndexPlaced_Right_ReturnsFalse)
{
	// Arrange
	DefaultRuleSet ruleSet; // Default game rules
	Grid grid(3, 3, ruleSet);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.Test(RIGHT);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_ThreeByThree_TopLeftIndexPlaced_BottomRight_ReturnsTrue)
{
	// Arrange
	DefaultRuleSet ruleSet;
	Grid grid(3, 3, ruleSet);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.Test(BOTTOM_RIGHT);
	
	// Assert
	ASSERT_TRUE(result);
}

TEST(Grid, Test_ThreeByThree_TopLeftIndexPlaced_Bottom_ReturnsFalse)
{
	// Arrange
	DefaultRuleSet ruleSet; // Default game rules
	Grid grid(3, 3, ruleSet);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.Test(BOTTOM);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_ThreeByThree_TopLeftIndexPlaced_BottomLeft_ReturnsFalse) 
{
	// Arrange
	DefaultRuleSet ruleSet;
	Grid grid(3, 3, ruleSet);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.Test(BOTTOM_LEFT);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_ThreeByThree_TopLeftIndexPlaced_Left_ReturnsFalse) 
{
	// Arrange
	DefaultRuleSet ruleSet;
	Grid grid(3, 3, ruleSet);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.Test(LEFT);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_ThreeByThree_TopLeftIndexPlaced_TopLeft_ReturnsFalse) 
{
	// Arrange
	DefaultRuleSet ruleSet;
	Grid grid(3, 3, ruleSet);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.Test(TOP_LEFT);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FourByFour_NoIndexPlaced_ReturnsFalse) 
{
	// Arrange
	DefaultRuleSet ruleSet;
	Grid grid(4, 4, ruleSet);
	
	// Act
	bool result = grid.Test(TOP);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FourByFour_TopLeftIndexPlaced_Top_ReturnsFalse) 
{
	// Arrange
	DefaultRuleSet ruleSet;
	Grid grid(4, 4, ruleSet);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.Test(TOP);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FourByFour_TopLeftIndexPlaced_TopRight_ReturnsFalse) 
{
	// Arrange
	DefaultRuleSet ruleSet;
	Grid grid(4, 4, ruleSet);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.Test(TOP_RIGHT);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FourByFour_TopLeftIndexPlaced_Right_ReturnsTrue)
{
	// Arrange
	DefaultRuleSet ruleSet;
	Grid grid(4, 4, ruleSet);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.Test(RIGHT);
	
	// Assert
	ASSERT_TRUE(result);
}

TEST(Grid, Test_FourByFour_TopLeftIndexPlaced_BottomRight_ReturnsTrue)
{
	// Arrange
	DefaultRuleSet ruleSet;
	Grid grid(4, 4, ruleSet);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.Test(BOTTOM_RIGHT);
	
	// Assert
	ASSERT_TRUE(result);
}

TEST(Grid, Test_FourByFour_TopLeftIndexPlaced_Bottom_ReturnsTrue)
{
	// Arrange
	DefaultRuleSet ruleSet;
	Grid grid(4, 4, ruleSet);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.Test(BOTTOM);
	
	// Assert
	ASSERT_TRUE(result);
}

TEST(Grid, Test_FourByFour_TopLeftIndexPlaced_BottomLeft_ReturnsFalse) 
{
	// Arrange
	DefaultRuleSet ruleSet;
	Grid grid(4, 4, ruleSet);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.Test(BOTTOM_LEFT);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FourByFour_TopLeftIndexPlaced_Left_ReturnsFalse) 
{
	// Arrange
	DefaultRuleSet ruleSet;
	Grid grid(4, 4, ruleSet);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.Test(LEFT);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FourByFour_TopLeftIndexPlaced_TopLeft_ReturnsFalse) 
{
	// Arrange
	DefaultRuleSet ruleSet;
	Grid grid(4, 4, ruleSet);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.Test(TOP_LEFT);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FiveByFive_TopLeftIndexPlaced_Top_ReturnsFalse)
{
	// Arrange
	DefaultRuleSet ruleSet;
	Grid grid(5, 5, ruleSet);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.Test(TOP);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FiveByFive_TopLeftIndexPlaced_TopRight_ReturnsFalse)
{
	// Arrange
	DefaultRuleSet ruleSet;
	Grid grid(5, 5, ruleSet);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.Test(TOP_RIGHT);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FiveByFive_TopLeftIndexPlaced_Right_ReturnsTrue)
{
	// Arrange
	DefaultRuleSet ruleSet;
	Grid grid(5, 5, ruleSet);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.Test(RIGHT);
	
	// Assert
	ASSERT_TRUE(result);
}

TEST(Grid, Test_FiveByFive_TopLeftIndexPlaced_BottomRight_ReturnsTrue)
{
	// Arrange
	DefaultRuleSet ruleSet;
	Grid grid(5, 5, ruleSet);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.Test(BOTTOM_RIGHT);
	
	// Assert
	ASSERT_TRUE(result);
}

TEST(Grid, Test_FiveByFive_TopLeftIndexPlaced_Bottom_ReturnsTrue)
{
	// Arrange
	DefaultRuleSet ruleSet;
	Grid grid(5, 5, ruleSet);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.Test(BOTTOM);
	
	// Assert
	ASSERT_TRUE(result);
}

TEST(Grid, Test_FiveByFive_TopLeftIndexPlaced_BottomLeft_ReturnsFalse)
{
	// Arrange]
	DefaultRuleSet ruleSet;
	Grid grid(5, 5, ruleSet);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.Test(BOTTOM_LEFT);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FiveByFive_TopLeftIndexPlaced_Left_ReturnsFalse)
{
	// Arrange
	DefaultRuleSet ruleSet;
	Grid grid(5, 5, ruleSet);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.Test(LEFT);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FiveByFive_TopLeftIndexPlaced_TopLeft_ReturnsFalse)
{
	// Arrange
	DefaultRuleSet ruleSet;
	Grid grid(5, 5, ruleSet);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.Test(TOP_LEFT);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FiveByFive_TopRightIndexPlaced_Top_ReturnsFalse)
{
	// Arrange
	DefaultRuleSet ruleSet;
	Grid grid(5, 5, ruleSet);
	grid.Start(4, 0);
	
	// Act
	bool result = grid.Test(TOP);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FiveByFive_TopRightIndexPlaced_TopRight_ReturnsFalse)
{
	// Arrange
	DefaultRuleSet ruleSet;
	Grid grid(5, 5, ruleSet);
	grid.Start(4, 0);
	
	// Act
	bool result = grid.Test(TOP_RIGHT);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FiveByFive_TopRightIndexPlaced_Right_ReturnsFalse)
{
	// Arrange
	DefaultRuleSet ruleSet;
	Grid grid(5, 5, ruleSet);
	grid.Start(4, 0);
	
	// Act
	bool result = grid.Test(RIGHT);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FiveByFive_TopRightIndexPlaced_BottomRight_ReturnsFalse)
{
	// Arrange
	DefaultRuleSet ruleSet;
	Grid grid(5, 5, ruleSet);
	grid.Start(4, 0);
	
	// Act
	bool result = grid.Test(BOTTOM_RIGHT);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FiveByFive_TopRightIndexPlaced_Bottom_ReturnsTrue)
{
	// Arrange
	DefaultRuleSet ruleSet;
	Grid grid(5, 5, ruleSet);
	grid.Start(4, 0);
	
	// Act
	bool result = grid.Test(BOTTOM);
	
	// Assert
	ASSERT_TRUE(result);
}

TEST(Grid, Test_FiveByFive_TopRightIndexPlaced_BottomLeft_ReturnsTrue)
{
	// Arrange
	DefaultRuleSet ruleSet;
	Grid grid(5, 5, ruleSet);
	grid.Start(4, 0);
	
	// Act
	bool result = grid.Test(BOTTOM_LEFT);
	
	// Assert
	ASSERT_TRUE(result);
}

TEST(Grid, Test_FiveByFive_TopRightIndexPlaced_Left_ReturnsTrue)
{
	// Arrange
	DefaultRuleSet ruleSet;
	Grid grid(5, 5, ruleSet);
	grid.Start(4, 0);
	
	// Act
	bool result = grid.Test(LEFT);
	
	// Assert
	ASSERT_TRUE(result);
}

TEST(Grid, Test_FiveByFive_TopRightIndexPlaced_TopLeft_ReturnsFalse)
{
	// Arrange
	DefaultRuleSet ruleSet;
	Grid grid(5, 5, ruleSet);
	grid.Start(4, 0);
	
	// Act
	bool result = grid.Test(TOP_LEFT);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FiveByFive_BottomRightIndexPlaced_Top_ReturnsTrue)
{
	// Arrange
	DefaultRuleSet ruleSet;
	Grid grid(5, 5, ruleSet);
	grid.Start(4, 4);
	
	// Act
	bool result = grid.Test(TOP);
	
	// Assert
	ASSERT_TRUE(result);
}

TEST(Grid, Test_FiveByFive_BottomRightIndexPlaced_TopRight_ReturnsFalse)
{
	// Arrange
	DefaultRuleSet ruleSet;
	Grid grid(5, 5, ruleSet);
	grid.Start(4, 4);
	
	// Act
	bool result = grid.Test(TOP_RIGHT);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FiveByFive_BottomRightIndexPlaced_Right_ReturnsFalse)
{
	// Arrange
	DefaultRuleSet ruleSet;
	Grid grid(5, 5, ruleSet);
	grid.Start(4, 4);
	
	// Act
	bool result = grid.Test(RIGHT);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FiveByFive_BottomRightIndexPlaced_BottomRight_ReturnsFalse)
{
	// Arrange
	DefaultRuleSet ruleSet;
	Grid grid(5, 5, ruleSet);
	grid.Start(4, 4);
	
	// Act
	bool result = grid.Test(BOTTOM_RIGHT);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FiveByFive_BottomRightIndexPlaced_Bottom_ReturnsFalse)
{
	// Arrange
	DefaultRuleSet ruleSet;
	Grid grid(5, 5, ruleSet);
	grid.Start(4, 4);
	
	// Act
	bool result = grid.Test(BOTTOM);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FiveByFive_BottomRightIndexPlaced_BottomLeft_ReturnsFalse)
{
	// Arrange
	DefaultRuleSet ruleSet;
	Grid grid(5, 5, ruleSet);
	grid.Start(4, 4);
	
	// Act
	bool result = grid.Test(BOTTOM_LEFT);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FiveByFive_BottomRightIndexPlaced_Left_ReturnsTrue)
{
	// Arrange
	DefaultRuleSet ruleSet;
	Grid grid(5, 5, ruleSet);
	grid.Start(4, 4);
	
	// Act
	bool result = grid.Test(LEFT);
	
	// Assert
	ASSERT_TRUE(result);
}

TEST(Grid, Test_FiveByFive_BottomRightIndexPlaced_TopLeft_ReturnsTrue)
{
	// Arrange
	DefaultRuleSet ruleSet;
	Grid grid(5, 5, ruleSet);
	grid.Start(4, 4);
	
	// Act
	bool result = grid.Test(TOP_LEFT);
	
	// Assert
	ASSERT_TRUE(result);
}

TEST(Grid, Test_FiveByFive_BottomLeftIndexPlaced_Top_ReturnsTrue)
{
	// Arrange
	DefaultRuleSet ruleSet;
	Grid grid(5, 5, ruleSet);
	grid.Start(0, 4);
	
	// Act
	bool result = grid.Test(TOP);
	
	// Assert
	ASSERT_TRUE(result);
}

TEST(Grid, Test_FiveByFive_BottomLeftIndexPlaced_TopRight_ReturnsTrue)
{
	// Arrange
	DefaultRuleSet ruleSet;
	Grid grid(5, 5, ruleSet);
	grid.Start(0, 4);
	
	// Act
	bool result = grid.Test(TOP_RIGHT);
	
	// Assert
	ASSERT_TRUE(result);
}

TEST(Grid, Test_FiveByFive_BottomLeftIndexPlaced_Right_ReturnsTrue)
{
	// Arrange
	DefaultRuleSet ruleSet;
	Grid grid(5, 5, ruleSet);
	grid.Start(0, 4);
	
	// Act
	bool result = grid.Test(RIGHT);
	
	// Assert
	ASSERT_TRUE(result);
}

TEST(Grid, Test_FiveByFive_BottomLeftIndexPlaced_BottomRight_ReturnsFalse)
{
	// Arrange
	DefaultRuleSet ruleSet;
	Grid grid(5, 5, ruleSet);
	grid.Start(0, 4);
	
	// Act
	bool result = grid.Test(BOTTOM_RIGHT);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FiveByFive_BottomLeftIndexPlaced_Bottom_ReturnsFalse)
{
	// Arrange
	DefaultRuleSet ruleSet;
	Grid grid(5, 5, ruleSet);
	grid.Start(0, 4);
	
	// Act
	bool result = grid.Test(BOTTOM);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FiveByFive_BottomLeftIndexPlaced_BottomLeft_ReturnsFalse)
{
	// Arrange
	DefaultRuleSet ruleSet;
	Grid grid(5, 5, ruleSet);
	grid.Start(0, 4);
	
	// Act
	bool result = grid.Test(BOTTOM_LEFT);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FiveByFive_BottomLeftIndexPlaced_Left_ReturnsFalse)
{
	// Arrange
	DefaultRuleSet ruleSet;
	Grid grid(5, 5, ruleSet);
	grid.Start(0, 4);
	
	// Act
	bool result = grid.Test(LEFT);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FiveByFive_BottomLeftIndexPlaced_TopLeft_ReturnsFalse)
{
	// Arrange
	DefaultRuleSet ruleSet;
	Grid grid(5, 5, ruleSet);
	grid.Start(0, 4);
	
	// Act
	bool result = grid.Test(TOP_LEFT);
	
	// Assert
	ASSERT_FALSE(result);
}

//////////////////////////////////////////////////////////////////
// void Next(Direction direction);
//////////////////////////////////////////////////////////////////

TEST(Grid, Next_ThreeByThree_WalkThroughGrid_IsSolvedReturnsTrue)
{
	// Arrange
	FreeRuleSet ruleSet;
	Grid grid(3, 3, ruleSet);
	grid.Start(0, 0);
	grid.Next(RIGHT);
	grid.Next(RIGHT);
	grid.Next(BOTTOM);
	grid.Next(LEFT);
	grid.Next(LEFT);
	grid.Next(BOTTOM);
	grid.Next(RIGHT);
	grid.Next(RIGHT);
	
	// Act
	bool result = grid.IsSolved();
	
	// Assert
	ASSERT_TRUE(result);
}

//////////////////////////////////////////////////////////////////
// void Previous(); 
//////////////////////////////////////////////////////////////////

TEST(Grid, Previous_ThreeByThree_WalkThroughGrid_IsSolvedReturnsTrue)
{
	// Arrange
	FreeRuleSet ruleSet;
	Grid grid(3, 3, ruleSet);
	grid.Start(0, 0);
	grid.Next(RIGHT);
	grid.Next(RIGHT);
	grid.Previous();
	grid.Next(RIGHT);
	grid.Next(BOTTOM);
	grid.Previous();
	grid.Next(BOTTOM);
	grid.Next(LEFT);
	grid.Next(LEFT);
	grid.Next(BOTTOM);
	grid.Next(RIGHT);
	grid.Previous();
	grid.Next(RIGHT);
	grid.Next(RIGHT);
	
	// Act
	bool result = grid.IsSolved();
	
	// Assert
	ASSERT_TRUE(result);
}

//////////////////////////////////////////////////////////////////
// bool CanContinue();
//////////////////////////////////////////////////////////////////

// Only one diagonal out of four is allowed
class OneDiagonalRuleSet : public IRuleSet
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
				result = -1; // Disallow
				break;
			case RIGHT: 
				result = currentX + 1;
				break;
			case BOTTOM_RIGHT: 
				result = currentX + 1; // Allow one diagonal
				break;
			case BOTTOM: 
				result = currentX;
				break;
			case BOTTOM_LEFT: 
				result = -1; // Disallow
				break;
			case LEFT: 
				result = currentX - 1;
				break;
			case TOP_LEFT: 
				result = currentX - 1; // Allow one diagonal
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
				result = -1; // Disallow
				break;
			case RIGHT: 
				result = currentY;
				break;
			case BOTTOM_RIGHT: 
				result = currentY + 1; // Allow one diagonal
				break;
			case BOTTOM: 
				result = currentY + 1;
				break;
			case BOTTOM_LEFT: 
				result = -1; // Disallow
				break;
			case LEFT: 
				result = currentY;
				break;
			case TOP_LEFT: 
				result = currentY - 1; // Allow one diagonal
				break;
			default: break;
		}

		return result;
	};
};

TEST(Grid, CanContinue_OneDiagonalRuleSet_OneByOne_NoIndexPlaced_ReturnsTrue)
{
	// Arrange
	OneDiagonalRuleSet ruleSet;
	Grid grid(1, 1, ruleSet);
	
	// Act
	bool result = grid.CanContinue();
	
	// Assert
	ASSERT_TRUE(result);
}

TEST(Grid, CanContinue_OneDiagonalRuleSet_OneByOne_IndexPlaced_ReturnsFalse)
{
	// Arrange
	OneDiagonalRuleSet ruleSet;
	Grid grid(1, 1, ruleSet);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.CanContinue();
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, CanContinue_OneDiagonalRuleSet_TwoByTwo_CornerStuck_ReturnsFalse)
{
	// Arrange
	OneDiagonalRuleSet ruleSet;
	Grid grid(2, 2, ruleSet);
	grid.Start(0, 0);
	grid.Next(BOTTOM_RIGHT);
	grid.Next(TOP);
	
	// Act
	bool result = grid.CanContinue(); // Bottom-left/Top-right is disallowed, so there's nowhere to move
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, CanContinue_FreeRuleSet_ClosedHalf_ReturnsFalse)
{
	// Arrange
	FreeRuleSet ruleSet;
	Grid grid(3, 3, ruleSet);
	grid.Start(0, 1);
	grid.Next(RIGHT);
	grid.Next(RIGHT);
	
	// Act
	bool result = grid.CanContinue(); // Going up results in deadlock, as does going down
	
	// Assert
	ASSERT_FALSE(result);
}

//////////////////////////////////////////////////////////////////
// bool IsSolved(); 
//////////////////////////////////////////////////////////////////

TEST(Grid, IsSolved_OneByOneGrid_NoIndexPlaced_ReturnsFalse) 
{
	// Arrange
	DefaultRuleSet ruleSet;
	Grid grid(1, 1, ruleSet);
	
	// Act
	bool result = grid.IsSolved();
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, IsSolved_OneByOneGrid_IndexPlaced_ReturnsTrue) 
{
	// Arrange
	DefaultRuleSet ruleSet;
	Grid grid(1, 1, ruleSet);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.IsSolved();
	
	// Assert
	ASSERT_TRUE(result);
}

TEST(Grid, IsSolved_TwoByTwoGrid_OneIndexPlaced_ReturnsFalse)
{
	// Arrange
	DefaultRuleSet ruleSet;
	Grid grid(2, 2, ruleSet);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.IsSolved();
	
	// Assert
	ASSERT_FALSE(result);
}
