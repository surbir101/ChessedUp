/*Header file for Player class

Represents a Player in a game, and can be Human or Computer.
Holds two bool variables representing if the player
is on the whiteSide or is a humanPlayer.
Also holds a string for the players name.

Constructor initializes name of Player and side

*/


#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>
using namespace std;

//Player class declaration
class Player
{
public:

    bool whiteSide ;    // indicates if Player is on whiteSide or not (black side)
    bool humanPlayer ;  // indicates whether player is Human or Computer
    string name ;       // holds player name

//Constructor
    Player(string, bool) ;

//Setter & Getter for side
     void setWhiteSide(bool) ;
     bool isWhiteSide() ;

//Setter & Getter for type of Player
     void setHumanPlayer(bool) ;
     bool isHumanPlayer() ;


//virtual destructor
    virtual ~Player() = 0 ;




};


#endif // PLAYER_H
