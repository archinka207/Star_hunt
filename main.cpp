#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.hpp"
#include "gamestate.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");

    ChangeGameState(new MenuState()); //press enter

    sf::Time sleepTime = sf::milliseconds(40);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        UpdateGame();

        //-----
        window.clear();
        DrawGame(window);
        window.display();
        sf::sleep(sleepTime);
    }
}
