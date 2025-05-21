//**************************************************************************
// CS2720A - Fall 2020 - Instructor: Dr. John Anvik
// Project Text Adventure Game
// Program Title: Room.h
// Program Purpose: Definition file for the Room Class
// that ...
//
// Written by: Mackenzie Kure
// Modified by: Cassandra Olfert
// Date: November 10, 2020
//*************************************************************************
#include <iostream>
#include <string>
#include "Room.h"
#include "Inventory.h"
#include "Item.h"
#include "Coordinate.h"
#include "playerStat.h"
#include "gtest/gtest.h"
#include "Exceptions.h"

TEST(TestNormalRoom, NormalRoomDefaultConstructorTest) {
  NormalRoom rm;
  EXPECT_EQ(rm.getCoord(), nullptr);
  EXPECT_EQ(rm.getInventory(), nullptr);
  EXPECT_EQ(rm.getStats(), nullptr);
}

TEST(TestNormalRoom, NormalRoomConstructorTest) {
  int yCoord1 = 01;
  PlayerStat* ps1 = new PlayerStat;
  NormalRoom rm1(yCoord1, ps1);
  EXPECT_EQ(rm1.getCoord()->getX(), 0);
  EXPECT_EQ(rm1.getCoord()->getY(), 1);
  EXPECT_EQ(rm1.getStats(), ps1);
  EXPECT_EQ(rm1.getInventory()->sizeOfInventory(), 3);
  EXPECT_EQ(rm1.getInventory()->getInventoryVector().at(0)->getItemName(),
            "Professor");
  EXPECT_EQ(rm1.getInventory()->getInventoryVector().at(1)->getItemName(),
            "Red Book");
  EXPECT_EQ(rm1.getInventory()->getInventoryVector().at(2)->getItemName(),
            "Puzzle: Math");
  delete ps1;

  int yCoord2 = 00;
  PlayerStat* ps2 = new PlayerStat;
  NormalRoom rm2(yCoord2, ps2);
  EXPECT_EQ(rm2.getCoord()->getX(), 0);
  EXPECT_EQ(rm2.getCoord()->getY(), 0);
  EXPECT_EQ(rm2.getStats(), ps2);
  EXPECT_EQ(rm2.getInventory()->sizeOfInventory(), 2);
  EXPECT_EQ(rm2.getInventory()->getInventoryVector().at(0)->getItemName(),
            "Old wrinkled woman");
  EXPECT_EQ(rm2.getInventory()->getInventoryVector().at(1)->getItemName(),
            "lava suit");
  delete ps2;

  int yCoord3 = 02;
  PlayerStat* ps3 = new PlayerStat;
  NormalRoom rm3(yCoord3, ps3);
  EXPECT_EQ(rm3.getCoord()->getX(), 0);
  EXPECT_EQ(rm3.getCoord()->getY(), 2);
  EXPECT_EQ(rm3.getStats(), ps3);
  EXPECT_EQ(rm3.getInventory()->sizeOfInventory(), 3);
  EXPECT_EQ(rm3.getInventory()->getInventoryVector().at(0)->getItemName(),
            "Broken screen");
  EXPECT_EQ(rm3.getInventory()->getInventoryVector().at(1)->getItemName(),
            "lava suit");
  EXPECT_EQ(rm3.getInventory()->getInventoryVector().at(2)->getItemName(),
            "Puzzle: keypanel");
  delete ps3;
}

TEST(TestNormalRoom, checkClothesTest) {
  std::string str1 = "Jeans and a T-shirt";
  std::string str2 = "normal clothes";
  std::string str3 = "Snow suit";
  std::string str4 = "winter";
  Object* obj2 = new Object(str3, str4);
  Object* obj = new Object(str1, str2);
  Inventory* inv = new Inventory;
  inv->addToInventory(obj);
  inv->addToInventory(obj2);
  Coordinate* c = new Coordinate(0, 1);
  int yCoord = 01;
  PlayerStat* stats = new PlayerStat(c, inv, 0, false);
  NormalRoom rm(yCoord, stats);
  EXPECT_TRUE(rm.checkClothes());
  rm.getStats()->setWornClothing(1);
  EXPECT_FALSE(rm.checkClothes());
  delete stats;
}
TEST(TestNormalRoom, runRoomTest) {
  //strings used for the intizlizations.
  std::string str1 = "Jeans and a T-shirt";
  std::string str2 = "normal clothes";
  std::string str3 = "snowsuit";
  std::string str4 = "snowsuit";
  Coordinate* c = new Coordinate(0, 0);
  int yCoord = 00;
  //creating the Players inventory
  Object* obj2 = new Object(str3, str4);
  Object* obj = new Object(str1, str2);
  Inventory* inv = new Inventory;
  inv->addToInventory(obj);
  inv->addToInventory(obj2);
  PlayerStat* stat = new PlayerStat(c, inv, 0, false);

  NormalRoom rm(yCoord, stat);
  //EXPECT_THROW(rm.runRoom(), invalid_input);
  //can't really test w/out running into an infinite loop
  delete stat;
}

