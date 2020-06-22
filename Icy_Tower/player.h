#ifndef PLAYER_H
#define PLAYER_H
#include <elements.h>



class Player : public Elements
{
    public:
        Player();
        virtual void Collision(std::unique_ptr<Elements> *el) override;
};




#endif // PLAYER_H
