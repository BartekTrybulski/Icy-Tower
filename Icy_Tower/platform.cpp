#include "platform.h"
#include "elements.h"

std::vector<sf::Texture> Platform::texture_platform;
int Platform::counter=0;

Platform::Platform()
{
    this->setTexture(texture_platform[0]);
}

void Platform::loader(const std::vector<std::string> &paths)
{
    for(int i=0;i<3;i++)
    {
        texture_platform.emplace_back(sf::Texture());
        if(!texture_platform[i].loadFromFile(paths[i]))
        {
            std::cerr<<"Nie mozna zaladowac textury"<<std::endl;
            throw "Nie mozna zaladowac textury";
        }

    }
}

int Platform::getcounter()
{
    return counter;
}

sf::Texture *Platform::gettexture()
{
    return &texture_platform[0];
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
        this->setspeedx(static_cast<float>(rand()%300-200));
        counter+=1;
        if(counter>10)
        {
            this->setTexture(texture_platform[1]);
        }
        if(counter>30)
        {
            this->setTexture(texture_platform[2]);
        }
    }
}

bool Platform::Collision(std::unique_ptr<Elements> *)
{
    return false;
}