TEST(TestNormalRoom, checkWardrobeTest) {
  Inventory* inv = new Inventory;
  Object* obj1 = new Object("Blue Jeans and t-Shirt",
  "normal clothes");
  inv->addToInventory(obj1);
  PlayerStat* stat = new PlayerStat(nullptr, inv, 0, false);
  Object* obj2 = new Object("Blue Jeans and t-Shirt",
  "normal clothes");
  NormalRoom rm(00, stat);
  EXPECT_TRUE(rm.checkWardrobe(obj2));
  Object* obj3 = new Object("snow clothes",
  "snowsuit");
  EXPECT_FALSE(rm.checkWardrobe(obj3));
  delete stat;
  delete obj2;
  delete obj3;
}

TEST(TestNoramlRoom, helpTest) {
  NormalRoom rm;
  EXPECT_TRUE(rm.help());
}

TEST(TestNormalRoom, checkDoorInputTest) {
  PlayerStat* stat = nullptr;
  NormalRoom room(00, stat);
  EXPECT_TRUE(room.checkDoorInput("EAST"));
  EXPECT_FALSE(room.checkDoorInput("NORTH"));
}

TEST(TestNormalRoom, assignCoordTest) {
  PlayerStat* ps = nullptr;
  NormalRoom rm(00, ps);
  rm.listDoors();
  delete ps;

  PlayerStat* ps1 = nullptr;
  NormalRoom rm1(01, ps1);
  rm1.listDoors();
  delete ps1;

  PlayerStat* ps2 = nullptr;
  NormalRoom rm2(02, ps2);
  rm2.listDoors();
  delete ps2;
}

///////////////////////////////////////////////////////////////////////////////
TEST(TestHotRoom, HotRoomDefaultConstructorTest) {
  HotRoom rm;
  EXPECT_EQ(rm.getCoord(), nullptr);
  EXPECT_EQ(rm.getInventory(), nullptr);
  EXPECT_EQ(rm.getStats(), nullptr);
}

TEST(TestHotRoom, HotRoomConstructorTest) {
  int yCoord1 = 10;
  PlayerStat* ps1 = new PlayerStat;
  HotRoom rm1(yCoord1, ps1);
  EXPECT_EQ(rm1.getCoord()->getX(), 1);
  EXPECT_EQ(rm1.getCoord()->getY(), 0);
  EXPECT_EQ(rm1.getStats(), ps1);
  EXPECT_EQ(rm1.getInventory()->sizeOfInventory(), 2);
  EXPECT_EQ(rm1.getInventory()->getInventoryVector().at(0)->getItemName(),
            "Man appearing from the 17th century");
  EXPECT_EQ(rm1.getInventory()->getInventoryVector().at(1)->getItemName(),
            "snowsuit");
  delete ps1;

  int yCoord2 = 11;
  PlayerStat* ps2 = new PlayerStat;
  HotRoom rm2(yCoord2, ps2);
  EXPECT_EQ(rm2.getCoord()->getX(), 1);
  EXPECT_EQ(rm2.getCoord()->getY(), 1);
  EXPECT_EQ(rm2.getStats(), ps2);
  EXPECT_EQ(rm2.getInventory()->sizeOfInventory(), 3);
  EXPECT_EQ(rm2.getInventory()->getInventoryVector().at(0)->getItemName(),
            "Librarian");
  EXPECT_EQ(rm2.getInventory()->getInventoryVector().at(1)->getItemName(),
            "snowsuit");
  EXPECT_EQ(rm2.getInventory()->getInventoryVector().at(2)->getItemName(),
            "Puzzle: combination lock");
  delete ps2;

  int yCoord3 = 12;
  PlayerStat* ps3 = new PlayerStat;
  HotRoom rm3(yCoord3, ps3);
  EXPECT_EQ(rm3.getCoord()->getX(), 1);
  EXPECT_EQ(rm3.getCoord()->getY(), 2);
  EXPECT_EQ(rm3.getStats(), ps3);
  EXPECT_EQ(rm3.getInventory()->sizeOfInventory(), 2);
  EXPECT_EQ(rm3.getInventory()->getInventoryVector().at(0)->getItemName(),
            "little girl");
  EXPECT_EQ(rm3.getInventory()->getInventoryVector().at(1)->getItemName(),
            "Puzzle: tictactoe");
  delete ps3;
}

