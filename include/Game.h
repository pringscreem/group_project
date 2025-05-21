/**
* \brief CS2720A - Fall 2020 - Instructor: Dr. John Anvik
* Project Text Adventure Game
* Program Title: Game.h
* Program Purpose: Definition file for the Game Class
*
* \author Jordon Harris, Cassandra Olfert, Mackenzie Kure
* \date October 28 - November 2020
*/

#ifndef GAME_H
#define GAME_H

/**
* \brief The Game class maintains control of the game from creation to game over.
*/

#include <iostream>
#include <vector>
#include <string>
#include "Area.h"
#include "Room.h"
#include "playerStat.h"

class Game {
 public:
   /**
   * Default Constructor
   */
    Game();

    /**
    * Destructor
    * deletes vector<Area*> collectionOfAreas, PlayerStat* p1Stats,
    * Area* currentArea and Room* currentRoom
    */
    ~Game();

    /**
    * Displays the welcome message for player
    */
    void openingMessage();

    /**
    * Ends the game, player has either won or lost, displays message to user
    */
    void endGame();

    /**
    * Updates the conditions which indicate the end of the game
    */
    void updateEndConditions();

    /**
    * Runs the game
    */
    void runGame();

    /**
    * updates the currentArea and currentRoom location for the game to run
    */
    void updateLocation();

 private:
    bool gameIsOver = false;
    std::vector<Area*> collectionOfAreas;
    std::string userInput;
    bool isPositiveOutcome;
    bool isDead = false;
    bool gameIsWon = false;
    Area* currentArea = nullptr;
    Room* currentRoom = nullptr;
    PlayerStat* p1Stats = nullptr;
};
#endif
