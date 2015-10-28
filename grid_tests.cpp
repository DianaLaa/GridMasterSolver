#include "gtest/gtest.h"
#include "grid.h"

//////////////////////////////////////////////////////////////////
// void Start(unsigned int x, unsigned int y);
//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
// bool Test(Direction direction);
//////////////////////////////////////////////////////////////////

TEST(Grid, Test_ThreeByThree_NoIndexPlaced_ReturnsFalse) 
{
	// Arrange
	Grid grid(3, 3);
	
	// Act
	bool result = grid.Test(TOP);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_ThreeByThree_TopLeftIndexPlaced_Top_ReturnsFalse) 
{
	// Arrange
	Grid grid(3, 3);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.Test(TOP);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_ThreeByThree_TopLeftIndexPlaced_TopRight_ReturnsFalse) 
{
	// Arrange
	Grid grid(3, 3);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.Test(TOP_RIGHT);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_ThreeByThree_TopLeftIndexPlaced_Right_ReturnsFalse)
{
	// Arrange
	Grid grid(3, 3);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.Test(RIGHT);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_ThreeByThree_TopLeftIndexPlaced_BottomRight_ReturnsTrue)
{
	// Arrange
	Grid grid(3, 3);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.Test(BOTTOM_RIGHT);
	
	// Assert
	ASSERT_TRUE(result);
}

TEST(Grid, Test_ThreeByThree_TopLeftIndexPlaced_Bottom_ReturnsFalse)
{
	// Arrange
	Grid grid(3, 3);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.Test(BOTTOM);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_ThreeByThree_TopLeftIndexPlaced_BottomLeft_ReturnsFalse) 
{
	// Arrange
	Grid grid(3, 3);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.Test(BOTTOM_LEFT);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_ThreeByThree_TopLeftIndexPlaced_Left_ReturnsFalse) 
{
	// Arrange
	Grid grid(3, 3);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.Test(LEFT);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_ThreeByThree_TopLeftIndexPlaced_TopLeft_ReturnsFalse) 
{
	// Arrange
	Grid grid(3, 3);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.Test(TOP_LEFT);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FourByFour_NoIndexPlaced_ReturnsFalse) 
{
	// Arrange
	Grid grid(4, 4);
	
	// Act
	bool result = grid.Test(TOP);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FourByFour_TopLeftIndexPlaced_Top_ReturnsFalse) 
{
	// Arrange
	Grid grid(4, 4);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.Test(TOP);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FourByFour_TopLeftIndexPlaced_TopRight_ReturnsFalse) 
{
	// Arrange
	Grid grid(4, 4);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.Test(TOP_RIGHT);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FourByFour_TopLeftIndexPlaced_Right_ReturnsTrue)
{
	// Arrange
	Grid grid(4, 4);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.Test(RIGHT);
	
	// Assert
	ASSERT_TRUE(result);
}

TEST(Grid, Test_FourByFour_TopLeftIndexPlaced_BottomRight_ReturnsTrue)
{
	// Arrange
	Grid grid(4, 4);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.Test(BOTTOM_RIGHT);
	
	// Assert
	ASSERT_TRUE(result);
}

TEST(Grid, Test_FourByFour_TopLeftIndexPlaced_Bottom_ReturnsTrue)
{
	// Arrange
	Grid grid(4, 4);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.Test(BOTTOM);
	
	// Assert
	ASSERT_TRUE(result);
}

TEST(Grid, Test_FourByFour_TopLeftIndexPlaced_BottomLeft_ReturnsFalse) 
{
	// Arrange
	Grid grid(4, 4);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.Test(BOTTOM_LEFT);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FourByFour_TopLeftIndexPlaced_Left_ReturnsFalse) 
{
	// Arrange
	Grid grid(4, 4);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.Test(LEFT);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FourByFour_TopLeftIndexPlaced_TopLeft_ReturnsFalse) 
{
	// Arrange
	Grid grid(4, 4);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.Test(TOP_LEFT);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FiveByFive_TopLeftIndexPlaced_Top_ReturnsFalse)
{
	// Arrange
	Grid grid(5, 5);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.Test(TOP);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FiveByFive_TopLeftIndexPlaced_TopRight_ReturnsFalse)
{
	// Arrange
	Grid grid(5, 5);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.Test(TOP_RIGHT);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FiveByFive_TopLeftIndexPlaced_Right_ReturnsTrue)
{
	// Arrange
	Grid grid(5, 5);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.Test(RIGHT);
	
	// Assert
	ASSERT_TRUE(result);
}

