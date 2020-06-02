/* Header file for Board class

    2D 8x8 array of Spots to represent Chess Board
    Constructor initializes board by:
        Dynamically allocating new Spots with appropriate x,y coordinates and
        Dynamically allocating new Piece of appropriate type at relevant Spots

    printBoard is used to print to screen the state of the Board before and after
    each move.

*/

#ifndef BOARD_H
#define BOARD_H
#include "Spot.h"
#include "Piece.h"

using namespace std;

//Forward declaration
class Spot;

//Board class declaration
class Board
{

public:

Spot* boxes[8][8] ;   // Chess board, a 2D vector

//Constructor
Board() ;

//Prints board to screen
void printBoard() ;

//Destructor
~Board() ;


};


#endif // BOARD_H
