/**
* \author Jordon Harris
* \date November 12, 2020
*/

#include<iostream>
#include<string>
#include "Coordinate.h"
#include"Inventory.h"
#include"playerStat.h"

    void PlayerStat::setLocation(Coordinate* coord) {
      this->location = coord;
    }

    Coordinate* PlayerStat::getLocation() {
      return this->location;
    }

    void PlayerStat::setIsDead(bool d) {
      this->isDead = d;
    }

    bool PlayerStat::getIsDead() {
      return this->isDead;
    }

    void PlayerStat::setWornClothing(int wc) {
      this->wornClothing = wc;
    }

    int PlayerStat::getWornClothing() {
      return this-> wornClothing;
    }

    Inventory* PlayerStat::getWardrobe() {
      return this->wardrobe;
    }

    int PlayerStat::getSolvedPuzzleCount() {
      return solvedPuzzleCount;
    }

    void PlayerStat::incrementSolvedPuzzleCount() {
      solvedPuzzleCount++;
    }
