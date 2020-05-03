#ifndef MOVE_H
#define MOVE_H
#include "Player.h"
#include "Spot.h"


class Move {
    public:

     Player* player;
     Spot* start;
     Spot* ending;
     Piece* pieceMoved;
     Piece* pieceKilled;



     Move(Player* player, Spot* start, Spot* ending)
    {
        this->player = player;
        this->start = start;
        this->ending = ending;
        this->pieceMoved = start->getPiece();
    }


} ;



#endif // MOVE_H