TEST(Grid, Test_FiveByFive_TopLeftIndexPlaced_BottomRight_ReturnsTrue)
{
	// Arrange
	Grid grid(5, 5);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.Test(BOTTOM_RIGHT);
	
	// Assert
	ASSERT_TRUE(result);
}

TEST(Grid, Test_FiveByFive_TopLeftIndexPlaced_Bottom_ReturnsTrue)
{
	// Arrange
	Grid grid(5, 5);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.Test(BOTTOM);
	
	// Assert
	ASSERT_TRUE(result);
}

TEST(Grid, Test_FiveByFive_TopLeftIndexPlaced_BottomLeft_ReturnsFalse)
{
	// Arrange
	Grid grid(5, 5);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.Test(BOTTOM_LEFT);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FiveByFive_TopLeftIndexPlaced_Left_ReturnsFalse)
{
	// Arrange
	Grid grid(5, 5);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.Test(LEFT);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FiveByFive_TopLeftIndexPlaced_TopLeft_ReturnsFalse)
{
	// Arrange
	Grid grid(5, 5);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.Test(TOP_LEFT);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FiveByFive_TopRightIndexPlaced_Top_ReturnsFalse)
{
	// Arrange
	Grid grid(5, 5);
	grid.Start(4, 0);
	
	// Act
	bool result = grid.Test(TOP);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FiveByFive_TopRightIndexPlaced_TopRight_ReturnsFalse)
{
	// Arrange
	Grid grid(5, 5);
	grid.Start(4, 0);
	
	// Act
	bool result = grid.Test(TOP_RIGHT);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FiveByFive_TopRightIndexPlaced_Right_ReturnsFalse)
{
	// Arrange
	Grid grid(5, 5);
	grid.Start(4, 0);
	
	// Act
	bool result = grid.Test(RIGHT);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FiveByFive_TopRightIndexPlaced_BottomRight_ReturnsFalse)
{
	// Arrange
	Grid grid(5, 5);
	grid.Start(4, 0);
	
	// Act
	bool result = grid.Test(BOTTOM_RIGHT);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FiveByFive_TopRightIndexPlaced_Bottom_ReturnsTrue)
{
	// Arrange
	Grid grid(5, 5);
	grid.Start(4, 0);
	
	// Act
	bool result = grid.Test(BOTTOM);
	
	// Assert
	ASSERT_TRUE(result);
}

TEST(Grid, Test_FiveByFive_TopRightIndexPlaced_BottomLeft_ReturnsTrue)
{
	// Arrange
	Grid grid(5, 5);
	grid.Start(4, 0);
	
	// Act
	bool result = grid.Test(BOTTOM_LEFT);
	
	// Assert
	ASSERT_TRUE(result);
}

TEST(Grid, Test_FiveByFive_TopRightIndexPlaced_Left_ReturnsTrue)
{
	// Arrange
	Grid grid(5, 5);
	grid.Start(4, 0);
	
	// Act
	bool result = grid.Test(LEFT);
	
	// Assert
	ASSERT_TRUE(result);
}

TEST(Grid, Test_FiveByFive_TopRightIndexPlaced_TopLeft_ReturnsFalse)
{
	// Arrange
	Grid grid(5, 5);
	grid.Start(4, 0);
	
	// Act
	bool result = grid.Test(TOP_LEFT);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FiveByFive_BottomRightIndexPlaced_Top_ReturnsTrue)
{
	// Arrange
	Grid grid(5, 5);
	grid.Start(4, 4);
	
	// Act
	bool result = grid.Test(TOP);
	
	// Assert
	ASSERT_TRUE(result);
}

TEST(Grid, Test_FiveByFive_BottomRightIndexPlaced_TopRight_ReturnsFalse)
{
	// Arrange
	Grid grid(5, 5);
	grid.Start(4, 4);
	
	// Act
	bool result = grid.Test(TOP_RIGHT);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FiveByFive_BottomRightIndexPlaced_Right_ReturnsFalse)
{
	// Arrange
	Grid grid(5, 5);
	grid.Start(4, 4);
	
	// Act
	bool result = grid.Test(RIGHT);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FiveByFive_BottomRightIndexPlaced_BottomRight_ReturnsFalse)
{
	// Arrange
	Grid grid(5, 5);
	grid.Start(4, 4);
	
	// Act
	bool result = grid.Test(BOTTOM_RIGHT);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FiveByFive_BottomRightIndexPlaced_Bottom_ReturnsFalse)
{
	// Arrange
	Grid grid(5, 5);
	grid.Start(4, 4);
	
	// Act
	bool result = grid.Test(BOTTOM);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FiveByFive_BottomRightIndexPlaced_BottomLeft_ReturnsFalse)
{
	// Arrange
	Grid grid(5, 5);
	grid.Start(4, 4);
	
	// Act
	bool result = grid.Test(BOTTOM_LEFT);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FiveByFive_BottomRightIndexPlaced_Left_ReturnsTrue)
{
	// Arrange
	Grid grid(5, 5);
	grid.Start(4, 4);
	
	// Act
	bool result = grid.Test(LEFT);
	
	// Assert
	ASSERT_TRUE(result);
}

