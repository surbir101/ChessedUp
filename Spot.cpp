//Spot class implementation file

#include "Spot.h"
#include <iostream>
#include "Piece.h"

using namespace std;

// Default constructor
Spot::Spot()
{
    this->x = -1;
    this->y = -1 ;
    this->piece = nullptr ;
}

//Constructor
Spot::Spot(int x, int y, Piece *p)
{
    this->x = x ;
    this->y = y ;
    this->piece = p ;
}

//Setter for Piece
void Spot::setPiece(Piece *p)
{
    this->piece = p ;
}

//Getter for Piece
Piece* Spot::getPiece()
{
    return this->piece ;

}

//Setter for x
void Spot::setX(int x)
{
    this->x = x;
}

//Getter for x
int Spot::getX()
{
    return x ;
}

//Setter for y
void Spot::setY(int y)
{
    this->y = y;
}

//Getter for y
int Spot::getY()
{
    return y ;
}

//Setter to set all variables in class at once
void Spot::setAll(int x, int y, Piece *p)
{
    this->x = x ;
    this->y = y ;
    this->piece = p ;
}

//Destructor
Spot::~Spot()
{


}


