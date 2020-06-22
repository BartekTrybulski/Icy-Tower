#include "player.h"

Player::Player()
{

}

void Player::Collision(std::unique_ptr<Elements> *el)
{
    if(this->getGlobalBounds().left+this->getGlobalBounds().width>=(*el)->getGlobalBounds().left
            && this->getGlobalBounds().left+this->getGlobalBounds().width<=(*el)->getGlobalBounds().left+2
            && this->speed.x>0)
    {
        this->speed.x=0;
    }

    if(this->getGlobalBounds().left<(*el)->getGlobalBounds().left+(*el)->getGlobalBounds().width
            && this->getGlobalBounds().left>=(*el)->getGlobalBounds().left+(*el)->getGlobalBounds().width-2
            && this->speed.x<0)
    {
        this->speed.x=0;
    }

    if(this->getGlobalBounds().top+this->getGlobalBounds().height>=(*el)->getGlobalBounds().top
            && this->getGlobalBounds().top+this->getGlobalBounds().height<=(*el)->getGlobalBounds().top+2
            && this->speed.y>0)
    {
        this->speed.y=0;
    }

    if(this->getGlobalBounds().top<(*el)->getGlobalBounds().height+(*el)->getGlobalBounds().top
            && this->getGlobalBounds().top>=(*el)->getGlobalBounds().top+(*el)->getGlobalBounds().height-2
            && this->speed.y<0)
    {
        this->speed.y=0;
    }

}
