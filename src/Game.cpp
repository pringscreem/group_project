/**
* \author Jordon Harris, Cassandra Olfert, Mackenzie Kure, Scott Sonnleitner
* \date October, November 2020
*/

#include <iostream>
#include <vector>
#include <string>
#include "Area.h"
#include "Game.h"
#include "playerStat.h"

        Game::Game() {
          // playerStat - initialize with normal clothes, and not dead
          Inventory* pInv = new Inventory();
          // start with normal clothes in inventory
          Object* normalClothes = new Object("Blue Jeans and t-Shirt",
          "normal clothes");
          pInv->addToInventory(normalClothes);
          // player starts in 0,0
          Coordinate* pLoc = new Coordinate(0, 0);
          p1Stats = new PlayerStat(pLoc, pInv, 0, false);
          // Area 1 - creates and adds its 3 rooms
          Area1* a1 = new Area1(p1Stats);
          // Area 2 - creates and adds its 3 rooms
          Area2* a2 = new Area2(p1Stats);
          // Area 3 - creates and adds its 3 rooms
          Area3* a3 = new Area3(p1Stats);
          collectionOfAreas.push_back(a1);
          collectionOfAreas.push_back(a2);
          collectionOfAreas.push_back(a3);
          // Now perform the pointer swap so that PlayerStats has the correct
          // Coordinate pointer instead of a different, identical one.
          std::vector<Room*>* tempVecPtr = a1->getCollectionOfRooms();
          std::vector<Room*>::iterator it = tempVecPtr->begin();
          Room* tempRmPtr = *it;
          Coordinate* tempCrdPtr = tempRmPtr->getCoord();
          p1Stats->setLocation(tempCrdPtr);
          delete pLoc;
          // Set the currentArea and currentRoom to the starting values (0,0)
          updateLocation();
        }

        Game::~Game() {
          for (auto it : collectionOfAreas) {
            delete it;
          }
          delete p1Stats;
          delete currentRoom;
          delete currentArea;
        }

        void Game::openingMessage() {
          std::cout << "You are trapped within a black ominous cube hurtling";
          std::cout << " through who knows where." << std::endl;
          std::cout << "Your only chance of escape is to solve three puzzles.";
          std::cout << std::endl;
          std::cout << "Solve them and you are free, good luck not dying along";
          std::cout << "\nthe way, as every puzzle you fail will result in \n";
          std::cout << "imminent death." << std::endl;
          std::cout << "Make it passed the traps, annoyances, and solve the\n";
          std::cout << "puzzles and you just might make it out alive. \n";
          std::cout << "Good luck!" << std::endl;
          std::cout << "press enter to start the game: ";
          std::getchar();
        }

        void Game::endGame() {
          if (isDead == true) {
            std::cout << "You are dead.\n";
          }
          if (gameIsWon == false) {
            std::cout << "You have lost.\n Game Over.\n";
          }
          if (gameIsWon == true) {
            std::cout << "Congratulations, you won.\n";
          }
        }

        void Game::updateEndConditions() {
          isDead = p1Stats->getIsDead();
          if (p1Stats->getSolvedPuzzleCount() >= 3) {
            gameIsWon = true;
          }
        }

        void Game::runGame() {
          updateLocation();
          openingMessage();
          while ((gameIsWon == false) && (isDead == false)) {
            if (!(currentArea->trapCheck())) {
              p1Stats->setIsDead(true);
              updateEndConditions(); break;
            }
            currentRoom->runRoom();
            updateLocation();
            updateEndConditions();
           }
            endGame();
          }

        // Updates runGame variables/conditions
        void Game::updateLocation() {
          int i = p1Stats->getLocation()->getY();
          if (i == 0) {
            currentArea = collectionOfAreas.at(0);
            auto it = collectionOfAreas.at(0);
              for (auto i : it->getRoomVector()) {
                if (p1Stats->getLocation()->getX() == i->getCoord()->getX()) {
                  currentRoom = i;
                }
              }
          }
          if (i == 1) {
            currentArea = collectionOfAreas.at(1);
            auto it = collectionOfAreas.at(1);
              for (auto i : it->getRoomVector()) {
                if (p1Stats->getLocation()->getX() == i->getCoord()->getX()) {
                  currentRoom = i;
                }
              }
          }
          if (i == 2) {
            currentArea = collectionOfAreas.at(2);
            auto it = collectionOfAreas.at(2);
              for (auto i : it->getRoomVector()) {
                if (p1Stats->getLocation()->getX() == i->getCoord()->getX()) {
                  currentRoom = i;
                }
              }
          }
        }
