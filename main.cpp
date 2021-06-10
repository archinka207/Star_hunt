#include <SFML/Graphics.hpp>
#include <iostream>
#include "gamer.hpp"
#include <math.h> 
using namespace std;
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");

    InitGamer();

    sf::Time sleepTime = sf::milliseconds(40);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        UpdateGamer();

        //-----
        window.clear();
        DrawGamer(window);
        window.display();
        sf::sleep(sleepTime);
    }

}
