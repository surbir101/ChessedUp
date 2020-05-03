#include "Move.h"



Move::Move(Player* player, Spot* start, Spot* ending)
{
   this->player = player;
   this->start = start;
   this->ending = ending;
   this->pieceMoved = start->getPiece();

}

    Player* Move::getPlayer()
    {
        return player ;
    }

     void Move::setPlayer(Player* player)
     {
         this->player = player ;

     }


     Spot* Move::getStart()
     {
        return start ;
     }

     void Move::setStart(Spot* start)
     {
        this->start = start ;

     }



     Spot* Move::getEnding()
     {
         return this->ending ;
     }

     void Move::setEnding(Spot* ending)
     {
         this->ending = ending ;
     }





