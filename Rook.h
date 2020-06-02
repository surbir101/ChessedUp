/* Header file for Rook class

Rook class inherits from Piece class, and implements
virtual function canMove() to determine validity
of move according to game logic.

Constructor invokes base class Constructor and
passes along two bools to indicate color and
piece status(dead or alive).

*/

#ifndef ROOK_H
#define ROOK_H
#include "Piece.h"
#include "Board.h"
#include "Spot.h"
#include <iostream>
using namespace std;



class Rook : public Piece
{

public:

//Rook class constructor calls base class Piece constructor
    Rook(bool white, bool killed) : Piece(white,killed){}

/*
    Piece class virtual function canMove(): Rook child class implementation


    Rook can move in 4 directions: forward,backward,left,right
    therefor there should only be a change in either the
    X or Y coordinates between the start and end Spot, but not both.

    If this checks out we must check the path to the end Spot to
    ensure there are no pieces in the way because this Piece cannot jump.

    If there is a piece at the end Spot and it is not of the same color
    as the piece at the start Spot we return true, because we kill it
    and take its position. Else if the Pieces are of same color return false.

*/
      bool canMove(Board* board, Spot* start, Spot* ending)
    {
        cout << "hello from Rook, a derived class" << endl ;

    //Returns false if Pieces at both spots are of the same color
       if(ending->getPiece() != nullptr)
            if(ending->getPiece()->isWhite() == start->getPiece()->isWhite())
                return false;

    //Determine if the move is a valid direction
        int x = abs(start->getX() - ending->getX()) ;
        int y = abs(start->getY() - ending->getY()) ;

    // If either the x or the y values between the start and end Spots are not the same, move is not valid
        if( x != 0 && y != 0 )
            return false ;

    //Now to see if path to end spot is clear of pieces in the way

    int i = 0 ; // to check next spot in path
    if( x == 0 ) //movement is left or right
    {

        if( start->getY() < ending->getY() ) //movement is right
        {

            i = start->getY() +1 ; // spot next in path
            while( board->boxes[start->getX()][i]->getPiece() == nullptr && i != ending->getY() )
            {
                i = i + 1 ; //increment i to next spot in path
            }

            //if i reaches end we know path is clear
            if( i == ending->getY())
                return true;
            else
                return false;


        }
        else //movement is left
        {
             i = start->getY() -1 ; // spot next in path
            while( board->boxes[start->getX()][i]->getPiece() == nullptr && i != ending->getY() )
            {
                i = i - 1 ; //increment i to next spot in path
            }

            //if i reaches end we know path is clear
            if( i == ending->getY())
                return true;
            else
                return false;


        }

    }
    else //movement is up or down
    {
        if( start->getX() < ending->getX() ) // movement is up the board
        {
            i = start->getX() + 1 ; //next spot in path
            while(board->boxes[i][start->getY()]->getPiece() == nullptr && i != ending->getX())
            {
                i = i+1 ; //increment i to next spot in path
            }

            //if i reaches end we know path is clear
            if( i == ending->getX() )
                return true;
            else
                return false;



        }
        else //movement is down the board
        {
            i = start->getX() - 1 ; //next spot in path
            while(board->boxes[i][start->getY()]->getPiece() == nullptr && i != ending->getX())
            {
                i = i - 1 ; //increment i to next spot in path
            }

            //if i reaches end we know path is clear
            if( i == ending->getX() )
                return true;
            else
                return false;

        }


    }
    }

        void printP()
    {
        if(white == true)
            cout << "Ro " ;
        else
            cout << RED << "Ro " << RESET  ;
    }


//Destructor for Rook class
    ~Rook()
    {
        cout << " Deleting Rook" << endl ;
    }


};





#endif // ROOK_H
