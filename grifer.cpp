#include <SFML/Graphics.hpp>
#include "grifer.hpp"
#include <math.h>
#include <iostream>

Grifer::Grifer() {
  sf::Vector2f new_grifer_centre(5.0f, 7.0f);
  Init(rand()%800, rand()%800, rand()%8+20, rand()%360, "buhlo", new_grifer_centre);
}

void Grifer::Init(float pos_x, float pos_y, float speed, float angle , std::string file, sf::Vector2f centre) {
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


Grifer::Grifer(const Grifer& other) {
  this -> pos_x = other.pos_x;
  this -> pos_y = other.pos_y;
  this -> speed  = other.speed;
  this -> angle = other.angle;
  this -> file = other.file;
  this -> centre = other.centre;
  
  this->texture = other.texture;
  this->obj = other.obj;
  this->obj.setTexture(texture);
}


void Grifer::Update(float time) {
  pos_x = pos_x + ((speed * cos(angle*pi/180)*time));
  pos_y = pos_y + ((speed * sin(angle*pi/180)*time));
  obj.setPosition(pos_x, pos_y);
}