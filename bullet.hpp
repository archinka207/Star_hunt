#ifndef BULLET_HPP_
#define BULLET_HPP_

#include <memory>
#include <SFML/Graphics.hpp>

class Bullet {
public:
  Bullet(float gamer_x, float gamer_y, float gamer_angle);
  void Update(long double time);
  void Draw(sf::RenderWindow &window);
  sf::Rect<int> Get_rect();
private:
  static constexpr float bullet_spide = -300;
  static constexpr float pi = 3.14159265;
  float bullet_x;
  float bullet_y;
  float bullet_angle;
  sf::Rect<int> bullet_rect = sf::Rect<int>(sf::Vector2<int>(bullet_x, bullet_y), sf::Vector2<int>(10,15));
  inline static sf::Texture bullet_texture;
  sf::Sprite bullet;
};

#endif
