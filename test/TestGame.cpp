/**
* \author Cassandra Olfert
* \date November 1, 2020
*/

#include <iostream>
#include <string>
#include <vector>
#include "Area.h"
#include "Coordinate.h"
#include "Game.h"
#include "Inventory.h"
#include "Room.h"
#include "gtest/gtest.h"
#include "Exceptions.h"

TEST(TestGame, GameConstructorTest) {
  Game* game = nullptr;
  EXPECT_TRUE(game == nullptr);
}
