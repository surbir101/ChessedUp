#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:

    bool whiteSide ;
    bool humanPlayer ;


     bool isWhiteSide()
    {
        return this->whiteSide == true;
    }
     bool isHumanPlayer()
    {
        return this->humanPlayer == true;
    }



};


#endif // PLAYER_H
