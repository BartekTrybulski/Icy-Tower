#ifndef PLAYER_H
#define PLAYER_H
#include "elements.h"
#include "platform.h"



class Player : public Elements
{
    public:
        Player();
        virtual bool Collision(std::unique_ptr<Elements> *) override;
        virtual void windowCollision(const sf::IntRect &pos) override;

};




#endif // PLAYER_H
