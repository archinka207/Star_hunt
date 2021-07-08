#include <SFML/Graphics.hpp>
#include <math.h>
#include "bullet.hpp"

Bullet::Bullet(float pos_x, float pos_y, float speed, float angle , std::string file, sf::Vector2f centre) {
  Init(pos_x, pos_y, speed, angle , file, centre);
}

void Bullet::Update(float time) {
  pos_x = pos_x + ((speed * cos(angle*pi/180)*time));
  pos_y = pos_y + ((speed * sin(angle*pi/180)*time));
  obj.setPosition(pos_x, pos_y);
}