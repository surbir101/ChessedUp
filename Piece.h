
#ifndef PIECE_H
#define PIECE_H
#include "Board.h"
#include "Spot.h"
#include <iostream>
#include<cstdlib>
using namespace std;

#define BLACK   "\033[30m"
#define RESET   "\033[0m"
#define RED     "\033[31m"




// Piece class declaration

class Board ;
class Spot ;
 class Piece {

protected:

    bool killed ;       // true = piece alive  false = piece killed
    bool white ;        // true = color white  false = color black





public:
    //default constructor
    Piece(){killed = false;white = false;}

    //constructor
    Piece(bool,bool) ;

    //destructor
    virtual ~Piece(){cout<<" base destructor called" << endl ;}

    //setters and getters
    void setWhite(bool);
    bool isWhite();

    //setters and getters
    void setKilled(bool) ;
    bool isKilled() ;

    virtual bool canMove(Board*, Spot*, Spot*) = 0;

    virtual void printP() = 0 ;




};


#endif // PIECE_H
