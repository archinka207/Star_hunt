#include "gamestate.hpp"
#include "gamer.hpp"
#include "game.hpp"

void MenuState::Update() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
    ChangeGameState(new PlayingState());
  }
}

void MenuState::Draw(sf::RenderWindow &window) {
  window.clear(sf::Color(100, 200, 100, 255));
}

PlayingState::PlayingState() {
  InitGamer();
}

void PlayingState::Update() {
  UpdateGamer();
}

void PlayingState::Draw(sf::RenderWindow &window) {
  DrawGamer(window);
}
