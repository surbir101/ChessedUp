// Implementation file for Piece class

#include "Piece.h"
#include <iostream>
#include <string>

using namespace std;



//Constructor
    Piece::Piece(bool white, bool killed)
    {
        setWhite(white) ;
        setKilled(killed) ;
    }


//setter for color
     void Piece::setWhite(bool white)
    {
       this->white = white ;
    }

//getter for color
     bool Piece::isWhite()
    {
        if(white == true)
            return true;
        else
            return false;
    }

//setter for alive or dead
    void Piece::setKilled(bool killed)
    {
       this->killed = killed ;
    }

//getter for alive or dead
     bool Piece::isKilled()
    {
        if(killed == true)
            return true;
        else
            return false;
    }




    Piece::~Piece()
    {
        cout << "Base class destructor called  " << endl ;


    }



