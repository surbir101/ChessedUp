#ifndef KNIGHT_H
#define KNIGHT_H
#include "Piece.h"
#include <iostream>
using namespace std;



class Knight : public Piece
{

public:

    Knight(bool white, bool killed) : Piece(white,killed){}

    void canMove()
    {
        cout << "hello from Knight, a derived class" << endl ;
    }


};




#endif // KNIGHT_H
