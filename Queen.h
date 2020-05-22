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

    Queen(bool white, bool killed) : Piece(white,killed){}

     bool canMove(Board* board, Spot* start, Spot* ending)
    {
       cout << "hello from Queen, a derived class" << endl ;

        int i  = -1;
        int x  = -1;
        int y = -1;


       //check for same color piece at end spot
       if(ending->getPiece() != nullptr)
           if(ending->getPiece()->isWhite() == start->getPiece()->isWhite())
                return false ;

        if(start->getX() == ending->getX()) // horizontal move check path
        {
             x = start->getX() ; i = start->getY() ;
            if(start->getY() > ending->getY())
            {
                i = i -1 ; // set y to next y in path
                while(board->boxes[x][i]->getPiece() == nullptr && i != ending->getY())
                {
                    i-- ;
                }

            }
            else
            {
                 i = i + 1 ; // set y to next y in path
                while(board->boxes[x][i]->getPiece() == nullptr && i != ending->getY())
                {
                    i++ ;
                }

            }

           if( i == ending->getY())
                return true ;
           else
            return false;

        }
        else if(start->getY() == ending->getY()) // moving vertically check path
        {
            y = start->getY() ; i = start->getX() ;
            if(start->getX() > ending->getX())
            {
                i = i -1 ; // set y to next y in path
                while(board->boxes[i][y]->getPiece() == nullptr && i != ending->getX())
                {
                    i-- ;
                }

            }
            else
            {

                 i = i + 1 ; // set y to next y in path
                while(board->boxes[i][y]->getPiece() == nullptr && i != ending->getX())
                {

                    i++ ;
                }

            }

            if( i == ending->getX())
                return true ;
           else
                return false;
        }
        else if(abs(start->getX() - ending->getX()) == abs(start->getY() - ending->getY())) // moving diaganolly check path
        {

            x = start->getX() ; y = start->getY() ;


            if(start->getY() > ending->getY())
            {
                y = y-1 ;
                if(start->getX() > ending->getX())
                {
                    x = x-1 ;
                    while(board->boxes[x][y]->getPiece() == nullptr && x != ending->getX())
                    {
                        x--; y-- ;
                    }
                }
                else
                {
                    x = x+1 ;
                       while(board->boxes[x][y]->getPiece() == nullptr && x != ending->getX())
                    {
                        x++; y-- ;
                    }
                }


            }
            else
            {
                 y = y+1 ;
                 if(start->getX() > ending->getX())
                {
                    x = x-1;
                       while(board->boxes[x][y]->getPiece() == nullptr && x != ending->getX())
                    {
                        x--; y++ ;
                    }
                }
                else
                {
                    x = x+1;
                       while(board->boxes[x][y]->getPiece() == nullptr && x != ending->getX())
                    {
                        x++; y++ ;
                    }
                }


            }



            if( x == ending->getX())
                return true ;
           else
                return false;

        }
        else // not vertical horizontal or diagonal
            return false ;




    }

        void printP()
    {
        if(white == true)
            cout << "QU " ;
        else
            cout << RED << "QU " << RESET  ;
    }



};



#endif // QUEEN_H
