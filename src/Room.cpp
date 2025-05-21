/**
* \author Jordon Harris, Mackenzie Kure, Cassandra Olfert
* \date October 28, November 2020
*/

#include <iostream>
#include <cctype>
#include <map>
#include <algorithm>
#include <utility>
#include <string>
#include "Room.h"
#include "Coordinate.h"
#include "Inventory.h"
#include "Item.h"
#include "playerStat.h"
#include "Exceptions.h"

//****************************************************************************
//                     Implement members of the Room Class
//****************************************************************************

// getCoord returns a pointer to the Coordinate class
Coordinate* Room::getCoord() {return coord;}

// getInventory returns a pointer to Inventory
Inventory* Room::getInventory() { return in;}

// getStats returns private variable for playerStat
PlayerStat* Room::getStats() {return stats;}

// lists the "doors" in the vector
void Room::listDoors() {
  int doorNum = 1;
  for (auto it : doors) {
    std::cout << doorNum << ". " << it.first << std::endl;
    doorNum++;
  }
}

// changeClothes
void Room::changeClothes() {
  std::cout << "You are wearing: ";
  std::cout << stats->getWardrobe()->getInventoryVector()
  .at(stats->getWornClothing())->getDescription() << std::endl;
  std::cout << std::endl;
  std::cout << "Do you want to change what you are wearing (yes/no)? \n";
  std::cout << "Enter yes/no: ";
  std::cin >> inputString;
  transform(inputString.begin(), inputString.end(),
          inputString.begin(), tolower);
  while (!(inputString == "yes" || inputString == "no")) {
    std::cout << "not a valid option, try again: ";
    std::cin >> inputString;
    transform(inputString.begin(), inputString.end(),
            inputString.begin(), tolower);
  }
  if (inputString == "yes") {
    stats->getWardrobe()->listInventory();
    std::cout << "select the number of the item you wish to change";
    std::cout << " into: ";
    std::cin >> userInput;
    while (userInput > stats->getWardrobe()->sizeOfInventory() ||
            userInput < 0) {
        std::cout << "not a valid item number, try again: ";
        std::cout << "Input: ";
        std::cin >> userInput;
        }
            userInput = userInput - 1;
            stats->setWornClothing(userInput);
            std::cout << "You are now wearing ";
            std::cout << stats->getWardrobe()->getInventoryVector()
            .at(userInput)->getDescription() << std::endl;
    } else {
      std::cout << "You did not want to change your clothes...";
      std::cout << " Your choice, but you do kind of stink. \n";
      std::cout << std::endl;
    }
}
// verifies that the stringInput is correct
bool Room::checkDoorInput(std::string s) {
  for (auto it : doors) {
    if (s == it.first) {
      return true;
    }
  } return false;
}
// Help function for user, outputs commands helpful to player
bool Room::help() {
  std::cout << std::endl;
  std::cout << "HELP:" << std::endl;
  std::cout << "So, you need help do you. I'll do the best I can. \n";
  std::cout << "In every room you enter you'll have a series of choices to \n";
  std::cout << "choose from: \nPuzzles: solve 3 of these to win the game\n";
  std::cout << "The puzzles will alternate depending on the room you \n";
  std::cout << "are in, there might not even be a puzzle in that room.\n";
  std::cout << std::endl;
  std::cout << "Character: Talk to the characters to gather information and \n";
  std::cout << "hints, some might give you pretty useless info though ";
  std::cout << std::endl;
  std::cout << "Items/Objects: These random items within the rooms may help\n";
  std::cout << "you later in the game to survive, others will\n";
  std::cout << "provide you with important information. Depening\n";
  std::cout << "on the item, you either can take it with\n";
  std::cout << "you or just observe it.\n";
  std::cout << std::endl;
  std::cout << "Doors: To leave the room and move onto another, select the \n";
  std::cout << "Doors option, here you will get a to choose an option\n";
  std::cout << "of the doors you can pass through, each door leading to";
  std::cout << "\nanother room in the cube and new experiences.\n";
  std::cout << std::endl;
  std::cout << "If you keep dying whenever you enter a room....pay attention\n";
  std::cout << "to what you are wearing....\n";
  std::cout << "Good Luck, Don't Die!" << std::endl;
  std::cout << std::endl;
}

