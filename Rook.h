#ifndef ROOK_H
#define ROOK_H
#include "Piece.h"
#include <iostream>
using namespace std;



class Rook : public Piece
{

public:

    Rook(bool white, bool killed) : Piece(white,killed){}

    void canMove()
    {
        cout << "hello from Rook, a derived class" << endl ;
    }


};





#endif // ROOK_H
