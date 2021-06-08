#include <SFML/Graphics.hpp>
#include <iostream>
#include "gamer.cpp"
using namespace std;
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");

    float gamer_x = 400.f;
    float gamer_y = 400.f;
    int gamer_max_sped = 6;
    int gamer_min_sped = -6;
    int angle_sped = 5;
    int gamer_sped = 0;
    sf::CircleShape gamer(20.f, 3);

    gamer.setPosition(gamer_x,gamer_y);
    gamer.setFillColor(sf::Color::White);
    gamer.setOrigin(sf::Vector2f(10.f,10.f));

    sf::Time sleepTime = sf::milliseconds(40);
    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                if (gamer_sped < gamer_max_sped) {
                    gamer_sped -= 2;
                }
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                if (gamer_sped > gamer_min_sped) {
                    gamer_sped += 2;
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                angle_sped -= 3;
                gamer.setRotation(angle_sped);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                angle_sped += 3;
                gamer.setRotation(angle_sped);
            }
        }
        if (gamer_sped > 0) {
            gamer_sped -= 1;
        }
        else if (gamer_sped < 0) {
            gamer_sped += 1;
        }
        gamer_x += gamer_sped * (angle_sped / 10);
        gamer_y += gamer_sped;
        gamer.setPosition(gamer_x,gamer_y);

        //-----
        window.clear();
        window.draw(gamer);
        window.display();
        sf::sleep(sleepTime);
    }

}
