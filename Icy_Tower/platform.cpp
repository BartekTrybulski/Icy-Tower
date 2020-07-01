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

    if(this->getGlobalBounds().top+this->getGlobalBounds().height>=pos.top+pos.height+40 && this->speed.y>0)
        this->setPosition(rand()%int(800-this->getGlobalBounds().width),0);
}

bool Platform::Collision(std::unique_ptr<Elements> *)
{
    return false;
}
