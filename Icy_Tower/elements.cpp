#include "elements.h"

Elements::Elements()
{

}

void Elements::setspeed(const sf::Vector2f &vel)
{
    this->speed=vel;
}

void Elements::addtospeed(const sf::Vector2f &vel)
{
    this->speed += vel;
}

sf::Vector2f Elements::getspeed() const
{
    return speed;
}

void Elements::update(const sf::Time &time)
{
    this->move(speed*time.asSeconds());
}

void Elements::windowCollision(const sf::IntRect &pos)
{
    if(this->getGlobalBounds().left<=pos.left && this->speed.x<0)
        this->speed.x=0;

    if(this->getGlobalBounds().left+this->getGlobalBounds().width>=pos.left+pos.width && this->speed.x>0)
        this->speed.x=0;

    if(this->getGlobalBounds().top<=pos.top && this->speed.y<0)
        this->speed.y=0;

    if(this->getGlobalBounds().top+this->getGlobalBounds().height>=pos.top+pos.height && this->speed.y>0)
        this->speed.y=0;
}


