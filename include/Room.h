/**
* \brief CS2720A - Fall 2020 - Instructor: Dr. John Anvik
* Project Text Adventure Game
* Program Title: Room.h
* Program Purpose: Definition file for the Room Class
*
* \author Jordon Harris, Cassandra Olfert
* \function bodies Mackenzie Kure, Cassandra Olfert
* \Bug fixes Scott Sonnleitner
* \date October 28 - November 2020
*/

#ifndef ROOM_H
#define ROOM_H

/**
* \brief Room is an abstract base class for the derived Room Classes.
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "Inventory.h"
#include "Item.h"
#include "Coordinate.h"
#include "playerStat.h"

class Room {
 public:
   /**
   * Virtual destructor for Room
   * deletes map<std::string, Coordinate*> doors, Inventory* in, and
   * Coordinate* coord
   */
  virtual ~Room() {
     for (auto it : doors) {
       delete it.second;
     }
     delete in;
     delete coord;
  }

/**
* Virtual Get the Coordinate of the Room
* \return Coordinate* coord, the Room's Coordinate*
*/
Coordinate* getCoord();

/**
* Virtual Get the Inventory of the Room
* \return Inventory* in, the Room's Inventory*
*/
Inventory* getInventory();

/**
* Virtual Get the private variables for playerStat, used to update the player
* \return PlayerStat* stats, the playerStat* of the player
*/
PlayerStat* getStats();

/**
* Lists the doors in doors vector
*/
void listDoors();

/**
* Allows the player to change clothes
*/
void changeClothes();

/**
* Checks that the door selected is available in the given Room
* \param string s, the user input for the door they chose
* \return bool, whether the chosen door is in the list, false otherwise
*/
bool checkDoorInput(std::string s);

/**
* Help function for user, outputs commands helpful to player
*/
bool help();

/**
* Checks to see if the object has already been added to the user's wardrobe
* \param Item* obj the object to check
* \return bool, true if the obj already exists in the player's wardrobe, false
* otherwise
*/
bool checkWardrobe(Item* obj);

/**
* Runs the interaction for the puzzle, NPC, or Object selected by the user
* \param Item* itm, the item to run the interaction on
*/
void runInteraction(Item* itm);

/**
* Checks if the puzzle has been previously completed
* \return bool, true if the puzzle has been completed, false if not
*/
bool puzzleCompletedCheck();

/**
* provides the implementation necessary for the user to change rooms, by
* selecting a door and changing the playerStat coordinate.
*/
void doorSelection();

/**
* provides the implementation necessary for the user to select a choice from the
* room's Inventory
* \return int, selection choice.
*/
int inventorySelection(int, int);

/**
* Runs the Room loop - the player interacts with objects, NPC's and
* puzzles. Updates playerStat throughout.
*/
void runRoom();

/**
* Virtual Prints the description of the Room
*/
virtual void printDescription() = 0;

/**
* Virtual Check which clothes the player is wearing, correct according to
* Room type
*/
virtual bool checkClothes() = 0;

/**
* Virtual Assigns door coordinates for the chosen room, how to change rooms
*/
virtual std::map<std::string, Coordinate*> assignDoorCoords() = 0;

/**
* Virtual Creates the inventory with Item's for the Room
*/
virtual Inventory* assignInventory(int coord) = 0;

/**
* Virtual Creates the Coordinate of the Room
*/
virtual Coordinate* assignCoordinate(int coord) = 0;

 protected:
  Coordinate* coord;
  Inventory* in;
  PlayerStat* stats;
  int userInput = 0;
  std::string inputString = "";
  std::map<std::string, Coordinate*> doors;
  bool stayInRoom = true;
  bool puzzleCompleted = false;
};

/**
* \brief NormalRoom is derived from Room Class and implements a room with normal
* characteristics.
*/

class NormalRoom : public Room {
 public:
    /**
    * Default Constructor
    * Sets coord, in, and stats to nullptr
    */
    NormalRoom();

