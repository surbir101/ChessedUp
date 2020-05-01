#ifndef BISHOP_H
#define BISHOP_H
#include "Piece.h"
#include <iostream>
using namespace std;

class Bishop : public Piece
{

public:

    Bishop(bool white, bool killed) : Piece(white,killed){}

    void canMove()
    {
        cout << "hello from Bishop, a derived class" << endl ;
    }


};




#endif // BISHOP_H
