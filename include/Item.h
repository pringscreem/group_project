/**
* \brief CS2720A - Fall 2020 - Instructor: Dr. John Anvik
* Project Text Adventure Game
* Program Title: Item.h
* Program Purpose: Definition file for the Item Class
*
* \author Jordon Harris, Cassandra Olfert, Mackenzie Kure
* \date November 2020
*/

#ifndef ITEM_H
#define ITEM_H

/**
* \brief Item is an abstract base class for the derived Item Classes.
*/

#include<iostream>
#include<string>
#include<vector>

class Item {
 public:
   /**
   * Destructor
   */
    virtual ~Item() {}

    /**
    * Allows the Player to interact with an Item
    */
    virtual void interaction() = 0;

    /**
    * Sets whether the player completes this interaction or not
    * \param bool result the condition if interaction completed or not
    */
     void setIsCompleted(bool result);

     /**
     * Get whether or not the player has completed this interaction
     * \return bool isCompleted the condition if interaction completed or not
     */
     bool getIsCompleted();

     /**
     * Sets the description for this Item
     * \param string incDescription the description of the Item
     */
     void setDescription(std::string incDescription);

     /**
     * Get the string description for this Item
     * \return string description the description of the Item
     */
     std::string getDescription();

     /**
     * Sets the name for this Item
     * \param string iName the name of the Item
     */
     void setItemName(std::string iName);

     /**
     * Get the name for this Item
     * \return string itemName the name of the Item
     */
     std::string getItemName();

     /**
     * Sets isPuzzle true if the Item is a puzzle
     * \param bool, true if Item is a puzzle
     */
     void setIsPuzzle(bool);

     /**
     * Gets whether the item is a puzzle or not
     * \return bool isPuzzle, true if Item is a puzzle
     */
     bool getIsPuzzle();

 protected:
    std::string description;
    std::string itemName;
    std::string inputString = "";
    bool isCompleted;
    bool isPuzzle;
};

/**
* \brief NPC is derived from Item Class and represents and implements NPC
* characters.
*/

class NPC  : public Item {
 public:
   /**
   * Default Constructor
   * Sets description, itemName, and message to empty strings
   * Sets isCompleted to false
   */
    NPC();

    /**
    * Constructor
    * Sets description, itemName, and message to supplied variables
    * Sets isCompleted to false
    * \param string desc, itm, m the description, name and message
    */
    NPC(std::string desc, std::string itm, std::string m);

    /**
    * Destructor
    */
    ~NPC() {}

    /**
    * Allows the player to interact with the NPC
    * Player receives a message or hint from the NPC
    * isCompleted is set to true
    */
     void interaction();

    /**
    * Sets the message that the NPC will give to the player
    * \param string m the message
    */
     void setMessage(std::string m);

     /**
     * Get the message that the NPC will give to the player
     * \return string message the message
     */
     std::string getMessage();

 private:
    std::string message;
};

/**
* \brief Object is derived from Item Class and represents and implements
* objects.
*/

class Object  : public Item {
 public:
   /**
   * Default Constructor
   * Sets description and itemName to empty strings
   * Sets isCompleted to false
   */
    Object();

    /**
    * Constructor
    * Sets description and itemName to supplied variables
    * Sets isCompleted to false
    * \param string desc, itm the description and name
    */
    Object(std::string desc, std::string itm);

    /**
    * Destructor
    */
    ~Object() {}

    /**
    * Allows the player to interact with the object
    * Player receives the name and description of the object
    * isCompleted is set to true if the player chooses to take the object
    */
    void interaction();
};

/**
* \brief Puzzles is derived from Item Class and is an abstract base class.
* This class implements different puzzles for the player to solve
*/

class Puzzles : public Item {
 public:
   /**
   * Destructor
   */
    virtual ~Puzzles() {}
};

/**
* \brief PuzzleA is derived from the Puzzles Class and implements the binary
* math puzzle.
*/

class PuzzleA  : public Puzzles {
 public:
   /**
   * Default Constructor
   * Sets description and itemName to empty strings
   * Sets isCompleted to false
   */
    PuzzleA();

    /**
    * Constructor
    * Sets description and itemName to supplied variables
    * Sets isCompleted to false
    * \param string desc, itm the description and name
    */
    PuzzleA(std::string desc, std::string itm);

    /**
    * Destructor
    */
    ~PuzzleA() {}

    /**
    * Allows the player to interact with the puzzle - try to solve it
    * Player is given a prompt to "solve the binary math equation, or die"
    * isCompleted is set to true if the player solves the equation
    */
    void interaction();

    /**
    * Initializes the list of 5 questions for the binary math puzzle
    */
    void creatingQuestions();

        struct Question {
          std::string question;
          std::string answer;
        };

 private:
  std::vector<Question> listOfQuestions;
  // The chosen question number
  int questionNum = 0;
  // Number of questions
  int numOfQuestions = 0;
};

/**
* \brief PuzzleB is derived from the Puzzles Class and implements the
* "single move tic tac toe" puzzle.
*/

class PuzzleB  : public Puzzles {
 public:
  /**
  * Default Constructor
  * Sets description and itemName to empty strings
  * Sets isCompleted to false
  */
  PuzzleB();

  /**
  * Constructor
  * Sets description and itemName to supplied variables
  * Sets isCompleted to false
  * \param string desc, itm the description and name
  */
  PuzzleB(std::string desc, std::string itm);

  /**
  * Destructor
  */
  ~PuzzleB() {}

  /**
  * Allows the player to interact with the puzzle - try to solve it
  * Player is given a prompt for solving the tic tac toe by placing the X to win
  * isCompleted is set to true if the player solves the puzzle
  */
  void interaction();

  /**
  * Randomly chooses which question to ask and returns that number
  * \return int questionNumber
  */
  int chooseQuestionNumber();

  /**
  * Sets up the board for the chosen question
  * \param int questionNumber
  */
  void setupBoard(int questionNumber);

  /**
  * Prints the board to the console for the chosen question
  */
  void printBoard();

  /**
  * Gets the player's answer and sets the variables for checking
  */
  void getInput();

  /**
  * Check if the player's answer is correct or not
  * \param int inputRow, inputColumn the player's answer
  * \return bool whether player was correct or not
  */
  bool checkAnswer(int inputRow, int inputColumn);

 private:
     // Row 1
     char x1y1, x2y1, x3y1;
     // Row 2
     char x1y2, x2y2, x3y2;
     // Row 3
     char x1y3, x2y3, x3y3;
     // Correct answer
     int correctRow;
     int correctColumn;
     // User input
     int inputRow;
     int inputColumn;
     // The chosen question number
     int questionNumber = 1;
     // Number of questions
     int numOfQuestions = 3;
};

/**
* \brief PuzzleC is derived from the Puzzles Class and implements the
* keycode puzzle.
*/

class PuzzleC  : public Puzzles {
 public:
    /**
    * Default Constructor
    * Sets description and itemName to empty strings
    * Sets isCompleted to false
    */
    PuzzleC();

    /**
    * Constructor
    * Sets description and itemName to supplied variables
    * Sets isCompleted to false
    * \param string desc, itm the description and name
    */
    PuzzleC(std::string desc, std::string itm);

    /**
    * Destructor
    */
    ~PuzzleC() {}

    /**
    * Allows the player to interact with the puzzle - try to solve it
    * Player is given a prompt to "enter the code, or die"
    * isCompleted is set to true if the player enters the correct code
    */
     void interaction();

 private:
  std::string code = "2319";
};
#endif //Item_H
