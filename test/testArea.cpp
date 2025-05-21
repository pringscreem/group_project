/**
* \author Jordon Harris, Mackenzie Kure, Scott Sonnleitner
* \date October 28, November 9, 2020
*/
#include <iostream>
#include <vector>
#include "Area.h"
#include "Room.h"
#include "Coordinate.h"
#include "Inventory.h"
#include "gtest/gtest.h"
#include "Exceptions.h"

//*****************************************************************************
//                                AREA1
//*****************************************************************************
TEST(TestArea1, ConstructorTest) {
  PlayerStat* ps = nullptr;
  Area1 a1(ps);
  EXPECT_EQ(a1.getRoomVector().at(0)->getInventory()->sizeOfInventory(), 2);
  EXPECT_EQ(a1.getRoomVector().at(1)->getInventory()->sizeOfInventory(), 2);
  EXPECT_EQ(a1.getRoomVector().at(2)->getInventory()->sizeOfInventory(), 3);
}

//*****************************************************************************
//                                AREA2
//*****************************************************************************
TEST(TestArea2, ConstructorTest) {
  PlayerStat* ps = nullptr;
  Area2 a2(ps);
  EXPECT_EQ(a2.getRoomVector().at(0)->getInventory()->sizeOfInventory(), 3);
  EXPECT_EQ(a2.getRoomVector().at(1)->getInventory()->sizeOfInventory(), 3);
  EXPECT_EQ(a2.getRoomVector().at(2)->getInventory()->sizeOfInventory(), 1);
}

//*****************************************************************************
//                                AREA3
//*****************************************************************************
TEST(TestArea3, ConstructorTest) {
  PlayerStat* ps = nullptr;
  Area3 a3(ps);
  EXPECT_EQ(a3.getRoomVector().at(0)->getInventory()->sizeOfInventory(), 3);
  EXPECT_EQ(a3.getRoomVector().at(1)->getInventory()->sizeOfInventory(), 2);
  EXPECT_EQ(a3.getRoomVector().at(2)->getInventory()->sizeOfInventory(), 2);
}
