#ifndef QUEEN_H
#define QUEEN_H
#include "Piece.h"
#include <iostream>
using namespace std;


class Queen : public Piece
{

public:

    Queen(bool white, bool killed) : Piece(white,killed){}

    void canMove()
    {
        cout << "hello from Queen, a derived class" << endl ;
    }


};



#endif // QUEEN_H
