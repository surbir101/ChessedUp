#include "Piece.h"
#include <iostream>

using namespace std;


    Piece::Piece(bool white)
    {
        setWhite(white) ;
    }


     void Piece::setWhite(bool white)
    {
       this->white = white ;
    }

     bool Piece::isWhite()
    {
        if(white == true)
            return true;
        else
            return false;
    }

    void Piece::setKilled(bool killed)
    {
       this->killed = killed ;
    }

     bool Piece::isKilled()
    {
        if(killed == true)
            return true;
        else
            return false;
    }








