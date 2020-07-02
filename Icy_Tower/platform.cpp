#include "platform.h"
#include "elements.h"

sf::Texture Platform::texture_platform2;
sf::Texture Platform::texture_platform3;
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

void Platform::loader2(const std::string &path)
{
    if(!texture_platform3.loadFromFile(path))
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
        this->setspeedx(static_cast<float>(rand()%300-200));
        counter+=1;
        if(counter>50)
        {
            Platform::loader("Textures/platform2.png");
            this->setTexture(texture_platform2);
        }
        if(counter>100)
        {
            Platform::loader2("Textures/platform3.png");
            this->setTexture(texture_platform3);
        }
    }
}

bool Platform::Collision(std::unique_ptr<Elements> *)
{
    return false;
}
