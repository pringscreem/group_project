/**
* \author Mackenzie Kure
* \date November 2020
*/

#include<iostream>
#include<string>
#include"Item.h"
#include "gtest/gtest.h"
#include "Exceptions.h"

TEST(TestNPC, defaultConstructorTest) {
  NPC npc;
  EXPECT_EQ(npc.getDescription(), "");
  EXPECT_EQ(npc.getItemName(), "");
  EXPECT_EQ(npc.getIsCompleted(), false);
  EXPECT_EQ(npc.getMessage(), "");
}
TEST(TestNPC, ConstructorTest) {
  NPC npc("Wrinkly and weathered", "Old Man", "Photo's reveal secrets...");
  EXPECT_EQ(npc.getDescription(), "Wrinkly and weathered");
  EXPECT_EQ(npc.getItemName(), "Old Man");
  EXPECT_EQ(npc.getIsCompleted(), false);
  EXPECT_EQ(npc.getMessage(), "Photo's reveal secrets...");
}
TEST(TestNPC, interactionTest) {
  std::string s = "Watch you step, wouldn't want to fall into any pits...";
  NPC npc("Adorable", "little girl", s);
  npc.interaction();
  EXPECT_EQ(npc.getMessage(), s);
  EXPECT_EQ(npc.getIsCompleted(), false);
}
//Checks if the set/getIsComplete functions return the proper values.
TEST(TestNPC, setGetIsCompleteTest) {
  NPC myItem1;

  myItem1.setIsCompleted(true);
  EXPECT_TRUE(myItem1.getIsCompleted());

  myItem1.setIsCompleted(false);
  EXPECT_FALSE(myItem1.getIsCompleted());
}

//Checks if the set/getDescription functions properly assign and return the
//description string variable.
TEST(TestNPC, setGetDescriptionTest) {
  NPC myItem1;
  std::string myString1 = "";

  myItem1.setDescription(myString1);
  EXPECT_EQ(myItem1.getDescription(), "");

  myString1 = "asdf";
  myItem1.setDescription(myString1);
  EXPECT_EQ(myItem1.getDescription(), "asdf");

  myString1 = "Words with space and capital letters as well as punctuation.\n";
  myItem1.setDescription(myString1);
  EXPECT_EQ(myItem1.getDescription(),
  "Words with space and capital letters as well as punctuation.\n");
}

//Checks if the set/getItemName functions properly assign and return the
//Name string variable.
TEST(TestNPC, setgetItemNameTest) {
  NPC myItem1;
  std::string myString1 = "";

  myItem1.setItemName(myString1);
  EXPECT_EQ(myItem1.getItemName(), "");

  myString1 = "asdf";
  myItem1.setItemName(myString1);
  EXPECT_EQ(myItem1.getItemName(), "asdf");

  myString1 = "Long Capitalized Name.";
  myItem1.setItemName(myString1);
  EXPECT_EQ(myItem1.getItemName(), "Long Capitalized Name.");
}

//Checks if the set/getMessage functions properly assign and return the
//message string variable.
TEST(TestNPC, setGetMessageTest) {
  NPC myItem1;
  std::string myString1 = "";

  myItem1.setMessage(myString1);
  EXPECT_EQ(myItem1.getMessage(), "");

  myString1 = "asdf";
  myItem1.setMessage(myString1);
  EXPECT_EQ(myItem1.getMessage(), "asdf");

  myString1 = "Words with space and capital letters as well as punctuation.\n";
  myItem1.setMessage(myString1);
  EXPECT_EQ(myItem1.getMessage(),
  "Words with space and capital letters as well as punctuation.\n");
}