// checks to see if the object is already in the user's inventory
bool Room::checkWardrobe(Item* obj) {
  for (auto it : stats->getWardrobe()->getInventoryVector()) {
      if (it->getItemName() == obj->getItemName()) {
        return true;
      }
  } return false;
}

// runs the interaction for the puzzle, NPC, or Object selected
void Room::runInteraction(Item* itm) {
  if (itm->getIsPuzzle() && puzzleCompletedCheck()) {
    std::cout << std::endl;
    std::cout << "You have already completed this puzzle" << std::endl;
    return;
  }
  std::cout << std::endl;
  itm->interaction();
    if (itm->getIsPuzzle()) {
      if (!(itm->getIsCompleted())) {
        stats->setIsDead(true);
        stayInRoom = false;
        if (stayInRoom == false) return;
      } else {
        stats->incrementSolvedPuzzleCount();
        puzzleCompleted = true;
      }
    }
    if (!(itm->getIsPuzzle())) {
      if (itm->getIsCompleted()) {
          if (!(checkWardrobe(itm))) {
            stats->getWardrobe()->addToInventory(itm);
            std::cout << std::endl;
            std::cout << "The item has been added to your backpack.";
            std::cout << std::endl;
          } else {
            std::cout << "Already have that item of clothing in your ";
           std::cout << "backback\n";
           std::cout << std::endl;
          }
      }
    }
}

// check if the puzzle had been previously completed
bool Room::puzzleCompletedCheck() {
    if (puzzleCompleted == true) {
      return true;
    }
    return false;
}

// enables implementation for selection a door, and changing the
// playerStat coordinate.
void Room::doorSelection() {
  listDoors();
  std::cout << "Enter just the direction of the door you wish"
                " to pass through (eg east, South): \n";
  std::cout << "Input direction: ";
  std::cin >> inputString;
  transform(inputString.begin(), inputString.end(),
          inputString.begin(), toupper);
  while (!(checkDoorInput(inputString))) {
    std::cout << "Not a door name, try again: ";
    std::cout << "Input: ";
    std::cin >> inputString;
    transform(inputString.begin(), inputString.end(),
            inputString.begin(), toupper);
  }
  stats->setLocation(doors.at(inputString));
}

// provides the implementation necessary for the user to select a choice from
// the room's Inventory
int Room::inventorySelection(int doorOption, int helpOption) {
  std::cout << "In the room you see:" << std::endl;
  getInventory()->listInventory();
  std::cout << doorOption << " Doors \n";
  std::cout << helpOption << " Help (select if you need help)\n";
  std::cout << "select the number of what you would like to do/see: ";
  std::cin >> userInput;
  while ((userInput > helpOption || userInput < 1)) {
    std::cout << "Invalid input: try again: ";
    std::cin >> userInput;
  }
    return userInput;
}

// runRoom runs the room loop, returns new location
void Room::runRoom() {
  stayInRoom = true;
  int doorOption = getInventory()->sizeOfInventory() + 1;
  int helpOption = doorOption + 1;
  printDescription();
  std::cout << std::endl;
  changeClothes();
  std::cout << std::endl;
  while (stayInRoom == true) {
  if (!(checkClothes())) {
    std::cout << "You should have changed...." << std::endl;
    stats->setIsDead(true);
    stayInRoom = false;
    if (stayInRoom == false) break;
  } else {
      userInput = inventorySelection(doorOption, helpOption);
      if (userInput == doorOption) {
        doorSelection();
        stayInRoom = false;
        if (stayInRoom == false) return;
      } else if (userInput == helpOption) {
        bool throwAwayBool = help();
      } else {
          userInput = userInput -1;
          auto it = getInventory()->getInventoryVector().at(userInput);
          runInteraction(it);
          if (stayInRoom == false) break;
          if (stats->getSolvedPuzzleCount() >= 3) break;
        }
      }
    }
}

