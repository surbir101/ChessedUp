/*Header file for ComputerPlayer class

Inherits from Player class and includes inline definition
of constructor, which accepts a string and bool to
set this players name, and chosen side (white or black) .

Not used in 2 player mode, but only if 1 player wants
to play against the "Computer" which is the AI engine,
that is yet to be implemented.

*/



#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H
#include "Player.h"

class ComputerPlayer : public Player
{

public:
    ComputerPlayer(string name,bool whiteSide) : Player(name,whiteSide)
    {
        this->whiteSide = whiteSide ;   // true = white || false = black
        this->name = name ;
        this->humanPlayer = false;
    }

    //Destructor for ComputerPlayer class
    ~ComputerPlayer()
    {
        cout << " Deleting ComputerPlayer" << endl ;
    }





};

#endif // COMPUTERPLAYER_H
