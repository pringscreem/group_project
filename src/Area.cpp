/**
* \author Jordon Harris, Mackenzie Kure, Scott Sonnleitner, Cassandra Olfert
* \date October, November 2020
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <utility>
#include "Area.h"
#include "Room.h"
#include "Coordinate.h"
#include "playerStat.h"

  // Returns a pointer to a Room in Area1
  std::vector<Room*> Area::getRoomVector() {return collectionOfRooms;}

  // Returns a pointer to the vector
  std::vector<Room*>* Area::getCollectionOfRooms() {
    std::vector<Room*>* myPtr = &collectionOfRooms;
    return myPtr;
}

//****************************************************************************
//                    Implement members of the Area1 Class
//****************************************************************************

        Area1::Area1(PlayerStat* pStats) {
          NormalRoom* nRoom1 = new NormalRoom(00, pStats);
          HotRoom* hRoom1 = new HotRoom(10, pStats);
          ColdRoom* cRoom1 = new ColdRoom(20, pStats);
          collectionOfRooms.push_back(nRoom1);
          collectionOfRooms.push_back(hRoom1);
          collectionOfRooms.push_back(cRoom1);
        }

        // prints description of Area1
        void Area1::printDescription() {
          std::cout << std::endl;
          std::cout << "The Area you have entered has a faded number 1.\n";
          std::cout << "The walls all around you seem to be coated in a thick";
          std::cout << "\nblack tar substance\n";
          std::cout << "painted on the wall.\n";
          std::cout << "Press enter to continue: ";
          std::getchar();
        }

        // Performs the trap check when the player enters a Room
        bool Area1::trapCheck() {
          printDescription();
          std::cout << "You see an annoying trap in front of you.\n";
          std::cout << "Do you want to activate the trap (yes/no)?\n";
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
            if (inputString == "no") {
              std::cout << std::endl;
              std::cout << "You step around the trap and continue.\n";
              return true;
            } else if (inputString == "yes") {
              std::cout << std::endl;
              std::cout << "You step directly on the annoying trap.";
              std::cout << "  Annoying things happen. \n";
              std::cout << "Black ink squirts you directly in the eye\n";
              std::cout << " Then you continue.\n";
              return true;
            }
      }

//****************************************************************************
//                    Implement members of the Area2 Class
//****************************************************************************

        Area2::Area2(PlayerStat* pStats) {
          NormalRoom* nRoom2 = new NormalRoom(01, pStats);
          HotRoom* hRoom2 = new HotRoom(11, pStats);
          ColdRoom* cRoom2 = new ColdRoom(21, pStats);
          collectionOfRooms.push_back(nRoom2);
          collectionOfRooms.push_back(hRoom2);
          collectionOfRooms.push_back(cRoom2);
        }

        // prints description of Area2
        void Area2::printDescription() {
          std::cout << std::endl;
          std::cout << "The area you have entered has a neon number 2 on the ";
          std::cout << "wall \n All around you are white walls, it looks like";
          std::cout << " an insane asylum\n";
          std::cout << "painted on the wall.\n";
          std::cout << "Press enter to continue: ";
          std::getchar();
        }

        // Performs the trap check when the player enters a Room
        bool Area2::trapCheck() {
          printDescription();
          std::cout << "You see an broken trap in front of you.\n";
          std::cout << "Do you want to activate the trap (yes/no)?\n";
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
            if (inputString == "no") {
              std::cout << std::endl;
              std::cout << "You step around the trap and continue.\n";
              return true;
            } else if (inputString == "yes") {
              std::cout << std::endl;
              std::cout << "You step directly on the broken trap.\n";
              std::cout << "It does nothing, beacause it is broken, duh.\n";
              std::cout << " On you continue.\n";
                return true;
              }
       }

//****************************************************************************
//                    Implement members of the Area3 Class
//****************************************************************************

        Area3::Area3(PlayerStat* pStats) {
          NormalRoom* nRoom3 = new NormalRoom(02, pStats);
          HotRoom* hRoom3 = new HotRoom(12, pStats);
          ColdRoom* cRoom3 = new ColdRoom(22, pStats);
          collectionOfRooms.push_back(nRoom3);
          collectionOfRooms.push_back(hRoom3);
          collectionOfRooms.push_back(cRoom3);
        }

        // prints description of Area3
        void Area3::printDescription() {
          std::cout << std::endl;
          std::cout << "The Area you've entered has a blood read 3 dripping\n";
          std::cout << "dripping down the wall. Definately an unsettling sight";
          std::cout << std::endl;
          std::cout << "Press enter to continue: ";
          std::getchar();
        }

        // Performs the trap check when the player enters a Room
        bool Area3::trapCheck() {
          printDescription();
          std::cout << "You see an lethal trap in front of you.\n";
          std::cout << "Do you want to activate the trap (yes/no)?\n";
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
            if (inputString == "no") {
              std::cout << std::endl;
              std::cout << "You step around the trap and continue.\n";
              return true;
            } else if (inputString == "yes") {
                std::cout << std::endl;
                std::cout << "You step directly on the lethal trap.";
                std::cout << "  Terrible things happen.\n";
                std::cout << "An Axe falls down from the ceiling and ";
                std::cout << " decapitates you.\n";
                std::cout << "That explains all of the blood on the wall...\n";
                  return false;
                }
     }
