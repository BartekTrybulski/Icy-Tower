#include "platform.h"

sf::Texture Platform::texture_platform2;
int Platform::counter=0;

Platform::Platform()
{

}

void Platform::loader(const std::string &path)
{
    if(!texture_platform2.loadFromFile(path))
    {
        std::cerr<<"Nie mozna zaladowac textury"<<std::endl;
        throw "Nie mozna zaladowac textury";
    }
}

int Platform::getcounter()
{
    return counter;
}

void Platform::setcounter(const int & val)
{
    counter=val;
}

void Platform::windowCollision(const sf::IntRect &pos)
{
    if(this->getGlobalBounds().left<=pos.left && this->speed.x<0)
        this->setspeedx(-1*speed.x);

    if(this->getGlobalBounds().left+this->getGlobalBounds().width>=pos.left+pos.width && this->getspeed().x>0)
        this->setspeedx(-1*speed.x);

    if(this->getGlobalBounds().top+this->getGlobalBounds().height>=pos.top+pos.height+40 && this->speed.y>0)
    {
        this->setPosition(rand()%int(800-this->getGlobalBounds().width),0);
        counter+=1;
        std::cout<<counter<<std::endl;
        if(counter>20)
        {
            this->setTexture(texture_platform2);
        }
    }
}

bool Platform::Collision(std::unique_ptr<Elements> *)
{
    return false;
}
