/**
* \brief CS2720A - Fall 2020 - Instructor: Dr. John Anvik
* Project Text Adventure Game
* Program Title: Inventory.h
* Program Purpose: Definition file for the Inventory Class
*
* \author Jordon Harris, Cassandra Olfert
* \function bodies by: Mackenzie Kure
* \date November 2020
*/

#ifndef INVENTORY_H
#define INVENTORY_H
/**
* \brief The Inventory Class contains and manages objects from the Item class.
*/

#include<iostream>
#include<vector>
#include "Item.h"

class Inventory {
 public:
   /**
   * Default Constructor
   */
    Inventory() {}

    /**
    * Destructor
    * deletes each Item* from inventory vector
    */
    ~Inventory();

    /**
    * Adds an item to the inventory vector
    * \param Item*
    */
    void addToInventory(Item*);

    /**
    * Get the size of the inventory vector, the number of Item*
    * \return int the size of the inventory vector
    */
    int sizeOfInventory();

    /**
    * Displays all items from the inventory vector
    * lists the items from the inventory for player
    */
    void listInventory();

    /**
    * Get the inventory vector as a whole
    * \return vector<Item*> inventory, the inventory vector
    */
    std::vector<Item*> getInventoryVector();

 private:
    std::vector<Item*> inventory;
};
#endif //INVENTORY_H
