/**
* \author Mackenzie Kure
* \date November 2020
*/

#include <iostream>
#include <vector>
#include "Item.h"
#include "Inventory.h"
#include "gtest/gtest.h"
#include "Exceptions.h"

TEST(TestInventory, addToInventoryTest) {
  Inventory inv;
  NPC* myItem1 = new NPC;
  Object* myItem2 = new Object;
  inv.addToInventory(myItem1);
  EXPECT_EQ(inv.sizeOfInventory(), 1);
  inv.addToInventory(myItem2);
  EXPECT_EQ(inv.sizeOfInventory(), 2);
}

TEST(TestInventory, sizeOfInventoryTest) {
  Inventory inv;
  NPC* myItem1 = new NPC;
  Object* myItem2 = new Object;
  inv.addToInventory(myItem1);
  EXPECT_EQ(inv.sizeOfInventory(), 1);
  inv.addToInventory(myItem2);
  EXPECT_EQ(inv.sizeOfInventory(), 2);
}

TEST(TestInventory, listInventoryTest) {
  Inventory inv;
  NPC* myItem1 = new NPC;
  Object* myItem2 = new Object;
  myItem1->setItemName("Old Man");
  myItem2->setItemName("hammer");
  inv.addToInventory(myItem1);
  inv.addToInventory(myItem2);
  EXPECT_EQ(inv.sizeOfInventory(), 2);
  inv.listInventory();
}
