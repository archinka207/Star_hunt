#ifndef GAMER_HPP_
#define GAMER_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>

namespace Gamer {

  void Init();
  void Update(float time, sf::FloatRect map_rect);
  void Draw(sf::RenderWindow &window);
}

#endif
