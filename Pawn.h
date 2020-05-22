#ifndef PAWN_H
#define PAWN_H
#include "Piece.h"
#include "Board.h"
#include "Spot.h"



class Pawn : public Piece
{

public:

    Pawn(bool white, bool killed) : Piece(white,killed){}


     bool canMove(Board* game, Spot* start, Spot* ending)
    {
        cout << "hello from Pawn, a derived class" << endl ;

        if(ending->getPiece() != nullptr)
        {
            if(start->getPiece()->isWhite() == ending->getPiece()->isWhite())
                return false ;
            else
            {
                if(start->getPiece()->isWhite())
                {
                    if(ending->getX() - start->getX() == 1)
                    {
                        if(abs(start->getY() - ending->getY()) == 1)
                            return true;
                        else
                            return false;
                    }
                    else
                        return false;

                }
                else
                {
                    if(start->getX() - ending->getX() == 1)
                    {
                        if(abs(start->getY() - ending->getY() == 1))
                            return true;
                        else
                            return false ;
                    }
                    else
                        return false ;
                }
            }

        }
        else
        {
            if(start->getPiece()->isWhite())
            {
                if(ending->getX() - start->getX() == 1)
                {
                    if(start->getY() == ending->getY())
                        return true ;
                    else
                        return false;

                }
                else if(ending->getX() - start->getX() == 2)
                {
                    if(start->getY() == ending->getY())
                        return true;
                    else
                        return false;

                }
                else
                    return false;


            }
            else
            {
                if(start->getX() - ending->getX() == 1)
                {
                    if(start->getY() == ending->getY())
                        return true;
                    else
                        return false;
                }
                else if(start->getX() - ending->getX() == 2)
                {
                    if(start->getY() == ending->getY())
                        return true;
                    else
                        return false;
                }
                else
                    return false;

            }

        }




    }

        void printP()
    {
        if(white == true)
            cout << "Pn " ;
        else
            cout << RED << "Pn " << RESET  ;
    }




};




#endif // PAWN_H
