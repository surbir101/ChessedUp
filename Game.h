/*Header file for Game class

This class is used to create and play a Game of Chess.

The game object is created, and both players are passed
as parameters to game.initialize(). Following this the Chess
Board is ready with pieces set, and players are prompted to
input a move with valid coordinates.

Game.playerMove(player,startX,startY,endX,endY) is called to make a move
the move is checked for validity and then made as well as stored in List<Move>.

While(game.status == game.active) the game continues, and each player will take turns
making moves until one player wins or chooses to end the game.

*/

#ifndef GAME_H
#define GAME_H
#include "HumanPlayer.h"
#include "Board.h"
#include "Move.h"
#include "King.h"
#include <list>
#include <typeinfo>
#include <string>

class Game
{

public:

//Used to indicate status of game
    enum GameStatus
    {
        ACTIVE,
        BLACK_WIN,
        WHITE_WIN,
        FORFEIT,
        STALEMATE,
        RESIGNATION
    } ;

     Player* players[2];    //Holds current players of this game
     Board board;   //Board object created upon creation of Game object
     Player* currentTurn;   //Indicates which player's turn it is to make a move
     Move* move1; // used to create new Moves that are stored in List data structure
     GameStatus status;     //Indicates if the game is active or if it reached termination
     list<Move> movesPlayed;    //Used to keep track of moves made in this game

     Game() ; //Constructor
     void playGame() ; //Loops game
     void initialize(Player*, Player*) ;    //Function initializes the players in this game
     bool isEnd() ;     //Getter to determine if game is over or not
     bool getStatus() ;     //Getter to determine status of game
     void setStatus(GameStatus) ;   //Setter to set game status
     bool playerMove(Player*, int, int, int, int) ;     //Called by makeMove to move Piece indicated on chessboard to desired place
     bool makeMove(Move, Player*) ;     //Called by Player to indicate a desired move, with relevant coordinates of start and end passed
     void parseS(string,int&,int&) ; // To parse user input string (S).

//Destructor
~Game() ;


};


#endif // GAME_H
