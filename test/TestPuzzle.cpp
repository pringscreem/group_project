/**
* \author Cassandra Olfert, Mackenzie Kure, Scott Sonnleitner
* \date October 30, November 9, November 13, 2020
*/

  #include <iostream>
  #include "Item.h"
  #include "gtest/gtest.h"
  #include "Exceptions.h"

  TEST(TestPuzzleA, PuzzleADefaultConstructorTest) {
    PuzzleA a;
    EXPECT_EQ(a.getDescription(), "");
    EXPECT_EQ(a.getItemName(), "");
    EXPECT_EQ(a.getIsCompleted(), false);
  }

  TEST(TestPuzzleA, PuzzleAConstructorTest) {
    PuzzleA a("Binary", "Binary Puzzle");
    EXPECT_EQ(a.getDescription(), "Binary");
    EXPECT_EQ(a.getItemName(), "Binary Puzzle");
    EXPECT_EQ(a.getIsCompleted(), false);
  }

  TEST(TestPuzzleA, PuzzleAGetIsCompletedTest) {
    PuzzleA a;
    //  not set, expect false
    EXPECT_FALSE(a.getIsCompleted());
    // set, should be true now
    a.setIsCompleted(true);
    EXPECT_TRUE(a.getIsCompleted());
  }

    TEST(TestPuzzleA, PuzzleAInteractionTest)  {
      PuzzleA a;
      a.interaction();
    }

  TEST(TestPuzzleA, PuzzleASetIsCompletedTest) {
    PuzzleA a;

    a.setIsCompleted(true);
    EXPECT_TRUE(a.getIsCompleted() == true);
    EXPECT_FALSE(a.getIsCompleted() == false);
    a.setIsCompleted(false);
    EXPECT_EQ(a.getIsCompleted(), false);
  }

  TEST(TestPuzzleB, PuzzleBDefaultConstructorTest) {
    PuzzleB b;
    EXPECT_EQ(b.getDescription(), "");
    EXPECT_EQ(b.getItemName(), "");
    EXPECT_EQ(b.getIsCompleted(), false);
  }

  TEST(TestPuzzleB, PuzzleBConstructorTest) {
    PuzzleB b("Binary", "Binary Puzzle");
    EXPECT_EQ(b.getDescription(), "Binary");
    EXPECT_EQ(b.getItemName(), "Binary Puzzle");
    EXPECT_EQ(b.getIsCompleted(), false);
  }

  TEST(TestPuzzleB, PuzzleBSetIsCompletedTest) {
    PuzzleB b;
    b.setIsCompleted(true);
    EXPECT_TRUE(b.getIsCompleted() == true);
    EXPECT_FALSE(b.getIsCompleted() == false);
    b.setIsCompleted(false);
    EXPECT_EQ(b.getIsCompleted(), false);
  }

//This tests whether checkAnswer and setupBoard are behaving correctly.
  TEST(TestPuzzleB, PuzzleBCheckAnswerSetupBoardTest) {
    PuzzleB myPuzzleB("TicTacToe", "TicTacToe Puzzle");
    int chosenQuestionNumber = 0;

    myPuzzleB.setupBoard(1);
    myPuzzleB.printBoard();
    EXPECT_TRUE(myPuzzleB.checkAnswer(3, 3));
    EXPECT_FALSE(myPuzzleB.checkAnswer(2, 2));

    chosenQuestionNumber = myPuzzleB.chooseQuestionNumber();
    myPuzzleB.setupBoard(chosenQuestionNumber);
    if (chosenQuestionNumber == 1) {
      EXPECT_TRUE(myPuzzleB.checkAnswer(3, 3));
      EXPECT_FALSE(myPuzzleB.checkAnswer(2, 2));
    }
    if (chosenQuestionNumber == 2) {
      EXPECT_TRUE(myPuzzleB.checkAnswer(1, 1));
      EXPECT_FALSE(myPuzzleB.checkAnswer(2, 2));
    }
    if (chosenQuestionNumber == 3) {
      EXPECT_TRUE(myPuzzleB.checkAnswer(3, 2));
      EXPECT_FALSE(myPuzzleB.checkAnswer(1, 1));
    }
  }

  TEST(TestPuzzleC, PuzzleCConstructorTest) {
    PuzzleC c("Binary", "Binary Puzzle");
    EXPECT_EQ(c.getDescription(), "Binary");
    EXPECT_EQ(c.getItemName(), "Binary Puzzle");
    EXPECT_EQ(c.getIsCompleted(), false);
  }

  TEST(TestPuzzleC, PuzzleCSetIsCompletedTest) {
    PuzzleC c;
    c.setIsCompleted(true);
    EXPECT_TRUE(c.getIsCompleted() == true);
    EXPECT_FALSE(c.getIsCompleted() == false);
    c.setIsCompleted(false);
    EXPECT_EQ(c.getIsCompleted(), false);
  }

TEST(TestPuzzleC, PuzzleADefaultConstructorTest) {
  PuzzleC c;
  EXPECT_EQ(c.getDescription(), "");
  EXPECT_EQ(c.getItemName(), "");
  EXPECT_EQ(c.getIsCompleted(), false);
}
