#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.hpp"
#include "bullet.hpp"
#include "gamestate.hpp"

using namespace std;


int main()
{
  sf::Clock clock;
  sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
  Game::ChangeGameState(new MenuState()); //press enter
  long double  time;

  while (window.isOpen()) {

    time = clock.getElapsedTime().asSeconds();
    clock.restart();

    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    Game::Update(time);

    window.clear();
    Game::Draw(window);
    window.display();
  }
}
