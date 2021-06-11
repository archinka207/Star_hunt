#ifndef GAMER_HPP_
#define GAMER_HPP_

#include <SFML/Graphics.hpp>

const int gamer_max_sped = 6;
const int gamer_min_sped = -6;

namespace Gamer {
  void Init();
  void Update();
  void Draw(sf::RenderWindow &window);
}

#endif
