#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <vector>
#include "gamer.hpp"

void Gamer::Update(float time) {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    if (speed < gamer_max_sped) {
      speed -= 0.3;
    }
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
    if (speed > gamer_min_sped) {
      speed += 0.3;
    }
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    angle -= angle_sped * time;
    if (angle < -360) {
      angle = 0;
    }
    obj.setRotation(angle);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
    angle += angle_sped * time;
    if (angle > 360) {
      angle = 0;
    }
    obj.setRotation(angle);
  }

  if (speed > 0) {
    speed -= 0.25;
  }
  else if (speed < 0) {
    speed += 0.25;
  }
  pos_x = pos_x + ((speed * cos(angle*pi/180)*time));
  pos_y = pos_y + ((speed * sin(angle*pi/180)*time));
  obj.setPosition(pos_x,pos_y);
}

float Gamer::Get_pos_x() {return pos_x;}
float Gamer::Get_pos_y() {return pos_y;}
float Gamer::Get_angle() {return angle;}