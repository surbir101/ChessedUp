#ifndef BOARD_H
#define BOARD_H
#include "Spot.h"
#include "Piece.h"

using namespace std;


class Spot;
class Board
{


public:

Spot* boxes[8][8] ;   // Chess board, a 2D vector

Board() ;
//~Board() ;

void printBoard() ;


};


#endif // BOARD_H
