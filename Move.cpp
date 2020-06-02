// Move class implementation file


#include "Move.h"

//Constructor
Move::Move(Player* player, Spot* start, Spot* ending)
{
   this->player = player;
   this->start = start;
   this->ending = ending;
   this->pieceMoved = start->getPiece();
   this->pieceKilled = nullptr;

}

//Setter
    void Move::setPlayer(Player* player)
     {
         this->player = player ;

     }

//Getter
    Player* Move::getPlayer()
    {
        return player ;
    }

//Setter
     void Move::setStart(Spot* start)
     {
        this->start = start ;
     }

//Getter
     Spot* Move::getStart()
     {
        return start ;
     }

//Setter
     void Move::setEnding(Spot* ending)
     {
         this->ending = ending ;
     }

//Getter
     Spot* Move::getEnding()
     {
         return this->ending ;
     }

//Setter
  void Move::setPieceMoved(Piece* piece)
    {
        this->pieceMoved = piece ;
    }

//Getter
    Piece* Move::getPieceMoved()
    {
        return this->pieceMoved ;
    }

//Setter
    void Move::setPieceKilled(Piece* piece)
    {
        this->pieceKilled = piece ;
    }

//Getter
    Piece* Move::getPieceKilled()
    {
        return this->pieceKilled ;
    }

//Destructor
Move::~Move()
{

    cout << "Move class destructor called" << endl ;
}











