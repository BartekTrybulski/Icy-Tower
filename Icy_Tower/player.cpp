#include "elements.h"
#include "player.h"
#include "platform.h"

Player::Player()
{

}

bool Player::Collision(std::unique_ptr<Elements> *element)
{
    Platform* platform=dynamic_cast<Platform*>(element->get());
    if(this->getGlobalBounds().intersects(platform->getGlobalBounds()))
    {
        if(this->getGlobalBounds().left + this->getGlobalBounds().width >= platform->getGlobalBounds().left
                && this->getGlobalBounds().left <= platform->getGlobalBounds().left + platform->getGlobalBounds().width
                && this->getGlobalBounds().top + this->getGlobalBounds().height >= platform->getGlobalBounds().top
                && this->getGlobalBounds().top + this->getGlobalBounds().height <= platform->getGlobalBounds().top + 2)
        {
            if(this->getspeed().y>platform->getspeed().y)
                this->setspeedy(platform->getspeed().y);
                    return true;
        }
    }
    return false;
}

void Player::windowCollision(const sf::IntRect &pos)
{
    if(this->getGlobalBounds().left<=pos.left && this->speed.x<0)
        this->speed.x=0;

    if(this->getGlobalBounds().left + this->getGlobalBounds().width>=pos.left+pos.width && this->speed.x>0)
        this->speed.x=0;

    if(this->getGlobalBounds().top + this->getGlobalBounds().height>=pos.top+pos.height && this->speed.y>0)
        this->speed.y=0;
}

bool Player::floorCollision(const sf::IntRect &pos)
{
    if(this->getGlobalBounds().top + this->getGlobalBounds().height>=pos.top+pos.height && this->speed.y>=0)
    {
       return true;
    }
    return false;
}
