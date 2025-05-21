/**
* \author Jordon Harris, Mackenzie Kure, Scott Sonnleitner
* \date October 28, November 9, November 13, 2020
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include <utility>
#include <random>
#include "Item.h"
#include "playerStat.h"

//****************************************************************************
//                     Implement members of the Item Class
//****************************************************************************

    void Item::setIsCompleted(bool result) {
      this->isCompleted = result;
    }

    bool Item::getIsCompleted() {
      return this->isCompleted;
    }

    void Item::setDescription(std::string d) {
      this->description = d;
    }

    std::string Item::getDescription() {
      return this->description;
    }

     void Item::setItemName(std::string iName) {
       this->itemName = iName;
      }

     std::string Item::getItemName() {
       return this->itemName;
      }
     void Item::setIsPuzzle(bool solution) {
        this->isPuzzle = solution;
     }
     bool Item::getIsPuzzle() {
       return this->isPuzzle;
     }

//****************************************************************************
//                     Implement members of the NPC Class
//****************************************************************************

    NPC::NPC() {
      Item::setDescription("");
      Item::setItemName("");
      Item::setIsCompleted(false);
      Item::setIsPuzzle(false);
      this->message = "";
    }

    NPC::NPC(std::string desc, std::string itm, std::string m) {
      Item::setDescription(desc);
      Item::setItemName(itm);
      Item::setIsCompleted(false);
      Item::setIsPuzzle(false);
      this->message = m;
    }

    void NPC::interaction() {
      std::cout << std::endl;
      std::cout << Item::getDescription() << std::endl;
      std::cout << getMessage() << std::endl;
      std::cout << std::endl;
    }

    void NPC::setMessage(std::string m) {
      this->message = m;
    }

    std::string NPC::getMessage() {
      return this->message;
    }

//****************************************************************************
//                     Implement members of the Object Class
//****************************************************************************

    Object::Object() {
      Item::setDescription("");
      Item::setItemName("");
      Item::setIsCompleted(false);
      Item::setIsPuzzle(false);
    }

    Object::Object(std::string desc, std::string itm) {
      Item::setDescription(desc);
      Item::setItemName(itm);
      Item::setIsCompleted(false);
      Item::setIsPuzzle(false);
    }

    void Object::interaction() {
      std::cout << getItemName() << std::endl;
      std::cout << getDescription() << std::endl;
      if (getItemName() == "snowsuit" || getItemName() == "lava suit") {
        std::cout << std::endl;
        std::cout << "Do you want to take it (yes/no)? " << std::endl;
        std::cout << "Enter yes/no: ";
        std::cin >> inputString;
        transform(inputString.begin(), inputString.end(),
                inputString.begin(), tolower);
        while (!(inputString == "yes" || inputString == "no")) {
          std::cout << "invalid input: try again: ";
          std::cin >> inputString;
          transform(inputString.begin(), inputString.end(),
                  inputString.begin(), tolower);
        }
        if (inputString == "yes") {
          Item::setIsCompleted(true);
        } else {
            Item::setIsCompleted(false);
          }
    }
  }

//****************************************************************************
//                 Implement members of the PuzzleA Class
//****************************************************************************

    PuzzleA::PuzzleA() {
      Puzzles::setDescription("");
      Puzzles::setItemName("");
      Puzzles::setIsCompleted(false);
      Puzzles::setIsPuzzle(true);
    }

    PuzzleA::PuzzleA(std::string desc, std::string itm) {
      Puzzles::setDescription(desc);
      Puzzles::setItemName(itm);
      Puzzles::setIsCompleted(false);
      Puzzles::setIsPuzzle(true);
    }

    void PuzzleA::interaction() {
      std::cout << std::endl;
      std::cout << Puzzles::getDescription() << std::endl;
      std::string s;
      std::cout << std::endl;
      std::cout << "Solve the binary math equation to not die: " << std::endl;
      creatingQuestions();
      for (int i = 0; i < 10; i++) {
      std::random_shuffle(listOfQuestions.begin(), listOfQuestions.end());
      }
      //Randomizing Questions:
      int randomNumberMT = 0;
      numOfQuestions = listOfQuestions.size();
      std::mt19937 mt_rand(time(0));
      randomNumberMT = mt_rand();
      questionNum = ((abs(randomNumberMT) % numOfQuestions) + 1);

      std::cout << listOfQuestions.at(questionNum-1).question;
      std::cout << "  (write the answer in decimal): ";
      std::cin >> s;
      std::cout << std::endl;
      if (s == listOfQuestions.at(questionNum-1).answer) {
        std::cout << std::endl;
        std::cout << "You are correct, congrats on not dying. " << std::endl;
        std::cout << std::endl;
        Puzzles::setIsCompleted(true);
      } else {
        Puzzles::setIsCompleted(false);
      }
    }


    void PuzzleA::creatingQuestions() {
      Question q1;
      q1.question = "What is 10101010 + 11001100?";
      q1.answer = "374";
      listOfQuestions.push_back(q1);
      Question q2;
      q2.question = "What is 00010010 - 00010001?";
      q2.answer = "1";
      listOfQuestions.push_back(q2);
      Question q3;
      q3.question = "What is 00011010 + 01001010?";
      q3.answer = "100";
      listOfQuestions.push_back(q3);
      Question q4;
      q4.question = "What is 00101000 - 00100011?";
      q4.answer = "5";
      listOfQuestions.push_back(q4);
      Question q5;
      q5.question = "What is 00001001 + 00001000?";
      q5.answer = "17";
      listOfQuestions.push_back(q5);
    }

    //*************************************************************************
    //                 Implement members of the PuzzleB Class
    //*************************************************************************

        PuzzleB::PuzzleB() {
          Puzzles::setDescription("");
          Puzzles::setItemName("");
          Puzzles::setIsCompleted(false);
          Puzzles::setIsPuzzle(true);
        }

        PuzzleB::PuzzleB(std::string desc, std::string itm) {
          Puzzles::setDescription(desc);
          Puzzles::setItemName(itm);
          Puzzles::setIsCompleted(false);
          Puzzles::setIsPuzzle(true);
        }

        void PuzzleB::interaction() {
          chooseQuestionNumber();
          setupBoard(questionNumber);
          printBoard();
          std::cout << std::endl;
          std::cout << "The puzzle is a tictactoe board.\n";
          std::cout << "Where does the X side need to place a mark in order";
          std::cout << " to win?\n";
          getInput();
          bool checkFlag = false;
          setIsCompleted(checkAnswer(inputRow, inputColumn));
          if (isCompleted == true) {
            std::cout << "Your answer is correct.\n";
          } else {
            Puzzles::setIsCompleted(false);
            std::cout << "Your answer is incorrect. ";
            std::cout << "The punishment is death.\n";
            }
        }

        int PuzzleB::chooseQuestionNumber() {
          int randomNumberMT = 0;
          std::mt19937 mt_rand(time(0));
          randomNumberMT = mt_rand();

          questionNumber = ((abs(randomNumberMT) % numOfQuestions) + 1);
          return questionNumber;
        }

        void PuzzleB::setupBoard(int questionNumber) {
          if (questionNumber == 1) {
            //Row 1
            x1y1 = 'x';
            x2y1 = 'x';
            x3y1 = 'o';
            //Row 2
            x1y2 = 'x';
            x2y2 = 'x';
            x3y2 = 'o';
            //Row 3
            x1y3 = 'o';
            x2y3 = 'o';
            x3y3 = '-';

            correctRow = 3;
            correctColumn = 3;
          } else if (questionNumber == 2) {
            //Row 1
            x1y1 = '-';
            x2y1 = 'o';
            x3y1 = 'o';
            //Row 2
            x1y2 = 'x';
            x2y2 = '-';
            x3y2 = '-';
            //Row 3
            x1y3 = 'x';
            x2y3 = '-';
            x3y3 = '-';

            correctRow = 1;
            correctColumn = 1;
          } else if (questionNumber == 3) {
            //Row 1
            x1y1 = 'o';
            x2y1 = 'x';
            x3y1 = 'o';
            //Row 2
            x1y2 = '-';
            x2y2 = 'x';
            x3y2 = '-';
            //Row 3
            x1y3 = '-';
            x2y3 = '-';
            x3y3 = '-';

            correctRow = 3;
            correctColumn = 2;
          }
        }

    void PuzzleB::printBoard() {
          std::cout << "Row/Col" << "\t\t" << '1' << '\t' << '2' << '\t' << '3'
                    << '\n';
          std::cout << " 1:" << "\t\t" << x1y1 << '\t' << x2y1 << '\t' << x3y1
                    << '\t' << '\n';
          std::cout << " 2:" << "\t\t" << x1y2 << '\t' << x2y2 << '\t' << x3y2
                    << '\t' << '\n';
          std::cout << " 3:" << "\t\t" << x1y3 << '\t' << x2y3 << '\t' << x3y3
                    << '\t' << '\n';
      }

        void PuzzleB:: getInput() {
          std::cout << std::endl;
          std::cout << "Choose a row number (1 is the top, 3 is the bottom): ";
          std::cin >> inputRow;
          while (!(inputRow == 1 || inputRow == 2 || inputRow == 3)) {
            std::cout << "Invalid input, try again: ";
            std::cin >> inputRow;
          }
          std::cout << std::endl;
          std::cout << "\nChoose a column number ";
          std::cout <<"(1 is the left, 3 is the right): ";
          std::cin >> inputColumn;
          while (!(inputColumn == 1 || inputColumn == 2 || inputColumn == 3)) {
            std::cout << "Invalid input, try again: ";
            std::cin >> inputColumn;
          }
        }

        bool PuzzleB::checkAnswer(int inputRow, int inputColumn) {
          if (inputRow == correctRow) {
            if (inputColumn == correctColumn) {
              return true;
            }
          }
            return false;
        }

//****************************************************************************
//                 Implement members of the PuzzleC Class
//****************************************************************************
    PuzzleC::PuzzleC() {
      Puzzles::setDescription("");
      Puzzles::setItemName("");
      Puzzles::setIsCompleted(false);
      Puzzles::setIsPuzzle(true);
    }

    PuzzleC::PuzzleC(std::string desc, std::string itm) {
      Puzzles::setDescription(desc);
      Puzzles::setItemName(itm);
      Puzzles::setIsCompleted(false);
      Puzzles::setIsPuzzle(true);
    }

     void PuzzleC::interaction() {
       std::string s;
       std::cout << "Enter the correct combination, \n";
       std::cout << "Get it wrong and you die." << std::endl;
       std::cout << "combination: ";
       std::cin >> s;
       if (s == code) {
         std::cout << std::endl;
         std::cout << "You entered the correct code!";
         std::cout << std::endl;
         Puzzles::setIsCompleted(true);
       } else {
         Puzzles::setIsCompleted(false);
       }
     }