//****************************************************************************
//                    Implement members of the NormalRoom Class
//****************************************************************************
        NormalRoom::NormalRoom() {
          coord = nullptr;
          in = nullptr;
          stats = nullptr;
        }

        NormalRoom::NormalRoom(int yCoord, PlayerStat* ps) {
          in = NormalRoom::assignInventory(yCoord);
          coord = NormalRoom::assignCoordinate(yCoord);
          stats = ps;
          doors = NormalRoom::assignDoorCoords();
        }

        Inventory* NormalRoom::assignInventory(int coord) {
          if (coord == 00) {
            // create Inventory and Items for Area1 normalRoom
            Inventory* invNR1 = new Inventory();
            std::string npcStr1 = "A hag of an old woman, who's face appears"
                                  " to be melting straight off her face. \n";
            std::string npcM1 = "As you approach she looks up from her knitting"
                                "and says, "
                                "\n \"You better put something on soon deary,\n"
                                "  the temperature can by quite temperamental."
                                "\"\n";
            NPC* npcNR1 = new NPC(npcStr1, "Old wrinkled woman", npcM1);
            std::string objStr1 = "A metallic looking suit, it's so bright it's"
                                  " hard to even look at.";
            Object* objNR1 = new Object(objStr1, "lava suit");
            invNR1->addToInventory(npcNR1);
            invNR1->addToInventory(objNR1);

            return invNR1;
          } else if (coord == 01) {
            // create Inventory and Items for Area2 normalRoom
            Inventory* invNR2 = new Inventory();
            std::string npcStr4 = "He's a young looking professor. \n"
                                  "He has blonde hair, and for some reason, \n"
                                  "is missing an eye.\n when you walk over he "
                                  "looks up from the book he is reading and "
                                  "states: ";
            std::string npcM4 = "\"Hopefully you haven't fogorgotten how to do"
                                " binary math. It might just save your life.\" "
                                "\n";
            NPC* npcNR2 = new NPC(npcStr4, "Professor", npcM4);
            std::string objStr4 = "A thin red book opened to a page, \n an "
                                  "equation is written across its pages: (39(7)"
                                  " + 5^3(4))*3 \n";
            Object* objNR2 = new Object(objStr4, "Red Book");
            std::string puzN1 = "Puzzle: Math";
            std::string puzD1 = "The room begins to fill water, answer the \n"
                                "binary math equation to stop it from flooding";
            Puzzles* puzzleNR2 = new PuzzleA(puzD1, puzN1);
            invNR2->addToInventory(npcNR2);
            invNR2->addToInventory(objNR2);
            invNR2->addToInventory(puzzleNR2);

            return invNR2;
          } else if (coord == 02) {
            // create Inventory and Items for Area3 normalRoom
            Inventory* invNR3 = new Inventory();
            std::string objStr6 = "The screen flickers in and out of existance "
                                  "flashing a series of numbers\n over and over"
                                  " again: 2......3......1.....9 \n";
            Object* objNR3 = new Object(objStr6, "Broken screen");
            std::string objStr7 = "metallic looking suit. \n";
            Object* objNR3second = new Object(objStr7, "lava suit");
            std::string puzN2 = "Puzzle: keypanel";
            std::string puzD2 = "A keypanel embedded into a wall of the room.\n"
                                "Enter the correct combination before the timer"
                                "\n runs out, who knows what happens.";
            Puzzles* puzzleNR3 = new PuzzleC(puzD2, puzN2);
            invNR3->addToInventory(objNR3);
            invNR3->addToInventory(objNR3second);
            invNR3->addToInventory(puzzleNR3);

            return invNR3;
          }
        }

        Coordinate* NormalRoom::assignCoordinate(int coord) {
          if (coord == 00) {
            Coordinate* c = new Coordinate(0, 0);
            return c;
          } else if (coord == 01) {
            Coordinate* c1 = new Coordinate(0, 1);
            return c1;
          } else if (coord == 02) {
            Coordinate* c2 = new Coordinate(0, 2);
            return c2;
          }
        }
          // assigns the "door" coordinates for a given room
  std::map<std::string, Coordinate*>  NormalRoom::assignDoorCoords() {
    if (getCoord()->getX() == 0 && getCoord()->getY() == 0) {
      Coordinate* c1 = new Coordinate(1, 0);
      doors.insert(std::pair<std::string, Coordinate*>("EAST", c1));
      Coordinate* c2 = new Coordinate(0, 1);
      doors.insert(std::pair<std::string, Coordinate*>("SOUTH", c2));
      return doors;
    }
    if (getCoord()->getX() == 0 && getCoord()->getY() == 1) {
      Coordinate* c1 = new Coordinate(0, 0);
      doors.insert(std::pair<std::string, Coordinate*>("NORTH", c1));
      Coordinate* c2 = new Coordinate(1, 1);
      doors.insert(std::pair<std::string, Coordinate*>("EAST", c2));
      Coordinate* c3 = new Coordinate(0, 2);
      doors.insert(std::pair<std::string, Coordinate*>("SOUTH", c3));
      return doors;
    }
    if (getCoord()->getX() == 0 && getCoord()->getY() == 2) {
      Coordinate* c1 = new Coordinate(0, 1);
      doors.insert(std::pair<std::string, Coordinate*>("NORTH", c1));
      Coordinate* c2 = new Coordinate(1, 2);
      doors.insert(std::pair<std::string, Coordinate*>("EAST", c2));
      return doors;
    }
  }

  // checkClothes returns true if player is wearing the right
  // clothes false otherwise.
