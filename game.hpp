#ifndef GAME_HPP_
#define GAME_HPP_

#include <SFML/Graphics.hpp>
#include "gamestate.hpp"

namespace Game {
  void ChangeState(GameState *state);
  void Update();
  void Draw(sf::RenderWindow &window);
}

#endif
