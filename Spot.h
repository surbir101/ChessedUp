#ifndef SPOT_H
#define SPOT_H
#include "Piece.h"


class Spot
{

public:
    Piece piece ;
    int x ;
    int y;

    Spot(Piece) ;

    void setPiece(Piece) ;


    void setX(int) ;
    void setY(int) ;

    int getX();
    int getY();

};






#endif // SPOT_H
