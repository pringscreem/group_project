/**
* \author Dr. Anvik <john.anvik@uleth.ca>, LN Wilson <n.wilson@uleth.ca>
* \author Mackenzie Kure, Cassandra Olfert
* \date 2018-09, 2018-10, 2018-11, 2020-11
*/

#ifndef EXCEPTIONS_H_INCLUDED
#define EXCEPTIONS_H_INCLUDED

/**
* \brief The Exceptions class provides error checking and displays information
* to the user about the exception
*/

#include <stdexcept>

/**
* Exception when a nullptr is passed as a valid coordinate.
*/
class invalid_coordinate: public std::runtime_error {
 public:
   /**
   * \param errMessage An error message.
   */
  explicit invalid_coordinate(const char* errMessage) :
    std::runtime_error(errMessage) {
  }
};

/**
* Exception if the x coordinate is set to be greater or less than the range
*/
class x_is_out_of_range_error: public std::runtime_error {
 public:
   /**
   * \param errMessage An error message.
   */
  explicit x_is_out_of_range_error(const char* errMessage) :
    std::runtime_error(errMessage) {
  }
};

/**
* Exception if the y coordinate is set to be greater or less than the range
*/
class y_is_out_of_range_error: public std::runtime_error {
 public:
   /**
   * \param errMessage An error message.
   */
  explicit y_is_out_of_range_error(const char* errMessage) :
    std::runtime_error(errMessage) {
  }
};

/**
* Exception if the user input is not valid
*/
class invalid_input: public std::runtime_error {
 public:
   /**
   * \param errMessage An error message.
   */
  explicit invalid_input(const char* errMessage) :
    std::runtime_error(errMessage) {
  }
};

#endif  // EXCEPTIONS_H_INCLUDED
