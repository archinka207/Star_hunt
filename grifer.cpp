#include <SFML/Graphics.hpp>
#include "grifer.hpp"
#include <math.h>
#include <iostream>

Grifer::Grifer() {
  this -> pos_x = rand()%100+700;
  this -> pos_y = rand()%100+700;
  this -> speed = rand()%8+20;
  this -> angle = rand()%360;
  this -> file = "buhlo";
  if (texture.getSize().x != 0 || texture.loadFromFile("image/" + file +".png")) {
    obj.setTexture(texture);
  }
  obj.setPosition(pos_x,pos_y);
  obj.setRotation(angle);
}

void Grifer::Update(float time) {
  pos_x = pos_x + ((speed * cos(angle*pi/180)*time));
  pos_y = pos_y + ((speed * sin(angle*pi/180)*time));
  obj.setPosition(pos_x, pos_y);
}