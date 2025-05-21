/**
* \author Jordon Harris, Mackenzie Kure
* \date October 28, November 9, 2020
*/

#include <iostream>
#include <vector>
#include <utility>
#include "Item.h"
#include "Inventory.h"

    Inventory::~Inventory() {
      for (auto it : inventory) {
        delete it;
      }
    }

    void Inventory::addToInventory(Item* in) {
        inventory.push_back(in);
    }

    int Inventory::sizeOfInventory() {
        return inventory.size();
    }

    void Inventory::listInventory() {
      int n = 1;
      for (auto it : inventory) {
        std::cout << n++ << " " << it->getItemName() << std::endl;
      }
    }

    std::vector<Item*> Inventory::getInventoryVector() {
      return inventory;
    }
