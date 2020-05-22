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

    Rook(bool white, bool killed) : Piece(white,killed){}



      bool canMove(Board* board, Spot* start, Spot* ending)
    {
        cout << "hello from Rook, a derived class" << endl ;

        int x = abs(start->getX() - ending->getX()) ;
        int y = abs(start->getY() - ending->getY()) ;

        if(x == 0 || y == 0)
        {
            if(ending->getPiece() == nullptr)  // no piece
            {

                if( x == 0)
                {
                    if(start->getY() > ending->getY())
                    {
                        for(int i = start->getY()-1; i > ending->getY(); i--)
                        {
                            if(board->boxes[start->getX()][i]->getPiece() != nullptr)
                            {
                                return false;
                            }
                            //do nothing
                        }
                        return true;

                    }
                    else
                    {
                        for(int i = start->getY()+1; i < ending->getY(); i++)
                        {
                            if(board->boxes[start->getX()][i]->getPiece() != nullptr)
                            {
                                return false;
                            }
                            //do nothing
                        }
                        return true;


                    }
                }
                else
                {
                    if(start->getX() > ending->getX())
                    {
                        for(int i = start->getX()-1; i > ending->getX(); i--)
                        {
                            if(board->boxes[i][start->getY()]->getPiece() != nullptr)
                            {
                               return false;
                            }
                            //do nothing
                        }
                        return true;

                    }
                    else
                    {
                         for(int i = start->getX()+1; i < ending->getX(); i++)
                        {
                            if(board->boxes[i][start->getX()]->getPiece() != nullptr)
                            {
                              return false;
                            }
                            //do nothing
                        }
                        return true;

                    }

                }


            }
            else //piece
            {
                if(ending->getPiece()->isWhite() == start->getPiece()->isWhite())
                    return false;
                else
                {
                      if( x == 0)
                {
                    if(start->getY() > ending->getY())
                    {
                        for(int i = start->getY()-1; i > ending->getY(); i--)
                        {
                            if(board->boxes[start->getX()][i]->getPiece() != nullptr)
                            {
                                return false;
                            }
                            //do nothing
                        }
                        return true;

                    }
                    else
                    {
                        for(int i = start->getY()+1; i < ending->getY(); i++)
                        {
                            if(board->boxes[start->getX()][i]->getPiece() != nullptr)
                            {
                                return false;
                            }
                            //do nothing
                        }
                        return true;


                    }
                }
                else
                {
                    if(start->getX() > ending->getX())
                    {
                        for(int i = start->getX()-1; i > ending->getX(); i--)
                        {
                            if(board->boxes[i][start->getY()]->getPiece() != nullptr)
                            {
                                return false;
                            }
                            //do nothing
                        }
                        return true;

                    }
                    else
                    {
                         for(int i = start->getX()+1; i < ending->getX(); i++)
                        {
                            if(board->boxes[i][start->getX()]->getPiece() != nullptr)
                            {
                                return false;
                            }
                            //do nothing
                        }
                        return true;

                    }

                }




                }

            }
        }
        else
            return false ;


    }

        void printP()
    {
        if(white == true)
            cout << "Ro " ;
        else
            cout << RED << "Ro " << RESET  ;
    }


    ~Rook(){cout << "derived destructor called" ;}


};





#endif // ROOK_H
