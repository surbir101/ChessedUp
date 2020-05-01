#ifndef PAWN_H
#define PAWN_H
#include "Piece.h"
#include <iostream>
using namespace std;



class Pawn : public Piece
{

public:

    Pawn(bool white, bool killed) : Piece(white,killed){}

    void canMove()
    {
        cout << "hello from Pawn, a derived class" << endl ;
    }


};




#endif // PAWN_H
