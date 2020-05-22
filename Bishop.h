#ifndef BISHOP_H
#define BISHOP_H
#include "Piece.h"
#include "Board.h"
#include "Spot.h"
#include "Piece.h"

#include <iostream>
using namespace std;

class Bishop : public Piece
{

public:

    Bishop(bool white, bool killed) : Piece(white,killed){}

    bool canMove(Board* board, Spot* start, Spot* ending)
    {
        cout << "hello from Bishop, a derived class" << endl ;

        int x = start->getX() ; int y = start->getY() ;

          //check for same color piece at end spot
       if(ending->getPiece() != nullptr)
           if(ending->getPiece()->isWhite() == start->getPiece()->isWhite())
                return false ;

        // piece is white moving up board
        if(start->getPiece()->isWhite() == true)
        {
            if(start->getX() > ending->getX())  // if moving wrong way not valid
                return false;
            else
            {
                if(abs(start->getX() - ending->getX()) == abs(start->getY() - ending->getY()))      // checks if piece move is diagnol
                {
                    x = x+1 ;
                    if(start->getY() > ending->getY())
                    {
                        y = y-1 ;
                        while(board->boxes[x][y]->getPiece() == nullptr && x != ending->getX())
                        {
                            x++ ; y-- ;
                        }

                    }
                    else
                    {
                         y = y+1 ;
                        while(board->boxes[x][y]->getPiece() == nullptr && x != ending->getX())
                        {
                            x++ ; y++ ;
                        }

                    }
                }
                else
                    return false;
            }

        }
        else
        {
            if(start->getX() < ending->getX())  // if moving wrong way not valid
                return false;
            else
            {
                if(abs(start->getX() - ending->getX()) == abs(start->getY() - ending->getY()))      // checks if piece move is diagnol
                {
                    x = x-1 ;
                    if(start->getY() > ending->getY())
                    {
                        y = y-1 ;
                        while(board->boxes[x][y]->getPiece() == nullptr && x != ending->getX())
                        {
                            x-- ; y-- ;
                        }

                    }
                    else
                    {
                         y = y+1 ;
                        while(board->boxes[x][y]->getPiece() == nullptr && x != ending->getX())
                        {
                            x-- ; y++ ;
                        }

                    }
                }
                else
                    return false;
            }


        }

        if( x == ending->getX())
            return true;
        else
            return false;





    }
        void printP()
    {
        if(white == true)
            cout << "Bi " ;
        else
            cout << RED << "Bi " << RESET  ;
    }




};




#endif // BISHOP_H
