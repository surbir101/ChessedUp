#ifndef BOARD_H
#define BOARD_H
#include "Spot.h"
#include "Piece.h"
#include<vector>
using namespace std;


class Board
{


public:

Spot boxes[8][8] ;   // Chess board, a 2D vector

Board() ;



};


#endif // BOARD_H