    /**
    * NormalRoom Constructor
    * Sets coord, in, and stats to supplied variables
    * Sets doors for the Room (how to travel to other Rooms)
    */
    NormalRoom(int yCoordinate, PlayerStat* ps);

    /**
    * Creates the inventory ptr for the room
    * \param int coord, depending on value creates the specified items for
    * the room's inventory
    * \return Inventory* the room's new inventory with Items
    */
    Inventory* assignInventory(int coord);

    /**
    * Creates the coordinate ptr for the room
    * \param int coord, depending on the value creates the specified coordinate
    * \return Coordinate* the room's new coordinate
    */
    Coordinate* assignCoordinate(int coord);

    /**
    * Adds the correct 'door' coordinates for the room
    * Depending on this room's coordinates the 'connected' rooms'
    * Coordinate's (the doors) are added
    */
    std::map<std::string, Coordinate*> assignDoorCoords();

    /**
    * Checks the player's current clothes, must be "normal clothes" option
    * to survive in the NormalRoom
    * \return bool whether player is wearing correct clothes or not
    */
    bool checkClothes();

    /**
    * Displays the description of the room for the player
    */
    void printDescription();
};

/**
* \brief HotRoom is derived from Room Class and implements a room with hot
* characteristics.
*/

class HotRoom : public Room {
 public:
  /**
  * Default Constructor
  * Sets coord, in, and stats to nullptr
  */
  HotRoom();

  /**
  * HotRoom Constructor
  * Sets coord, in, and stats to supplied variables
  * Sets doors for the Room (how to travel to other Rooms)
  */
  HotRoom(int yCoordinate, PlayerStat* ps);

  /**
  * Creates the inventory ptr for the room
  * \param int coord, depending on value creates the specified items for
  * the room's inventory
  * \return Inventory* the room's new inventory with Items
  */
  Inventory* assignInventory(int coord);

  /**
  * Creates the coordinate ptr for the room
  * \param int coord, depending on the value creates the specified coordinate
  * \return Coordinate* the room's new coordinate
  */
  Coordinate* assignCoordinate(int coord);

  /**
  * Adds the correct 'door' coordinates for the room
  * Dependinf on this room's coordinates the 'connected' rooms'
  * Coordinate's (the doors) are added
  */
  std::map<std::string, Coordinate*> assignDoorCoords();

  /**
  * Checks the player's current clothes, must be "hot clothes" option
  * to survive in the HotRoom
  * \return bool whether player is wearing correct clothes or not
  */
  bool checkClothes();

  /**
  * Displays the description of the room for the player
  */
  void printDescription();
};

/**
* \brief ColdRoom is derived from Room Class and implements a room with cold
* characteristics.
*/

class ColdRoom : public Room {
 public:
  /**
  * Default Constructor
  * Sets coord, in, and stats to nullptr
  */
  ColdRoom();

  /**
  * HotRoom Constructor
  * Sets coord, in, and stats to supplied variables
  * Sets doors for the Room (how to travel to other Rooms)
  */
  ColdRoom(int yCoordinate, PlayerStat* ps);

  /**
  * Creates the inventory ptr for the room
  * \param int coord, depending on value creates the specified items for
  * the room's inventory
  * \return Inventory* the room's new inventory with Items
  */
  Inventory* assignInventory(int coord);

  /**
  * Creates the coordinate ptr for the room
  * \param int coord, depending on the value creates the specified coordinate
  * \return Coordinate* the room's new coordinate
  */
  Coordinate* assignCoordinate(int coord);

  /**
  * Adds the correct 'door' coordinates for the room
  * Dependinf on this room's coordinates the 'connected' rooms'
  * Coordinate's (the doors) are added
  */
  std::map<std::string, Coordinate*> assignDoorCoords();

  /**
  * Checks the player's current clothes, must be "cold clothes" option
  * to survive in the ColdRoom
  * \return bool whether player is wearing correct clothes or not
  */
  bool checkClothes();

  /**
  * Displays the description of the room for the player
  */
  void printDescription();
};
#endif
