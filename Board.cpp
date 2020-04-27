#include <iostream>
#include <string>
#include "Piece.h"
#include "Spot.h"
#include "King.h"
#include "Board.h"
#include <vector>
using namespace std;


Board::Board()
{
    cout << "Chess Board Empty but ready" ;
     boxes[0][0].setAll(0,0,new King(true,false)) ;



}
