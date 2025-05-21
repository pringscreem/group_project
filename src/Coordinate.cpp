/**
* \author Jordon Harris, Mackenzie Kure, Scott Sonnleitner
* \date October 28, November 9, November 10, 2020
*/

#include <iostream>
#include "Coordinate.h"
#include "Exceptions.h"

    int Coordinate::getX() {
      return xCoord;
    }

    int Coordinate::getY() {
      return yCoord;
    }

    void Coordinate::setCoordinate(int incomingX, int incomingY) {
      if (incomingX > 2 || incomingX < 0) {
        throw x_is_out_of_range_error("x is out of range");
      } else if (incomingY > 2 || incomingY < 0) {
          throw y_is_out_of_range_error("y is out of range");
        } else {
          xCoord = incomingX;
          yCoord = incomingY;
        }
    }

    Coordinate* Coordinate::getCoordinate() {
      return this;
    }
