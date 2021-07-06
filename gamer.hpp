#ifndef GAMER_HPP_
#define GAMER_HPP_

#include <SFML/Graphics.hpp>

namespace Gamer {

  void Init();
  void Update(long double time, const sf::Rect<int> & map_rectref);
  void Draw(sf::RenderWindow &window);
}

#endif
