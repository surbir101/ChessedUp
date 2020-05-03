#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H
#include "Player.h"

class ComputerPlayer : public Player
{

public:
    ComputerPlayer(bool whiteSide)
    {
        this->whiteSide = whiteSide ;
        this->humanPlayer = false;
    }




};

#endif // COMPUTERPLAYER_H
