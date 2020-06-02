/* Header file for Move class

Used to keep track of each Move made in the game
Holds a Player to keep track of who made the move
A starting and ending spot as well as
the pieceMoved and if applicable pieceKilled

Moves are kept in a list type structure
defined in Game class

Constructor initializes Player making move
and starting and ending spots of move

*/


#ifndef MOVE_H
#define MOVE_H
#include "Player.h"
#include "Spot.h"


//Move class declaration
class Move {
    public:

     Player* player;        // Player which made move
     Spot* start;           // Starting spot of move
     Spot* ending;          // Ending spot of move
     Piece* pieceMoved;     // Piece moved
     Piece* pieceKilled;    // Piece killed if there is one or nullptr indicates none killed on this move

//Constructor
     Move(Player*, Spot*, Spot* );

//Setter's & Getter's
     Player* getPlayer() ;      //Sets Player making move
     void setPlayer(Player*) ;  //Returns Player making move

     Spot* getStart() ;         //Sets beginning Spot of move
     void setStart(Spot*) ;     //Returns beginning Spot of move


     Spot* getEnding() ;        //Sets ending spot of Move
     void setEnding(Spot*) ;    //Returns ending spot of Move


    Piece* getPieceMoved() ;        //Sets piece that is to be moved
    void setPieceMoved(Piece*) ;    //Returns piece that is to be moved

    void setPieceKilled(Piece*);    //Sets piece that was killed
    Piece* getPieceKilled() ;       //Returns piece that is killed

//Destructor
~Move();



} ;



#endif // MOVE_H
