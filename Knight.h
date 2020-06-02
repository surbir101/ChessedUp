/*Header file for Knight class

Knight class inherits from Piece class, and implements
virtual function canMove() to determine validity
of move according to game logic.

Constructor invokes base class Constructor and
passes along two bools to indicate color and
piece status(dead or alive).

*/

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

//Knight class constructor calls base class Piece constructor
    Knight(bool white, bool killed) : Piece(white,killed){}


/*
    Piece class virtual function canMove(): Knight child class implementation

    Knight can move in any direction but it must be in a L shape, and the
    L will consist of 2 moves along one plane of axis (refers to x or y axis),
    and 1 along the other plane.

    Knight can "jump" over pieces so we do not need to check the path.
    Only check if the ending Spot has a same color Piece, in which
    case return false.


 */

     bool canMove(Board* board, Spot* start, Spot* ending)
    {
            cout << "hello from knight a derived class" << endl ;

     //Returns false if Pieces at both spots are of the same color
        if(ending->getPiece() != nullptr)
           if(ending->getPiece()->isWhite() == start->getPiece()->isWhite())
                return false ;

    // take difference between X and Y coordinates of Start and End Spots
        int x = abs(start->getX() - ending->getX()) ;
        int y = abs(start->getY() - ending->getY()) ;

    /*
        Start and End spot X and Y coordinates must differ by either 1 or 2.
        If the X coordinates differ by 1 the Y's must differ by 2
        If the X coordinates differ by 2 the Y's must differ by 1
        Otherwise return false .

    */
        if( x == 2)
        {
            if( y == 1)
                return true;
            else
                return false;
        }
        else if( x == 1)
        {
            if( y == 2)
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


    // Destructor for Knight class
    ~Knight()
    {
        cout << " Deleting Knight" << endl ;
    }


};




#endif // KNIGHT_H
