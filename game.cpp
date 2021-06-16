#include <memory>
#include <SFML/Graphics.hpp>
#include "game.hpp"

GameState *current_game_state = nullptr;

void ChangeGameState(GameState *state) {
  if (current_game_state) delete current_game_state;
  current_game_state = state;
}

void UpdateGame() {
  current_game_state->Update();
}

void DrawGame(sf::RenderWindow &window) {
  current_game_state->Draw(window);
}
