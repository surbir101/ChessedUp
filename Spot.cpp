#include "Spot.h"
#include <iostream>
#include "Piece.h"

using namespace std;



Spot::Spot(Piece p)
{
    this->piece = p ;
}

void Spot::setPiece(Piece p)
{
    this->piece = p ;
}

void Spot::setX(int x)
{
    this->x = x;
}

int Spot::getX()
{
    return x ;
}

void Spot::setY(int y)
{
    this->y = y;
}

int Spot::getY()
{
    return y ;
}


