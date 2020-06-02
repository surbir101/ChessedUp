/* Header file for Spot class

A Spot represents a position on a Chess board (1 square on 8x8 standard Chess Board).

Holds an X and Y integer for its coordinate position, and a
Piece* ptr to represent a Piece at that position or nullptr for empty Spot (no piece there).

Each Spot is created once by the Board class when initializing Board.
    2D 8x8 Spot array = Board object
    new Spot(x,y,Piece) called by board class to setup Board

*/

#ifndef SPOT_H
#define SPOT_H
#include "Piece.h"


//Forward declaration
class Piece ;

//Spot class declaration
class Spot
{

public:

    Piece *piece ;  // indicates whether this Spot on the Chess Board has a piece on it or not
    int x ;         // x coordinate of this Spot in 8x8 Spot array(Board)
    int y;          // y coordinate of this Spot in 8x8 Spot array(Board)

//default constructor
    Spot() ;

//Constructor initializes Spot with (x,y) position indicating position on Chess Board,
//and if first or last 2 rows places relevant Piece for board initialization.
    Spot(int, int, Piece *) ;

// setter & getter for placing and retrieving Piece
    void setPiece(Piece *) ;
    Piece* getPiece() ;

// setter & getter for x coordinate
    void setX(int) ;
    void setY(int) ;

// setter & getter for y coordinate
    int getX();
    int getY();

// function to change all variables in object in one call
    void setAll(int, int, Piece*) ;

//Destructor
~Spot() ;

};







#endif // SPOT_H
