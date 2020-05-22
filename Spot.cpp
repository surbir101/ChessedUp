#include "Spot.h"
#include <iostream>
#include "Piece.h"

using namespace std;

//Spot class implementation file

Spot::Spot()
{
    this->x = -1;
    this->y = -1 ;
    this->piece = nullptr ;
}

Spot::Spot(int x, int y, Piece *p)
{
    this->x = x ;
    this->y = y ;
    this->piece = p ;
}

void Spot::setPiece(Piece *p)
{
    this->piece = p ;
}

Piece* Spot::getPiece()
{
    return this->piece ;

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



void Spot::setAll(int x, int y, Piece *p)
{
    this->x = x ;
    this->y = y ;
    this->piece = p ;
}

/*destructor
Spot::~Spot()
{
    delete this->piece ;

}
*/

