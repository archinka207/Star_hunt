#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.hpp"
#include "bullet.hpp"
#include "gamestate.hpp"

using namespace std;

int main()
{

  sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");

  Game::ChangeGameState(new MenuState()); //press enter

  sf::Time sleepTime = sf::milliseconds(40);
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }



    Game::Update();

    window.clear();
    Game::Draw(window);
    window.display();
    sf::sleep(sleepTime);
  }
}
