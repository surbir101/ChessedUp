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



     Move(Player*, Spot*, Spot* );

     Player* getPlayer() ;
     void setPlayer(Player*) ;

     Spot* getStart() ;
     void setStart(Spot*) ;


     Spot* getEnding() ;
     void setEnding(Spot*) ;



} ;



#endif // MOVE_H
