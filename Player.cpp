#include "Player.h"


Player::Player(bool whiteSide)
{
    this->whiteSide = whiteSide ;

}

void Player::setWhiteSide(bool whiteside)
{
    this->whiteSide = whiteside ;

}

bool Player::isWhiteSide()
{
    if(whiteSide == true)
        return true ;
    else
        return false ;

}

void Player::setHumanPlayer(bool humanPlayer)
{
    this->humanPlayer = humanPlayer ;
}

bool Player::isHumanPlayer()
{
    if(humanPlayer == true)
        return true;
    else
        return false;
}
