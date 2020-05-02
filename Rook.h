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



      bool canMove(Board* game, Spot* start, Spot* ending)
    {
        cout << "hello from Rook, a derived class" << endl ;
        return true;

    }

    ~Rook(){cout << "derived destructor called" ;}


};





#endif // ROOK_H
