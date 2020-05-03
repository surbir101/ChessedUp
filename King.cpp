/*

#include "Piece.h"
#include "King.h"
#include "Board.h"
#include "Spot.h"
#include <iostream>
#include <cstdlib>


bool King::canMove(Board* game, Spot* start, *Spot ending)
{

     // we can't move the piece to a Spot that
        // has a piece of the same color
        if (ending->getPiece()->isWhite() == this->isWhite()) {
            return false;
        }

        int x = abs(start->getX() - ending->getX());
        int y = abs(start->getY() - ending->getY());
        if (x + y == 1) {
            // check if this move will not result in the king
            // being attacked if so return true
            return true;
        }
        else
            return false;



}
*/
