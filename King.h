#ifndef KING_H
#define KING_H
#include "Piece.h"
#include "Board.h"
#include "Spot.h"

#include <cstdlib>




class King : public Piece
{

public:



    King(bool white, bool killed) : Piece(white,killed){}

     bool canMove(Board* game, Spot* start, Spot* ending)
    {
        cout << "hello from King a derived class" << endl ;

           // we can't move the piece to a Spot that
        // has a piece of the same color

        if(ending->getPiece() != nullptr)
        {
            if(ending->getPiece()->isWhite() == this->isWhite())
                return false ;
            else
            {
                int x = abs(start->getX() - ending->getX());
                int y = abs(start->getY() - ending->getY());
                if (x + y == 1)
                    return true;
                else
                    return false;
            }
        }
        else
        {
             int x = abs(start->getX() - ending->getX());
             int y = abs(start->getY() - ending->getY());
             if (x + y == 1)
                return true;
             else
                return false;

        }

    }

    void printP()
    {

        if(white == true)
            cout << "KI " ;
        else
            cout << RED << "KI " << RESET  ;
    }


};


#endif // KING_H
