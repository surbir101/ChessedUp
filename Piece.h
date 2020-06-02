/* Header File for Piece class:

  Constructor sets initial values for bool variables: killed & white
  indicating weather the piece is alive, and its color (white or black)

  Class includes setter and getter functions for bools, as well as two
  virtual functions canMove() returning a bool indicating weather piece
  can move there or not, based on game rules. As well as printP() which
  prints to screen piece type, used in printBoard() in board class.

  Virtual functions are implemented in inherited classes that represent
  the difference Chess Game Piece Types .


*/

#ifndef PIECE_H
#define PIECE_H                 // Below #defines used to print color to screen
#define BLACK   "\033[30m"      // color black
#define RED     "\033[31m"      // color red
#define RESET   "\033[0m"       // color reset
#include "Board.h"
#include "Spot.h"
#include <iostream>
#include<cstdlib>

using namespace std;

// Forward declaration of Board and Spot classes used in Piece
class Board ;
class Spot ;

//Piece class declaration
class Piece {

protected:

    bool killed ;       // true = piece alive  false = piece killed
    bool white ;        // true = color white  false = color black

public:

//default constructor
    Piece(){killed = false;white = false;}

//constructor
    Piece(bool,bool) ;

//virtual destructor
    virtual ~Piece() = 0 ;

//setters and getters
    void setWhite(bool);
    bool isWhite();


    void setKilled(bool) ;
    bool isKilled() ;


// virtual function implemented specific to each Piece type, determines if move is valid or not
    virtual bool canMove(Board*, Spot*, Spot*) = 0;


//virtual function implemented specific to each Piece type, prints to screen Piece type & color
//only used in Board class to print entire Board to screen after each Player move
    virtual void printP() = 0 ;




};


#endif // PIECE_H
