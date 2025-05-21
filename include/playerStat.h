/**
* \brief CS2720A - Fall 2020 - Instructor: Dr. John Anvik
* Project Text Adventure Game
* Program Title: playerStat.h
* Program Purpose: Definition file for the PlayerStat Class
*
* \author Jordon Harris, Cassandra Olfert, Mackenzie Kure
* \date November 12, November 18, 2020
*/

#ifndef PLAYERSTAT_H
#define PLAYERSTAT_H

/**
* \brief The PlayerStat Class is a simple class that contains basic player
* information. It can be placed in any class that needs this information.
*/

#include <iostream>
#include <string>
#include "Coordinate.h"
#include "Inventory.h"
#include "Item.h"

class PlayerStat {
 public:
   /**
   * Default Constructor
   * Sets the location and wardrobe to nullptr, playerName to empty string,
   * wornClothing to 0, and isDead to false.
   */
    PlayerStat() : location{nullptr}, wardrobe{nullptr},
                    wornClothing{0}, isDead{false} {}
    /**
    * Constructor
    * Sets the location, wardrobe, playerName, wornClothing, and isDead to
    * supplied inputs
    * \param Coordinate* l, Inventory* w, string pn, int wc, bool id
    */
    PlayerStat(Coordinate* l,  Inventory* w, int wc, bool id) {
      location = l;
      wardrobe = w;
      wornClothing = wc;
      isDead = id;
    }

     /**
     * Destructor
     * deletes location and wardrobe variables
     */
    ~PlayerStat() {
      delete wardrobe;
      delete location;
    }

    /**
    * Sets the player's location
    * \param Coordinate* coord the Coordinate* for player location
    */
    void setLocation(Coordinate* coord);

    /**
    * Get the player's location
    * \return the pointer location for player location
    */
    Coordinate* getLocation();

    /**
    * Sets the player's life status, whether dead or not
    * \param bool d
    */
    void setIsDead(bool d);

    /**
    * Get the player's life status , whether dead or not
    * \return bool isDead
    */
    bool getIsDead();

    /**
    * Sets the player's current clothes
    * \param int c the clothing
    */
    void setWornClothing(int wc);

    /**
    * Get the player's current clothes
    * \return int wornClothing the clothing
    */
    int getWornClothing();

    /**
    * Get the player's wardrobe
    * \return Inventory* wardrobe the player's items of clothing
    */
    Inventory* getWardrobe();

    /**
    * Get the number of solvedPuzzleCount
    * \return solvedPuzzleCount
    */
    int getSolvedPuzzleCount();

    /**
    * Increment the solvedPuzzleCount by one, when player completes a puzzle
    */
    void incrementSolvedPuzzleCount();

 private:
    Coordinate* location;
    Inventory* wardrobe;
    int wornClothing;
    bool isDead;
    int solvedPuzzleCount = 0;
};
#endif
