#ifndef PIECE_H
#define PIECE_H


 class Piece {

protected:

    bool killed ;
    bool white ;

public:

    Piece(bool) ;

    void setWhite(bool);
    bool isWhite();

    void setKilled(bool) ;
    bool isKilled() ;




};


#endif // PIECE_H
