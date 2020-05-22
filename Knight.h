#ifndef KNIGHT_H
#define KNIGHT_H
#include "Piece.h"
#include "Board.h"
#include "Spot.h"
#include <iostream>
#include <cstdlib>
using namespace std;



class Knight : public Piece
{

public:

    Knight(bool white, bool killed) : Piece(white,killed){}

     bool canMove(Board* board, Spot* start, Spot* ending)
    {
            cout << "hello from knight a derived class" << endl ;

        if(ending->getPiece() != nullptr)
           if(ending->getPiece()->isWhite() == start->getPiece()->isWhite())
                return false ;

        if(abs(start->getX() - ending->getX()) == 2 )
        {
            if(abs(start->getY() - ending->getY()) == 1)
                return true;
            else
                return false;

        }
        else if(abs(start->getX() - ending->getX()) == 1)
        {
            if(abs(start->getY() - ending->getY()) == 2)
                return true;
            else
                return false;

        }
        else
            return false;

    }

        void printP()
    {
        if(white == true)
            cout << "Kn " ;
        else
            cout << RED << "Kn " << RESET  ;
    }


};




#endif // KNIGHT_H
