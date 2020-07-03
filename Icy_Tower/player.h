#ifndef PLAYER_H
#define PLAYER_H
#include "elements.h"
#include "platform.h"



class Player : public Elements
{
    protected:
        int animation;
        sf::Clock animate;

    public:
        Player();
        virtual bool Collision(std::unique_ptr<Elements> *) override;
        virtual void windowCollision(const sf::IntRect &pos) override;
        bool floorCollision(const sf::IntRect &pos);
        virtual void update(const sf::Time &time) override;
};




#endif // PLAYER_H
