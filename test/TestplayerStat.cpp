/**
* \author Mackenzie Kure
* \date October 28, November 13, 2020
*/

#include<iostream>
#include<string>
#include"playerStat.h"
#include"Coordinate.h"
#include"Inventory.h"
#include"Item.h"
#include"gtest/gtest.h"
#include"Exceptions.h"

TEST(TestplayerStat, defaultConstructorTest) {
  PlayerStat stats;
  EXPECT_EQ(stats.getLocation(), nullptr);
  EXPECT_EQ(stats.getWornClothing(), 0);
  EXPECT_EQ(stats.getIsDead(), false);
}

TEST(TestplayerStat, ConstructorTest) {
  Coordinate* c = new Coordinate(0, 1);
  Inventory* inv = new Inventory;
  PlayerStat stats(c, inv, 2, true);
  EXPECT_EQ(stats.getLocation(), c);
  EXPECT_EQ(stats.getWornClothing(), 2);
  EXPECT_EQ(stats.getIsDead(), true);
}

TEST(TestplayerStat, setWornClothingTest) {
  PlayerStat stats;
  stats.setWornClothing(3);
  EXPECT_GT(stats.getWornClothing(), 2);
  EXPECT_LT(stats.getWornClothing(), 4);
}

TEST(TestplayerStat, setIsDeadTest) {
  PlayerStat stats;
  stats.setIsDead(true);
  EXPECT_EQ(stats.getIsDead(), true);
}

TEST(TestplayerStat, setLocationTest) {
  PlayerStat stats;
  Coordinate* c = new Coordinate(2, 2);
  stats.setLocation(c);
  EXPECT_EQ(stats.getLocation(), c);
}

TEST(TestplayerStat, incrementSolvedPuzzleCountTest) {
  PlayerStat ps;
  ps.incrementSolvedPuzzleCount();
  EXPECT_EQ(ps.getSolvedPuzzleCount(), 1);
}
