#include "elements.h"
#include "player.h"
#include "platform.h"

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Icy Tower");

    sf::Texture texture_back;
    if(!texture_back.loadFromFile("Textures/wall.jpg")) {return 1;}
    texture_back.setRepeated(true);

    sf::Sprite back;
    back.setTexture(texture_back);

    sf::Texture texture_hero;
    if(!texture_hero.loadFromFile("Textures/character.png")) {return 1;}

    sf::Texture texture_platform;
    if(!texture_platform.loadFromFile("Textures/platform.jpg")) {return 1;}
    texture_platform.setRepeated(true);

    std::vector<std::unique_ptr<Elements>> objects;

    objects.emplace_back(std::make_unique<Player>());
    objects[0]->setTexture(texture_hero);
    objects[0]->setTextureRect({14,7,19,29});
    objects[0]->setScale(3,3);
    objects[0]->setPosition(200,540);
    objects[0]->setOrigin(10,15);

    objects.emplace_back(std::make_unique<Platform>());
    objects[1]->setPosition(300,500);
    objects[1]->setTexture(texture_platform);
    objects[1]->setScale(0.06,0.012);

    objects.emplace_back(std::make_unique<Platform>());
    objects[2]->setPosition(100,400);
    objects[2]->setTexture(texture_platform);
    objects[2]->setScale(0.06,0.012);

    objects.emplace_back(std::make_unique<Platform>());
    objects[3]->setPosition(400,300);
    objects[3]->setTexture(texture_platform);
    objects[3]->setScale(0.06,0.012);



//    objects[1]->setTexture(texture_platform);

//    objects.emplace_back(std::make_unique<Platform>());

//    objects.emplace_back(std::make_unique<Platform>());

//    objects.emplace_back(std::make_unique<Platform>());

//    objects.emplace_back(std::make_unique<Platform>());

    for(unsigned int i=1;i<4;i++)
    {
        objects[i]->setspeedx(50);
    }

    sf::Vector2f gravity({0,1600});

    sf::Clock clock;
    sf::Time time;

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        clock.restart();
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();



            objects[0]->setspeed({0,objects[0]->getspeed().y});

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                objects[0]->setspeedy(-650.0);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                objects[0]->setspeedx(500);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                objects[0]->setspeedx(-500);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                objects[0]->setspeedx(500);

        }

        // clear the window with black color

        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(back);

        objects[0]->addtospeed(gravity*time.asSeconds());

        for(auto &el : objects)
        {
            el->windowCollision({0,0,800,600});
            window.draw(*el);
            el->update(time);
        }

        // end the current frame
        window.display();
        time = clock.getElapsedTime();
    }

    return 0;
}


