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
}

void PlayingState::Update(float time) {
  Gamer::Update(time);
}

void PlayingState::Draw(sf::RenderWindow &window) {
  Gamer::Draw(window);
}
