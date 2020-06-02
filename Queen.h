/* Header file for Queen class

Queen class inherits from Piece class, and implements
virtual function canMove() to determine validity
of move according to game logic.

Constructor invokes base class Constructor and
passes along two bools to indicate color and
piece status(dead or alive).

*/



#ifndef QUEEN_H
#define QUEEN_H
#include "Piece.h"
#include "Board.h"
#include "Spot.h"
//#include <iostream>

//using namespace std;

class Queen : public Piece
{

public:

//Queen class constructor calls base class Piece constructor
    Queen(bool white, bool killed) : Piece(white,killed){}







 /*
    Piece class virtual function canMove(): Queen child class implementation

    Queen can move like a rook or a bishop, therefor in any direction, so
    long as there is not a piece in its path.

    If there is a piece at the end Spot and it is not of the same color
    as the piece at the start Spot we return true, because we kill it
    and take its position. Else if the Pieces are of same color return false.

 */


     bool canMove(Board* board, Spot* start, Spot* ending)
    {
       cout << "hello from Queen, a derived class" << endl ;

     //Returns false if Pieces at both spots are of the same color
       if(ending->getPiece() != nullptr)
            if(ending->getPiece()->isWhite() == start->getPiece()->isWhite())
                return false;

       //To determine if move is a valid direction
        int x = abs(start->getX() - ending->getX()) ;
        int y = abs(start->getY() - ending->getY()) ;


        if( x != 0 && y != 0 )  // checks if queen is moving up down left or right (Rook logic)
            if( x != y )    //checks if queen is moving diagonal (Bishop logic)
                return false;


        //Now check if path is clear,by determining direction and then checking path
        int i = 0 ; int j = 0 ; //iterator variables
        if( x == 0 ) //Queen is attempting to move left of right
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
        else if( y == 0 ) //Queen is attempting to move up or down
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
        else if( x == y ) //Queen is attempting to move diagonal
        {
            if( start->getX() < ending->getX() ) // moving up the board diagonally
            {
                if( start->getY() < ending->getY() ) // diagonally right
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
        else
            return false; //Invalid move



    }



        void printP()
    {
        if(white == true)
            cout << "QU " ;
        else
            cout << RED << "QU " << RESET  ;
    }


    //Destructor for Queen class
    ~Queen()
    {
        cout << " Deleting Queen" << endl ;
    }



};



#endif // QUEEN_H
