#include <memory>
#include <SFML/Graphics.hpp>
#include "game.hpp"

namespace Game {
  GameState* current_game_state = nullptr;

  GameState& GetCurrentGameStateGeneric() {
    return *current_game_state;
  }

  void ChangeGameState(GameState *state) {
    if (current_game_state) {
      delete current_game_state;
    }

    current_game_state = state;
  }

  void Update(float time) {
    current_game_state->Update(time);
  }

  void Draw(sf::RenderWindow &window) {
    current_game_state->Draw(window);
  }
}