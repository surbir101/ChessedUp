/* Header file for Bishop class

Bishop class inherits from Piece class, and implements
virtual function canMove() to determine validity
of move according to game logic.

Constructor invokes base class Constructor and
passes along two bools to indicate color and
piece status(dead or alive).

*/

#ifndef BISHOP_H
#define BISHOP_H
#include "Piece.h"
#include "Board.h"
#include "Spot.h"
#include <iostream>

//using namespace std;

class Bishop : public Piece
{

public:

//Bishop class constructor calls base class Piece constructor
    Bishop(bool white, bool killed) : Piece(white,killed){}



/*
   Piece class virtual function canMove(): Bishop child class implementation

   Bishop can move in any direction, as long as it is moving diagonally,
   and no Pieces are in its path

   Diagonal move can be confirmed by checking if, the x and y values
   of the start and end Spot changed by the same amount.

*/

    bool canMove(Board* board, Spot* start, Spot* ending)
    {
        cout << "hello from Bishop, a derived class" << endl ;

 //Returns false if Pieces at both spots are of the same color
       if(ending->getPiece() != nullptr)
            if(ending->getPiece()->isWhite() == start->getPiece()->isWhite())
                return false;

        //Calculate x and y differences between start and end Spots
        int x = abs(start->getX() - ending->getX()) ;
        int y = abs(start->getY() - ending->getY()) ;

        //Check if move is not diagonal
        if( x != y )
            return false ;

        //Now check the path of the move
        int i = 0 ; int j = 0 ;     // iterator variables

        if( start->getX() < ending->getX() )    // moving up the board diagonally
            {
                if( start->getY() < ending->getY() )    // diagonally right
                {
                    i = start->getX()+1 ; j = start->getY()+1 ;
                    while(board->boxes[i][j]->getPiece() == nullptr && i != ending->getX())
                    {
                        i = i+1 ;
                        j = j+1 ;
                    }

                    if( i == ending->getX() )
                        return true;
                    else
                        return false;
                }
                else // diagonally left
                {
                    i = start->getX()+1 ; j = start->getY()-1 ;
                    while(board->boxes[i][j]->getPiece() == nullptr && i != ending->getX())
                    {
                        i = i+1 ;
                        j = j-1 ;
                    }

                    if( i == ending->getX() )
                        return true;
                    else
                        return false;
                }

            }
        else // moving down diagonally
            {
                 if( start->getY() < ending->getY() ) // diagonally right
                 {
                     i = start->getX()-1 ; j = start->getY()+1 ;
                    while(board->boxes[i][j]->getPiece() == nullptr && i != ending->getX())
                    {
                        i = i-1 ;
                        j = j+1 ;
                    }

                    if( i == ending->getX() )
                        return true;
                    else
                        return false;

                 }
                 else // diagonally left
                 {
                     i = start->getX()-1 ; j = start->getY()-1 ;
                    while(board->boxes[i][j]->getPiece() == nullptr && i != ending->getX())
                    {
                        i = i-1 ;
                        j = j-1 ;
                    }

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
            cout << "Bi " ;
        else
            cout << RED << "Bi " << RESET  ;
    }


    //Destructor for Bishop class
    ~Bishop()
    {
        cout << " Deleting Bishop" << endl ;
    }




};




#endif // BISHOP_H
