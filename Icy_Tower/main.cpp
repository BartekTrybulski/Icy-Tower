#include "elements.h"
#include "player.h"
#include "platform.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Icy Tower");

    sf::Font font;
    if (!font.loadFromFile("Font/RoteFlora.ttf"))
    {
        std::cerr << "Bark odpowiedniej czcionki" << std::endl;
        return -1;
    }

    int best;
    std::ifstream file;
    file.open("score.txt");
    if(file.is_open())
    {
        while(!file.eof())
            file>>best;
    }
    file.close();

    sf::Text score;
    score.setFont(font);
    score.setPosition(5,5);

    sf::Text score2;
    score2.setFont(font);
    score2.setPosition(285,265);
    score2.setFillColor(sf::Color::Red);

    sf::Text score3;
    score3.setFont(font);
    score3.setPosition(285,300);
    score3.setFillColor(sf::Color::Green);

    sf::Texture texture_back;
    if(!texture_back.loadFromFile("Textures/wall.jpg")) {return 1;}
    texture_back.setRepeated(true);

    sf::Sprite back,back2;
    back.setTexture(texture_back);
    back2.setTexture(texture_back);
    back2.setPosition(0,-600);

    sf::Texture texture_hero;
    if(!texture_hero.loadFromFile("Textures/harold.png")) {return 1;}

    sf::Texture texture_platform;
    if(!texture_platform.loadFromFile("Textures/platform.png")) {return 1;}

    std::vector<std::unique_ptr<Elements>> objects;

    objects.emplace_back(std::make_unique<Platform>());
    objects[0]->setPosition(rand()%800,500);
    objects[0]->setTexture(texture_platform);
    objects[0]->setScale(0.35,0.35);
    objects[0]->setspeedy(100);

    objects.emplace_back(std::make_unique<Platform>());
    objects[1]->setPosition(rand()%800,400);
    objects[1]->setTexture(texture_platform);
    objects[1]->setScale(0.35,0.35);
    objects[1]->setspeedy(100);

    objects.emplace_back(std::make_unique<Platform>());
    objects[2]->setPosition(rand()%800,300);
    objects[2]->setTexture(texture_platform);
    objects[2]->setScale(0.35,0.35);
    objects[2]->setspeedy(100);

    objects.emplace_back(std::make_unique<Platform>());
    objects[3]->setPosition(rand()%800,200);
    objects[3]->setTexture(texture_platform);
    objects[3]->setScale(0.35,0.35);
    objects[3]->setspeedy(100);

    objects.emplace_back(std::make_unique<Platform>());
    objects[4]->setPosition(rand()%800,100);
    objects[4]->setTexture(texture_platform);
    objects[4]->setScale(0.35,0.35);
    objects[4]->setspeedy(100);

    objects.emplace_back(std::make_unique<Platform>());
    objects[5]->setPosition(rand()%800,0);
    objects[5]->setTexture(texture_platform);
    objects[5]->setScale(0.35,0.35);

    auto player=dynamic_cast<Player*>(objects.emplace_back(std::make_unique<Player>()).get());
    player->setTexture(texture_hero);
    player->setScale(1.6,1.6);
    player->setPosition(400,600-player->getGlobalBounds().height);
    player->setTextureRect({0,0,29,52});

    for(unsigned int i=0;i<6;i++)
    {
        objects[i]->setspeedx(50);
    }

    sf::Vector2f gravity({0,1600});
    sf::Vector2f gravity2({0,0.07});

    sf::Clock clock;
    sf::Time time;

    bool wascol=false;
    bool wasstarted=false;

    while(window.isOpen())
    {
        wascol=false;
        wasstarted=false;
        player->setPosition(400,600-player->getGlobalBounds().height);
        for(int i=0;i<6;i++)
        {
            objects[i]->setspeedy(100);
            objects[i]->setTexture(texture_platform);
        }
        Platform::setcounter(0);

        while(true)
        {
            clock.restart();
            sf::Event event;
            while (window.pollEvent(event))
            {

                if (event.type == sf::Event::Closed)
                    window.close();

                player->setspeedx(0);
                player->setTextureRect({0,0,29,52});

                if(wascol)
                {
                    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
                    {
                        player->addtospeed({0,-600});
                        wasstarted=true;
                    }
                }

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                {
                    player->setspeedx(-500);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                {
                    player->setspeedx(500);
                }
            }

            window.clear(sf::Color::Black);

            window.draw(back);
            window.draw(back2);

            player->addtospeed(gravity*time.asSeconds());

            for(int i=0;i<6;i++)
            {
                objects[i]->addtospeed(gravity2*time.asSeconds());
            }

            back.move({0,0.018});
            back2.move({0,0.018});

            if(back.getPosition().y>=600)
                back.setPosition(0,-600);

            if(back2.getPosition().y>=600)
                back2.setPosition(0,-600);

            wascol=false;

            if(player->getGlobalBounds().top + player->getGlobalBounds().height >= window.getSize().y)
            {
                wascol=true;
            }

            if(wasstarted==false)
            {
                Platform::setcounter(0);
            }

            if(wasstarted==true)
            {
                if(player->floorCollision({0,0,800,600}))
                    break;
            }

            for(auto it=objects.begin();it!=objects.end();it++)
            {
                if(it!=objects.end()-1)
                {
                    if(player->Collision(&*it))
                    {
                        wascol=true;
                    }
                }
            }

            for(auto &el : objects)
            {
                el->windowCollision({0,0,800,600});
                el->update(time);
                window.draw(*el);
            }

            std::ostringstream ss;
            ss<<"SCORE: "<<Platform::getcounter();
            score.setString(ss.str());
            window.draw(score);

            // end the current frame
            window.display();
            time = clock.getElapsedTime();
        }
        while(true)
        {
            bool exit=false;
            sf::Event event;
            while (window.pollEvent(event))
            {
                if(event.type == sf::Event::Closed)
                    window.close();

                if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
                {
                    exit=true;
                    break;
                }

            }
            if(exit)
            {
                break;
            }
            window.clear(sf::Color::Black);
            std::ostringstream ss2,ss3;
            ss2<<"YOUR SCORE: "<<Platform::getcounter();
            score2.setString(ss2.str());
            window.draw(score2);
            std::ofstream wfile("score.txt");
            if(wfile.is_open())
            {
                if(Platform::getcounter()>best)
                    best=Platform::getcounter();

                wfile<<best;
            }
            wfile.close();
            ss3<<"YOUR BEST: "<<best;
            score3.setString(ss3.str());
            window.draw(score3);
            window.display();
        }
    }
    return 0;
}
