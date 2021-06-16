#ifndef BULLET_HPP_
#define BULLET_HPP_

#include <memory>
#include <SFML/Graphics.hpp>

class Bullet {
public:
  Bullet(float gamer_x, float gamer_y, float gamer_angle);
  void Update();
  void Draw(sf::RenderWindow &window);
};

#endif
