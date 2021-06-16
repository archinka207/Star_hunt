#include <memory>
#include <SFML/Graphics.hpp>
#include "game.hpp"

GameState* current_game_state = nullptr;

void Game::ChangeGameState(GameState *state) {
  if (current_game_state) {
    delete current_game_state;
  }

  current_game_state = state;
}

void Game::Update() {
  current_game_state->Update();
}

void Game::Draw(sf::RenderWindow &window) {
  current_game_state->Draw(window);
}