TEST(TestHotRoom, checkClothesTest) {
  std::string str1 = "Jeans and a T-shirt";
  std::string str2 = "lava suit";
  std::string str3 = "Snow suit";
  std::string str4 = "winter";
  Object* obj2 = new Object(str3, str4);
  Object* obj = new Object(str1, str2);
  Inventory* inv = new Inventory;
  inv->addToInventory(obj2);
  inv->addToInventory(obj);
  Coordinate* c = new Coordinate(1, 1);
  int yCoord = 11;
  PlayerStat* stats = new PlayerStat(c, inv, 1, false);
  HotRoom rm(yCoord, stats);
  EXPECT_TRUE(rm.checkClothes());
  rm.getStats()->setWornClothing(0);
  EXPECT_FALSE(rm.checkClothes());
  delete stats;
}

TEST(TestHotRoom, assignCoordTest) {
  PlayerStat* ps = nullptr;
  HotRoom rm(10, ps);
  rm.listDoors();
  delete ps;
}

///////////////////////////////////////////////////////////////////////////////
TEST(TestColdRoom, ColdRoomDefaultConstructorTest) {
  ColdRoom rm;
  EXPECT_EQ(rm.getCoord(), nullptr);
  EXPECT_EQ(rm.getInventory(), nullptr);
  EXPECT_EQ(rm.getStats(), nullptr);
}

TEST(TestColdRoom, ColdRoomConstructorTest) {
  int yCoord1 = 20;
  PlayerStat* ps1 = new PlayerStat;
  ColdRoom rm1(yCoord1, ps1);
  EXPECT_EQ(rm1.getCoord()->getX(), 2);
  EXPECT_EQ(rm1.getCoord()->getY(), 0);
  EXPECT_EQ(rm1.getStats(), ps1);
  EXPECT_EQ(rm1.getInventory()->sizeOfInventory(), 3);
  EXPECT_EQ(rm1.getInventory()->getInventoryVector().at(0)->getItemName(),
            "Cat");
  EXPECT_EQ(rm1.getInventory()->getInventoryVector().at(1)->getItemName(),
            "Painting");
  EXPECT_EQ(rm1.getInventory()->getInventoryVector().at(2)->getItemName(),
            "Puzzle: tictactoe");
  delete ps1;

  int yCoord2 = 21;
  PlayerStat* ps2 = new PlayerStat;
  ColdRoom rm2(yCoord2, ps2);
  EXPECT_EQ(rm2.getCoord()->getX(), 2);
  EXPECT_EQ(rm2.getCoord()->getY(), 1);
  EXPECT_EQ(rm2.getStats(), ps2);
  EXPECT_EQ(rm2.getInventory()->sizeOfInventory(), 1);
  EXPECT_EQ(rm2.getInventory()->getInventoryVector().at(0)->getItemName(),
            "A homeless looking man");
  delete ps2;

  int yCoord3 = 22;
  PlayerStat* ps3 = new PlayerStat;
  ColdRoom rm3(yCoord3, ps3);
  EXPECT_EQ(rm3.getCoord()->getX(), 2);
  EXPECT_EQ(rm3.getCoord()->getY(), 2);
  EXPECT_EQ(rm3.getStats(), ps3);
  EXPECT_EQ(rm3.getInventory()->sizeOfInventory(), 2);
  EXPECT_EQ(rm3.getInventory()->getInventoryVector().at(0)->getItemName(),
            "Nondescript looking man");
  EXPECT_EQ(rm3.getInventory()->getInventoryVector().at(1)->getItemName(),
            "Puzzle: Equation");
  delete ps3;
}

TEST(TestColdRoom, checkClothesTest) {
  std::string str1 = "Jeans and a T-shirt";
  std::string str2 = "lava suit";
  std::string str3 = "Snow suit";
  std::string str4 = "snowsuit";
  Object* obj2 = new Object(str3, str4);
  Object* obj = new Object(str1, str2);
  Inventory* inv = new Inventory;
  inv->addToInventory(obj);
  inv->addToInventory(obj2);
  Coordinate* c = new Coordinate(2, 2);
  int yCoord = 22;
  PlayerStat* stats = new PlayerStat(c, inv, 1, false);
  ColdRoom rm(yCoord, stats);
  EXPECT_TRUE(rm.checkClothes());
  rm.getStats()->setWornClothing(0);
  EXPECT_FALSE(rm.checkClothes());
  delete stats;
}

TEST(TestColdRoom, assignCoordTest) {
  PlayerStat* ps = nullptr;
  ColdRoom rm(20, ps);
  rm.listDoors();
  delete ps;

  PlayerStat* ps1 = nullptr;
  ColdRoom rm1(21, ps1);
  rm1.listDoors();
  delete ps1;

  PlayerStat* ps2 = nullptr;
  ColdRoom rm2(22, ps2);
  rm2.listDoors();
  delete ps2;
}

TEST(TestColdRoom, runInteractionTest) {
  PlayerStat* stats = nullptr;
  ColdRoom rm(21, stats);
  auto it = rm.getInventory()->getInventoryVector().at(0);
  std::cout << it->getItemName() << std::endl;
  std::cout << "before runInteraction" << std::endl;
  rm.runInteraction(it);
  EXPECT_EQ(it->getIsCompleted(), false);
}
