#include "gamestate.hpp"
#include "gamer.hpp"
#include "game.hpp"


void MenuState::Update(float time) {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
    Game::ChangeGameState(new PlayingState());
  }
}

void MenuState::Draw(sf::RenderWindow &window) {
  window.clear(sf::Color(100, 200, 100, 255));
}

PlayingState::PlayingState() {
  Gamer::Init();
  map_t.loadFromFile("image/map.png");
  map.setTexture(map_t);
}

void PlayingState::Update(float time) {
  Gamer::Update(time , map.getGlobalBounds());
}

void PlayingState::Draw(sf::RenderWindow &window) {
  window.draw(map);
  Gamer::Draw(window);
}
