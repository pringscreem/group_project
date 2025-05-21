/**
* \author Mackenzie Kure
* \date November 2020
*/

#include<iostream>
#include<string>
#include"Item.h"
#include "gtest/gtest.h"
#include "Exceptions.h"

TEST(TestObject, interactionTest) {
  std::string str = "Painting";
  std::string str2 = "lighthouse during a storm. A ship stuggles in the waves";

  Object obj(str2, str);
  obj.interaction();
  //bad test, but what I am using for now.
}

//Checks if the set/getIsComplete functions return the proper values.
TEST(TestObject, setGetIsCompleteTest) {
  Object myItem1;

  myItem1.setIsCompleted(true);
  EXPECT_TRUE(myItem1.getIsCompleted());

  myItem1.setIsCompleted(false);
  EXPECT_FALSE(myItem1.getIsCompleted());
}

//Checks if the set/getDescription functions properly assign and return the
//description string variable.
TEST(TestObject, setGetDescriptionTest) {
  Object myItem1;
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
TEST(TestObject, setgetItemNameTest) {
  Object myItem1;
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
