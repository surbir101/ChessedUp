#ifndef KING_H
#define KING_H
#include "Piece.h"
#include <iostream>
using namespace std;



class King : public Piece
{

public:

    King(bool white, bool killed) : Piece(white,killed){}

    void canMove()
    {
        cout << "hello from King, a derived class" << endl ;
    }


};


#endif // KING_H


