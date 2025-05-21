/**
* \brief CS2720A - Fall 2020 - Instructor: Dr. John Anvik
* Project Text Adventure Game
* Program Title: Coordinate.h
* Program Purpose: Definition file for the Coordinate Class
*
* \author Jordon Harris, Mackenzie Kure, Cassandra Olfert
* \date November 9, November 18, 2020
*/

#ifndef COORDINATE_H
#define COORDINATE_H

/**
* \brief The Coordinate Class is a simple class that contains x,y
* coordinates. It can be placed in any class that needs to know its
* location.
*/

#include <iostream>

class Coordinate {
 public:
    /**
    * Default Constructor
    * Sets the xCoord and yCoord to 0
    */
    Coordinate() : xCoord{0}, yCoord{0} {}

    /**
    * Constructor
    * Sets the xCoord and yCoord to supplied inputs incX, incY
    * \param int incX, the new x coordinate
    * \param int incY, the new y coordinate
    */
    Coordinate(int incX,  int incY) : xCoord{incX}, yCoord{incY} {}

    /**
    * Destructor
    */
    ~Coordinate() {}

    /**
    * Get the x coordinate value
    * \return int xCoord for the location
    */
    int getX();

    /**
    * Get the y coordinate value
    * \return int yCoord for the location
    */
    int getY();

    /**
    * Sets the coordinate with supplied input incomingX and incomingY
    * \param int incomingX, int incomingY the coordinates
    * \throw x_is_out_of_range_error when values above 2 are below 0 entered
    * \throw y_is_out_of_range_error when values above 2 are below 0 entered
    */
    void setCoordinate(int incomingX, int incomingY);

    /**
    * Get the coordinate
    * \return Coordinate* of object
    */
    Coordinate* getCoordinate();

    /**
    * Operator== returns true if the x and y coordinate values of the provided
    * Coordinate object equals those of this one
    * \return true or false bool
    */
    bool operator==(const Coordinate& c) const {
        return ((xCoord == c.xCoord) && (yCoord == c.yCoord));
      }

 private:
    int xCoord = 0;
    int yCoord = 0;
};
#endif
