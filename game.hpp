#ifndef GAME_HPP_
#define GAME_HPP_

#include <SFML/Graphics.hpp>
#include "gamestate.hpp"

namespace Game {
  void ChangeGameState(GameState *state);
  void Update(float  time);
  void Draw(sf::RenderWindow &window);
}

#endif
