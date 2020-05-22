#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Board.h"
#include "Move.h"
#include "King.h"
#include <list>
#include <typeinfo>

class Game
{

public:

    enum GameStatus
    {
        ACTIVE,
        BLACK_WIN,
        WHITE_WIN,
        FORFEIT,
        STALEMATE,
        RESIGNATION
    } ;

     Player* players[2];
     Board board;
     Player* currentTurn;
     GameStatus status;
     list<Move> movesPlayed;

     void initialize(Player*, Player*) ;
     bool isEnd() ;
     bool getStatus() ;
     void setStatus(GameStatus) ;
     bool playerMove(Player*, int, int, int, int) ;
     bool makeMove(Move, Player*) ;
   //  void printBoard() ;



};


#endif // GAME_H
