#ifndef PLATFORM_H
#define PLATFORM_H
#include<elements.h>


class Platform : public Elements
{
    protected:
        static int counter;
        static std::vector<sf::Texture> texture_platform;


    public:
        Platform();
        static void loader(const std::vector<std::string> &paths);
        static int getcounter();
        static sf::Texture *gettexture();
        static void setcounter(const int&);
        virtual void windowCollision(const sf::IntRect &pos) override;
        virtual bool Collision(std::unique_ptr<Elements> *) override;
};



#endif // PLATFORM_H
