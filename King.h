/*Header file for King class

King class inherits from Piece class, and implements
virtual function canMove() to determine validity
of move according to game logic.

Constructor invokes base class Constructor and
passes along two bools to indicate color and
piece status(dead or alive).

*/


#ifndef KING_H
#define KING_H
#include "Piece.h"
#include "Board.h"
#include "Spot.h"

#include <cstdlib>



class King : public Piece
{

public:


//King class constructor calls base class Piece constructor
    King(bool white, bool killed) : Piece(white,killed){}

 /*
      Piece class virtual function canMove(): King child class implementation

      King can move one square in any direction, so longs as a Piece of the
      same color is not occupying it.

  */

     bool canMove(Board* game, Spot* start, Spot* ending)
    {
        cout << "hello from King a derived class" << endl ;


     //Returns false if Pieces at both spots are of the same color
        if(ending->getPiece() != nullptr)
           if(ending->getPiece()->isWhite() == start->getPiece()->isWhite())
                return false ;


        int x = abs(start->getX() - ending->getX()) ;
        int y = abs(start->getY() - ending->getY()) ;

        if( x + y == 1)
            return true ;
        else
            return false;



    }

    void printP()
    {

        if(white == true)
            cout << "KI " ;
        else
            cout << RED << "KI " << RESET  ;
    }

    // Destructor for King class
    ~King()
    {
        cout << " Deleting King" << endl ;
    }


};


#endif // KING_H
