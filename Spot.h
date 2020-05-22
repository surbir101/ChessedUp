
#ifndef SPOT_H
#define SPOT_H
#include "Piece.h"



// Spot class declaration file
class Piece ;
class Spot
{

public:
    Piece *piece ;
    int x ;
    int y;


    Spot() ;
    //~Spot() ;
    Spot(int, int, Piece *) ;

    void setPiece(Piece *) ;
    Piece* getPiece() ;


    void setX(int) ;
    void setY(int) ;

    int getX();
    int getY();

    void setAll(int, int, Piece*) ;
};






#endif // SPOT_H
