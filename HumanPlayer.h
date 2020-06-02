/*Header file for HumanPlayer class

Inherits from Player class and includes inline definition
of constructor, which accepts a string and bool to
set this players name, and chosen side (white or black) .

*/

#ifndef HUMANPLAYER
#define HUMANPLAYER
#include "Player.h"


class HumanPlayer : public Player
{

public:

//Constructor
    HumanPlayer(string name,bool whiteSide) : Player(name,whiteSide)
    {

        this->whiteSide = whiteSide ;   // true = white || false = black
        this->name = name ;
        this->humanPlayer = true;
    }

    //Destructor for HumanPlayer class
    ~HumanPlayer()
    {
        cout << " Deleting HumanPlayer" << endl ;
    }




};

#endif // HUMANPLAYER
