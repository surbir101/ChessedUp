#ifndef HUMANPLAYER
#define HUMANPLAYER
#include "Player.h"

class HumanPlayer : public Player
{

public:
    HumanPlayer(bool whiteSide)
    {
        this->whiteSide = whiteSide ;
        this->humanPlayer = true;
    }






};

#endif // HUMANPLAYER
