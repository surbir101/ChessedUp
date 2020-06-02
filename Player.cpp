//Player class implementation file


#include "Player.h"

//Constructor
Player::Player(string name, bool whiteSide)
{
    this->whiteSide = whiteSide ;
    this->name = name ;

}

//Setter
void Player::setWhiteSide(bool whiteSide)
{
    this->whiteSide = whiteSide ;

}

//Getter
bool Player::isWhiteSide()
{
    if(whiteSide == true)
        return true ;
    else
        return false ;

}

//Setter
void Player::setHumanPlayer(bool humanPlayer)
{
    this->humanPlayer = humanPlayer ;
}

//Getter
bool Player::isHumanPlayer()
{
    if(humanPlayer == true)
        return true;
    else
        return false;
}

 Player::~Player()
{
    cout << "Player base class destructor called  " << endl ;

}
