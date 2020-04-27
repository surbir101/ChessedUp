#ifndef PIECE_H
#define PIECE_H

// Piece class declaration


 class Piece {

protected:

    bool killed ;       // true = piece alive  false = piece killed
    bool white ;        // true = color white  false = color black


public:
    //default constructor
    Piece(){killed = false;white = false;}

    //constructor
    Piece(bool,bool) ;

    //setters and getters
    void setWhite(bool);
    bool isWhite();

    //setters and getters
    void setKilled(bool) ;
    bool isKilled() ;

    virtual void canMove() = 0;


};


#endif // PIECE_H
