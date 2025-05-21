/**
* \brief CS2720A - Fall 2020 - Instructor: Dr. John Anvik
* Project Text Adventure Game
* Program Title: Area.h
* Program Purpose: Definition file for the Area Class
*
* \author Jordon Harris, Mackenzie Kure, Cassandra Olfert
* \date October 28, November 9, November 20, 2020
*/

#ifndef AREA_H
#define AREA_H
/**
* \brief Area is an abstract base class for the derived Area Classes.
*/

#include <iostream>
#include <vector>
#include <string>
#include "Room.h"
#include "Coordinate.h"
#include "playerStat.h"

class Area {
 public:
   /**
   * Virtual destructor for Area
   * deletes vector<Room*> collectionOfRooms
   */
  virtual ~Area() {
    for (auto it : collectionOfRooms) {
      delete it;
    }
  }

  /**
  * Get the Room pointer of the room in the Area
  * \return vector<Room*> the pointer to a Room in the Area
  */
  std::vector<Room*> getRoomVector();

  /**
  * Get the vector of Room* belonging to an Area
  * \return the vector<Room*>* the rooms of the Area
  */
  std::vector<Room*>* getCollectionOfRooms();

  /**
  * Virtual Displays the description of the Area
  */
  virtual void printDescription() = 0;

  /**
  * Virtual Performs the trap check when the player enters a new Room
  */
  virtual bool trapCheck() = 0;

 protected:
    std::vector<Room*> collectionOfRooms;
    std::string inputString = "";
};

/**
* Area1 is derived from Area Class and implements an 'annoying trap' area
* with 3 Rooms
*/

class Area1 : public Area {
 public:
  /**
  * Constructor
  * \param PlayerStat* pStats, the pointer for the PlayerStat
  */
  Area1(PlayerStat* pStats);

  /**
  * Displays the description of Area1 for the player
  */
  void printDescription();

  /**
  * Performs the trap check when the player enters a new Room
  * Area1 traps are annoying traps, that will not kill the player
  */
  bool trapCheck();
};

/**
* Area2 is derived from Area Class and implements a 'broken trap' area
* with 3 Rooms
*/

class Area2 : public Area{
 public:
  /**
  * Constructor
  * \param PlayerStat* pStats, the pointer for the PlayerStat
  */
  Area2(PlayerStat* pStats);

  /**
  * Displays the description of Area3 for the player
  */
  void printDescription();

  /**
  * Performs the trap check when the player enters a new Room
  * Area2 traps are broken, and will not kill the player
  */
  bool trapCheck();
};

/**
* Area3 is derived from Area Class and implements a 'lethal trap' area
* with 3 Rooms
*/

class Area3 : public Area {
 public:
  /**
  * Constructor
  * \param PlayerStat* pStats, the pointer for the PlayerStat
  */
  Area3(PlayerStat* pStats);

  /**
  * Displays the description of Area3 for the player
  */
  void printDescription();

  /**
  * Performs the trap check when the player enters a new Room
  * Area3 traps are lethal traps, and will kill the player if they choose not
  * to avoid it
  */
  bool trapCheck();
};
#endif
