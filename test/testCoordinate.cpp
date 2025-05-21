/**
* \author Mackenzie Kure
* \date November 11, 2020
*/

#include <iostream>
#include "Exceptions.h"
#include "Coordinate.h"
#include "gtest/gtest.h"

//setCoordinate is tested implicitly in testGetX and testGetY because it is
//called in both of those tests.
//Checks if the x coordinate entered is returned properly by the getX()
//function.
TEST(TestCoordinate, getXTest) {
  Coordinate myCoordinate1;
  myCoordinate1.setCoordinate(1, 1);
  EXPECT_EQ(myCoordinate1.getX(), 1);
  EXPECT_THROW(myCoordinate1.setCoordinate(3, 1), x_is_out_of_range_error);
  EXPECT_THROW(myCoordinate1.setCoordinate(1, 3), y_is_out_of_range_error);
  EXPECT_THROW(myCoordinate1.setCoordinate(-1, 1), x_is_out_of_range_error);
  EXPECT_THROW(myCoordinate1.setCoordinate(1, -1), y_is_out_of_range_error);
}

//Checks if the y coordinate entered is returned properly by the getX()
//function.
TEST(TestCoordinate, getYTest) {
  Coordinate myCoordinate1;
  myCoordinate1.setCoordinate(1, 1);
  EXPECT_EQ(myCoordinate1.getY(), 1);

  EXPECT_THROW(myCoordinate1.setCoordinate(3, 1), x_is_out_of_range_error);
  EXPECT_THROW(myCoordinate1.setCoordinate(1, 3), y_is_out_of_range_error);
  EXPECT_THROW(myCoordinate1.setCoordinate(-1, 1), x_is_out_of_range_error);
  EXPECT_THROW(myCoordinate1.setCoordinate(1, -1), y_is_out_of_range_error);
  EXPECT_NO_THROW(myCoordinate1.setCoordinate(2, 1));
}

//Checks if the pointer returned by getCoordinate() holds the same address as
//the "this" Coordinate calling it.
TEST(TestCoordinate, getCoordinateTest) {
  Coordinate myCoordinate1;
  myCoordinate1.setCoordinate(1, 1);

  Coordinate* coordinatePtr1 = &myCoordinate1;

  EXPECT_EQ(myCoordinate1.getCoordinate(), coordinatePtr1);
}
