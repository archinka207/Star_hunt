#ifndef GAMER_HPP_
#define GAMER_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include "gameobj.hpp"

class Gamer : public GameObj{
public:
  void Update(float time);
  void Init(float pos_x, float pos_y, float speed, float angle, std::string file, sf::Vector2f centre);
  float Get_pos_x();
  float Get_pos_y();
  float Get_angle();
private:
  inline static sf::Texture texture;
  float angle_sped = 250.f;
  const float gamer_max_sped = 2;
  const float gamer_min_sped = -2;
};

#endif
