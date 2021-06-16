#ifndef GAMER_HPP_
#define GAMER_HPP_

#include <SFML/Graphics.hpp>

class Gamer {
public:
  const float pi = 3.14159265;
  const int gamer_max_sped = 6;
  const int gamer_min_sped = -6;

  void Init();
  void Update();
  void Draw(sf::RenderWindow &window);
};

#endif
