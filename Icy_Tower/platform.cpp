#include "platform.h"

Platform::Platform()
{

}

void Platform::windowCollision(const sf::IntRect &pos)
{
    if(this->getGlobalBounds().left<=pos.left && this->speed.x<0)
        this->setspeedx(-1*speed.x);

    if(this->getGlobalBounds().left+this->getGlobalBounds().width>=pos.left+pos.width && this->getspeed().x>0)
        this->setspeedx(-1*speed.x);
}
