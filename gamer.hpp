#ifndef GAMER_HPP_
#define GAMER_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include "gameobj.hpp"

class Gamer : public GameObj{
public:
  void Update(float time);
  float Get_pos_x();
  float Get_pos_y();
  float Get_angle();
private:
  float angle_sped = 250.f;
  const float gamer_max_sped = 2;
  const float gamer_min_sped = -2;
};

#endif
