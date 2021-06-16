#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.hpp"
#include "gamestate.hpp"

int main()
{
  sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");

<<<<<<< HEAD
  ChangeGameState(new MenuState()); //press enter //дэбил на русском пиши

  sf::Time sleepTime = sf::milliseconds(40);
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
=======
    Game::ChangeState(new MenuState()); //press enter

    sf::Time sleepTime = sf::milliseconds(40);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        Game::Update();

        //-----
        window.clear();
        Game::Draw(window);
        window.display();
        sf::sleep(sleepTime);
>>>>>>> f98ec2c90f1a5160acfa18305599fbb5636f6b05
    }

    UpdateGame();
    //-----
    window.clear();
    DrawGame(window);
    window.display();
    sf::sleep(sleepTime);
  }
}
