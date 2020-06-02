/*Header file for Pawn class

Pawn class inherits from Piece class, and implements
virtual function canMove() to determine validity
of move according to game logic.

Constructor invokes base class Constructor and
passes along two bools to indicate color and
piece status(dead or alive).

*/

#ifndef PAWN_H
#define PAWN_H
#include "Piece.h"
#include "Board.h"
#include "Spot.h"



class Pawn : public Piece
{

public:

//Pawn class constructor calls base class Piece constructor
    Pawn(bool white, bool killed) : Piece(white,killed){}


/*
    Piece class virtual function canMove(): Pawn child class implementation

    Pawn has 2 exceptions but in general can only move forward 1 square

    On its first turn it has the option to move forward 2 squares.

    Can move one square forward diagonally left or right to kill,
    but only if an opposing teams piece is occupying that square.


 */

     bool canMove(Board* game, Spot* start, Spot* ending)
    {
        cout << "hello from Pawn, a derived class" << endl ;

     /*
        If Pieces at start and end spot are same color return false
        If Piece at start and end spot are different colors
        but Piece is moving forward return false (only diagonal can kill)

     */
        if(ending->getPiece() != nullptr)
        {
            if(ending->getPiece()->isWhite() == start->getPiece()->isWhite()) // If pieces are same color
                return false ;
            else
            {
                if(ending->getY() - start->getY() == 0 ) //if Piece is moving forward
                    return false ;
            }
        }

    /*
        Pawn can move 1 of 3 ways:

        Forward 1 space, as long as ending Spot is unoccupied
        Forward 2 spaces, as long as ending Spot and path is unoccupied, and its this Pawns first move
        Diagonally forward left or right, 1 space, if ending Spot has a Piece to kill
    */

        if(start->getPiece()->isWhite() == true) //piece is white
        {
            if(( ending->getX() - start->getX() == 1) && ( ending->getY() == start->getY() )) //1 space forward
                return true ;
            else if(( ending->getX() - start->getX() == 2) && ( ending->getY() == start->getY() ) ) //2 spaces forward
                {
                    if(start->getX() == 1)// indicating its Pawns first move
                        return true ;
                    else
                        return false ;
                }
            else if(( ending->getX() - start->getX() == 1) && ( abs(ending->getY() - start->getY()) == 1 ) ) // diagonal forward 1
                return true;
            else
                return false;
        }
        else //piece is black
        {
             if(( start->getX() - ending->getX() == 1) && ( ending->getY() == start->getY() )) //1 space forward
                return true ;
            else if(( start->getX() - ending->getX() == 2) && ( ending->getY() == start->getY() ) ) //2 spaces forward
                {
                    if(start->getX() == 6)// indicating its Pawns first move
                        return true ;
                    else
                        return false ;
                }
            else if(( start->getX() - ending->getX() == 1) && ( abs(ending->getY() - start->getY()) == 1 ) ) // diagonal forward 1
                return true;
            else
                return false;

        }


    }




        void printP()
    {
        if(white == true)
            cout << "Pn " ;
        else
            cout << RED << "Pn " << RESET  ;
    }


    //Destructor for Pawn class
    ~Pawn()
    {
        cout << " Deleting Pawn" << endl ;
    }




};




#endif // PAWN_H
