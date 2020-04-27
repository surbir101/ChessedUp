#include "Piece.h"
#include <iostream>
#include <string>

using namespace std;

//Piece class implementation file

//Constructor
    Piece::Piece(bool white, bool killed)
    {
        setWhite(white) ;
        setKilled(killed) ;
    }


     void Piece::setWhite(bool white)   //setter
    {
       this->white = white ;
    }

     bool Piece::isWhite()  //getter
    {
        if(white == true)
            return true;
        else
            return false;
    }

    void Piece::setKilled(bool killed)  //setter
    {
       this->killed = killed ;
    }

     bool Piece::isKilled() //getter
    {
        if(killed == true)
            return true;
        else
            return false;
    }







