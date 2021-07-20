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

void Gamer::Init(float pos_x, float pos_y, float speed, float angle , std::string file, sf::Vector2f centre) {
  this -> pos_x = pos_x;
  this -> pos_y = pos_y;
  this -> speed  = speed;
  this -> angle = angle;
  this -> file = file;
  this -> centre = centre;
  if (texture.getSize().x != 0 || texture.loadFromFile("image/" + file +".png")) {
    obj.setTexture(texture);
  }
  obj.setOrigin(centre);
  obj.setPosition(pos_x,pos_y);
  obj.setRotation(angle);
}
float Gamer::Get_pos_x() {return pos_x;}
float Gamer::Get_pos_y() {return pos_y;}
float Gamer::Get_angle() {return angle;}