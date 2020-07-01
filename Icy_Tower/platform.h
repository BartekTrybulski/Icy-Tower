#ifndef PLATFORM_H
#define PLATFORM_H
#include<elements.h>


class Platform : public Elements
{
    public:
        Platform();
        virtual void windowCollision(const sf::IntRect &pos) override;
        virtual bool Collision(std::unique_ptr<Elements> *) override;
};

#endif // PLATFORM_H