TEST(Grid, Test_FiveByFive_BottomRightIndexPlaced_TopLeft_ReturnsTrue)
{
	// Arrange
	Grid grid(5, 5);
	grid.Start(4, 4);
	
	// Act
	bool result = grid.Test(TOP_LEFT);
	
	// Assert
	ASSERT_TRUE(result);
}

TEST(Grid, Test_FiveByFive_BottomLeftIndexPlaced_Top_ReturnsTrue)
{
	// Arrange
	Grid grid(5, 5);
	grid.Start(0, 4);
	
	// Act
	bool result = grid.Test(TOP);
	
	// Assert
	ASSERT_TRUE(result);
}

TEST(Grid, Test_FiveByFive_BottomLeftIndexPlaced_TopRight_ReturnsTrue)
{
	// Arrange
	Grid grid(5, 5);
	grid.Start(0, 4);
	
	// Act
	bool result = grid.Test(TOP_RIGHT);
	
	// Assert
	ASSERT_TRUE(result);
}

TEST(Grid, Test_FiveByFive_BottomLeftIndexPlaced_Right_ReturnsTrue)
{
	// Arrange
	Grid grid(5, 5);
	grid.Start(0, 4);
	
	// Act
	bool result = grid.Test(RIGHT);
	
	// Assert
	ASSERT_TRUE(result);
}

TEST(Grid, Test_FiveByFive_BottomLeftIndexPlaced_BottomRight_ReturnsFalse)
{
	// Arrange
	Grid grid(5, 5);
	grid.Start(0, 4);
	
	// Act
	bool result = grid.Test(BOTTOM_RIGHT);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FiveByFive_BottomLeftIndexPlaced_Bottom_ReturnsFalse)
{
	// Arrange
	Grid grid(5, 5);
	grid.Start(0, 4);
	
	// Act
	bool result = grid.Test(BOTTOM);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FiveByFive_BottomLeftIndexPlaced_BottomLeft_ReturnsFalse)
{
	// Arrange
	Grid grid(5, 5);
	grid.Start(0, 4);
	
	// Act
	bool result = grid.Test(BOTTOM_LEFT);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FiveByFive_BottomLeftIndexPlaced_Left_ReturnsFalse)
{
	// Arrange
	Grid grid(5, 5);
	grid.Start(0, 4);
	
	// Act
	bool result = grid.Test(LEFT);
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, Test_FiveByFive_BottomLeftIndexPlaced_TopLeft_ReturnsFalse)
{
	// Arrange
	Grid grid(5, 5);
	grid.Start(0, 4);
	
	// Act
	bool result = grid.Test(TOP_LEFT);
	
	// Assert
	ASSERT_FALSE(result);
}

//////////////////////////////////////////////////////////////////
// void Next(Direction direction);
//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
// void Previous(); 
//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
// bool Validate();
//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
// bool IsSolved(); 
//////////////////////////////////////////////////////////////////

TEST(Grid, IsSolved_OneByOneGrid_NoIndexPlaced_ReturnsFalse) 
{
	// Arrange
	Grid grid(1, 1);
	
	// Act
	bool result = grid.IsSolved();
	
	// Assert
	ASSERT_FALSE(result);
}

TEST(Grid, IsSolved_OneByOneGrid_IndexPlaced_ReturnsTrue) 
{
	// Arrange
	Grid grid(1, 1);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.IsSolved();
	
	// Assert
	ASSERT_TRUE(result);
}

TEST(Grid, IsSolved_TwoByTwoGrid_OneIndexPlaced_ReturnsFalse)
{
	// Arrange
	Grid grid(2, 2);
	grid.Start(0, 0);
	
	// Act
	bool result = grid.IsSolved();
	
	// Assert
	ASSERT_FALSE(result);
}