#ifndef PLATFORM_H
#define PLATFORM_H
#include<elements.h>


class Platform : public Elements
{
    protected:
        static int counter;
        static sf::Texture texture_platform2;

    public:
        Platform();
        static void loader(const std::string &);
        static int getcounter();
        static void setcounter(const int&);
        virtual void windowCollision(const sf::IntRect &pos) override;
        virtual bool Collision(std::unique_ptr<Elements> *) override;
};



#endif // PLATFORM_H
