#ifndef ELEMENTS_H
#define ELEMENTS_H

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <sstream>
#include <cmath>



class Elements : public sf::Sprite
{
    protected:
        sf::Texture texture;
        sf::Vector2f speed;

    public:
        Elements();
        virtual void setspeed(const sf::Vector2f &vel);
        virtual void setspeedx(const float &speedx) {this->speed.x = speedx;}
        virtual void setspeedy(const float &speedy) {this->speed.y = speedy;}
        virtual void addtospeed(const sf::Vector2f &vel);
        virtual sf::Vector2f getspeed() const;
        virtual void update(const sf::Time &time);
        virtual void windowCollision(const sf::IntRect &pos);
        virtual bool Collision(std::unique_ptr<Elements> *)=0;
        virtual ~Elements()=default;

};

#endif // ELEMENTS_H