bool NormalRoom::checkClothes() {
  auto it = stats->getWardrobe()->getInventoryVector()
          .at(stats->getWornClothing());
  if (it->getItemName() == "normal clothes")  {
      return true;
    } else {
      if (it->getItemName() == "lava suit") {
        std::cout << "You were still wearing your lava suit in a room that\n";
        std::cout << "did not require it, you over heated and died.\n";
      }
      if (it->getItemName() == "snowsuit") {
        std::cout << "You were wearing your snow clothes in a room that did";
        std::cout << "\nnot require it, you couldn't see in your snowsuit and";
        std::cout << "\nand walked right into a bottomless pit and died.\n";
      }
        return false;
    }
  }

    // prints a description of the Room
  void NormalRoom::printDescription() {
    std::cout << std::endl;
    std::cout << "All that surrounds you are seemingly blank walls.\n";
    std::cout << "A gentle breeze wafts by. \nWhile ominous, at least the";
    std::cout << " temperature in here is moderate." << std::endl;
    std::cout << std::endl;
  }

//****************************************************************************
//                    Implement members of HotRoom Class
//****************************************************************************
        HotRoom::HotRoom() {
          coord = nullptr;
          in = nullptr;
          stats = nullptr;
        }

        HotRoom::HotRoom(int yCoord, PlayerStat* ps) {
          in = HotRoom::assignInventory(yCoord);
          coord = HotRoom::assignCoordinate(yCoord);
          stats = ps;
          doors = HotRoom::assignDoorCoords();
        }

        Inventory* HotRoom::assignInventory(int coord) {
          if (coord == 10) {
            // create Inventory and Items for Area1 HotRoom
            Inventory* invHR1 = new Inventory();
            std::string npcStr2 = "He appears to be wearing a white powdered "
                                  "wig and robes akin to a dress... \n clearly "
                                  "he's in the wrong century. \n";
            std::string npcM2 = "He stares off blankly and states, \"A picture"
                                " can hold a thousand words... or a number\".";
            NPC* npcHR1 = new NPC(npcStr2, "Man appearing from the 17th century"
                                  , npcM2);
            std::string objStr2 = "Snow clothes making you appear more like\n a"
                                  " marshmallow more than human. \n";
            Object* objHR1 = new Object(objStr2, "snowsuit");
            invHR1->addToInventory(npcHR1);
            invHR1->addToInventory(objHR1);

            return invHR1;
          } else if (coord == 11) {
            // create Inventory and Items for Area2 HotRoom
            Inventory* invHR2 = new Inventory();
            std::string npcStr5 = "She is the empitome of a librarian: \n"
                                  "cardigan, reading glasses, and a long skirt."
                                  "\nNot to mention she smells of moth balls.";
            std::string npcM5 = "She states, \"I wouldn't try that next puzzle "
                                "if I were you,\" \n \" but not until you've "
                                "had time to read a book or appreciate some "
                                "art. \" \n";
            NPC* npcHR2 = new NPC(npcStr5, "Librarian", npcM5);
            std::string objStr5 = "A blue snowsuit, might be useful\nUnless you"
                                  " already collected a set of clothes for cold"
                                  " weather. \n";
            Object* objHR2 = new Object(objStr5, "snowsuit");
            std::string puzN3 = "Puzzle: combination lock";
            std::string puzD3 = "Enter the correct code into the combination\n "
                                "lock, else a bomb will detonate. \n";
            Puzzles* puzzleHR2 = new PuzzleC(puzD3, puzN3);
            invHR2->addToInventory(npcHR2);
            invHR2->addToInventory(objHR2);
            invHR2->addToInventory(puzzleHR2);

            return invHR2;
          } else if (coord == 12) {
            // create Inventory and Items for Area3 HotRoom
            Inventory* invHR3 = new Inventory();
            std::string npcStr7 = "A little girl plays with a skipping rope. \n"
                                  "her pink dress flopping around everytime she"
                                  " jumps.\n Appearing rather ghostlike, her "
                                  "feet never seem to actually hit the ground.";
            std::string npcM7 = "When you approach she looks up and states "
                                "matter of fact, \n \"I've always liked tic tac"
                                " toe, not a fan of the version here though.\""
                                "\n I can't seem to win.\" \n";
            NPC* npcHR3 = new NPC(npcStr7, "little girl", npcM7);
            std::string puzN4 = "Puzzle: tictactoe";
            std::string puzD4 = "tictactoe board lays across the floor. \nStep";
                                " on the wrong tile and the floor will cave in";
            Puzzles* puzzleHR3 = new PuzzleB(puzD4, puzN4);
            invHR3->addToInventory(npcHR3);
            invHR3->addToInventory(puzzleHR3);

            return invHR3;
          }
        }

        Coordinate* HotRoom::assignCoordinate(int coord) {
          if (coord == 10) {
            Coordinate* c = new Coordinate(1, 0);
            return c;
          } else if (coord == 11) {
            Coordinate* c1 = new Coordinate(1, 1);
            return c1;
          } else if (coord == 12) {
            Coordinate* c2 = new Coordinate(1, 2);
            return c2;
          }
        }

        // assigns the "door" coordinates for a given room
        std::map<std::string, Coordinate*>  HotRoom::assignDoorCoords() {
          if (getCoord()->getX() == 1 && getCoord()->getY() == 0) {
            Coordinate* c1 = new Coordinate(2, 0);
            doors.insert(std::pair<std::string, Coordinate*>("EAST", c1));
            Coordinate* c2 = new Coordinate(1, 1);
            doors.insert(std::pair<std::string, Coordinate*>("SOUTH", c2));
            Coordinate* c3 = new Coordinate(0, 0);
            doors.insert(std::pair<std::string, Coordinate*>("WEST", c3));
            return doors;
            }
          if (getCoord()->getX() == 1 && getCoord()->getY() == 1) {
            Coordinate* c1 = new Coordinate(1, 0);
            doors.insert(std::pair<std::string, Coordinate*>("NORTH", c1));
            Coordinate* c2 = new Coordinate(2, 1);
            doors.insert(std::pair<std::string, Coordinate*>("EAST", c2));
            Coordinate* c3 = new Coordinate(1, 2);
            doors.insert(std::pair<std::string, Coordinate*>("SOUTH", c3));
            Coordinate* c4 = new Coordinate(0, 1);
            doors.insert(std::pair<std::string, Coordinate*>("WEST", c4));
            return doors;
          }
          if (getCoord()->getX() == 1 && getCoord()->getY() == 2) {
            Coordinate* c1 = new Coordinate(1, 1);
            doors.insert(std::pair<std::string, Coordinate*>("NORTH", c1));
            Coordinate* c2 = new Coordinate(2, 2);
            doors.insert(std::pair<std::string, Coordinate*>("EAST", c2));
            Coordinate* c3 = new Coordinate(0, 2);
            doors.insert(std::pair<std::string, Coordinate*>("WEST", c3));
            return doors;
          }
        }

      // checkClothes returns true if player is wearing the right
      // clothes false otherwise.
      bool HotRoom::checkClothes() {
        auto it = stats->getWardrobe()->getInventoryVector()
                .at(stats->getWornClothing());
        if (it->getItemName() == "lava suit")  {
            return true;
          } else {
            if (it->getItemName() == "normal clothes") {
              std::cout << "You were still wearing your jeans abd t-shirt.\n";
              std::cout << "Those clothes did nothing to protect you from\n";
              std::cout << "The heat, you were burned alive and died.\n";
            }
            if (it->getItemName() == "snowsuit") {
              std::cout << "You were wearing your snow clothes, they caught on";
              std::cout << "\nfire in the heat, you died.\n";
            }
              return false;
          }
        }

        // prints a description of the Room
        void HotRoom::printDescription() {
          std::cout << std::endl;
          std::cout << "The second you step within this room,\n you are";
          std::cout << " bombarded with an overbearing amount of heat!. \n";
          std::cout << "your sweat inhibits your vision,\n you are unable to "
                       "see";
          std::cout << " through the sweat the pours off of your face. \n";
          std::cout << std::endl;
        }

  //***************************************************************************
  //                    Implement members of the ColdRoom Class
  //***************************************************************************
        ColdRoom::ColdRoom() {
          coord = nullptr;
          in = nullptr;
          stats = nullptr;
        }

        ColdRoom::ColdRoom(int yCoord, PlayerStat* ps) {
          in = ColdRoom::assignInventory(yCoord);
          coord = ColdRoom::assignCoordinate(yCoord);
          stats = ps;
          doors = ColdRoom::assignDoorCoords();
        }

        Inventory* ColdRoom::assignInventory(int coord) {
          if (coord == 20) {
            // create Inventory and Items for Area1 ColdRoom
            Inventory* invCR1 = new Inventory();
            std::string npcStr3 = "A pitch black cat, with eyes that seem \nto "
                                "stare into you soul, as most cats do.\n";
            std::string npcM3 = "The cat unalarmed by your precence, lets out a"
                                " \"Meow.\" \n and slinks away into the dark.";
            NPC* npcCR1 = new NPC(npcStr3, "Cat", npcM3);
            std::string objStr3 = "The painting is of Van Gough's starry night,"
                                  "\nHowever, someone has defaced it with the "
                                  "numbers 2319 roughly scratched across it.\n";
            Object* objCR1 = new Object(objStr3, "Painting");
            std::string puzN4 = "Puzzle: tictactoe";
            std::string puzD4 = "Another tictactoe boards spans the floor.";
            Puzzles* puzzleCR1 = new PuzzleB(puzD4, puzN4);
            invCR1->addToInventory(npcCR1);
            invCR1->addToInventory(objCR1);
            invCR1->addToInventory(puzzleCR1);

            return invCR1;
          } else if (coord == 21) {
            // create Inventory and Items for Area2 ColdRoom
            Inventory* invCR2 = new Inventory();
            std::string npcStr6 = "The man is dressed in tatters,his shredded"
                                  "clothes are \n barely hanging onto his lanky"
                                  " form. \n he runs into the wall repreating a"
                                  " phrase over and over again: \n";
            std::string npcM6 = "\"2319, it's 2319...\"";
            NPC* npcCR2 = new NPC(npcStr6, "A homeless looking man", npcM6);
            invCR2->addToInventory(npcCR2);

            return invCR2;
          } else if (coord == 22) {
            // create Inventory and Items for Area3 ColdRoom
            Inventory* invCR3 = new Inventory();
            std::string npcStr8 = "Honestly, he is the most non-descript human "
                                  "in existance. Couldn't describe him if I\n"
                                  " even wanted to \n";
            std::string npcM8 = "He looks up and states, \"still alive huh? "
                                "that won't last long I'm sure.\" \n";
            NPC* npcCR3 = new NPC(npcStr8, "Nondescript looking man", npcM8);
            std::string puzN5 = "Puzzle: Equation";
            std::string puzD5 = "Answer the binary math eqation, else the room "
                                "\n will fill with Gas and you wil surely die";
            Puzzles* puzzleCR3 = new PuzzleA(puzD5, puzN5);
            invCR3->addToInventory(npcCR3);
            invCR3->addToInventory(puzzleCR3);

            return invCR3;
          }
        }

        Coordinate* ColdRoom::assignCoordinate(int coord) {
          if (coord == 20) {
            Coordinate* c = new Coordinate(2, 0);
            return c;
          } else if (coord == 21) {
            Coordinate* c1 = new Coordinate(2, 1);
            return c1;
          } else if (coord == 22) {
            Coordinate* c2 = new Coordinate(2, 2);
            return c2;
          }
        }

        // assigns the "door" coordinates for a given room
        std::map<std::string, Coordinate*>  ColdRoom::assignDoorCoords() {
        if (getCoord()->getX() == 2 && getCoord()->getY() == 0) {
            Coordinate* c1 = new Coordinate(2, 1);
            doors.insert(std::pair<std::string, Coordinate*>("SOUTH", c1));
            Coordinate* c2 = new Coordinate(1, 0);
            doors.insert(std::pair<std::string, Coordinate*>("WEST", c2));
            return doors;
          }
        if (getCoord()->getX() == 2 && getCoord()->getY() == 1) {
            Coordinate* c1 = new Coordinate(2, 0);
            doors.insert(std::pair<std::string, Coordinate*>("NORTH", c1));
            Coordinate* c2 = new Coordinate(2, 2);
            doors.insert(std::pair<std::string, Coordinate*>("SOUTH", c2));
            Coordinate* c3 = new Coordinate(1, 1);
            doors.insert(std::pair<std::string, Coordinate*>("WEST", c3));
            return doors;
          }
        if (getCoord()->getX() == 2 && getCoord()->getY() == 2) {
            Coordinate* c1 = new Coordinate(2, 1);
            doors.insert(std::pair<std::string, Coordinate*>("NORTH", c1));
            Coordinate* c2 = new Coordinate(1, 2);
            doors.insert(std::pair<std::string, Coordinate*>("WEST", c2));
            return doors;
          }
        }

      // checkClothes returns true if player is wearing the right
      // clothes false otherwise.
      bool ColdRoom::checkClothes() {
        auto it = stats->getWardrobe()->getInventoryVector()
                .at(stats->getWornClothing());
        if (it->getItemName() == "snowsuit")  { //not correct name
            return true;
          } else {
            if (it->getItemName() == "normal clothes") {
              std::cout << "You were still wearing your jeans abd t-shirt.\n";
              std::cout << "Those clothes did nothing to protect you from\n";
              std::cout << "The cold, you were forze to death.\n";
            }
            if (it->getItemName() == "lava suit") {
              std::cout << "You were wearing your lava suit, all they did was";
              std::cout << "\naid you in freezing faster.\n";
            }
              return false;
          }
      }

      // prints a description of the Room
      void ColdRoom::printDescription() {
        std::cout << std::endl;
        std::cout << "Is that frostbite? your fingers begin discolour as";
        std::cout << " you take your first step into the room. \n" << std::endl;
        std::cout << "oops, there goes one of your fingers. \n If this keeps";
        std::cout << " up, you'll soom be left without a hand." << std::endl;
        std::cout << std::endl;
      }
