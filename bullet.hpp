#ifndef BULLET_HPP_
#define BULLET_HPP_

#include <memory>
#include <SFML/Graphics.hpp>

class Bullet {
public:
  Bullet(float gamer_x, float gamer_y, float gamer_angle);
  void Update(float time);
  void Draw(sf::RenderWindow &window);
  sf::Rect<int> Get_rect();
};

#endif
