#include <SFML/Graphics.hpp>
#include <math.h>
#include "bullet.hpp"

Bullet::Bullet(float pos_x, float pos_y, float speed, float angle , std::string file, sf::Vector2f centre) {
  Init(pos_x, pos_y, speed, angle +180, file, centre);
}

void Bullet::Init(float pos_x, float pos_y, float speed, float angle , std::string file, sf::Vector2f centre) {
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

Bullet::Bullet(const Bullet& other) {
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

void Bullet::Update(float time) {
  pos_x = pos_x + ((speed * cos(angle*pi/180)*time));
  pos_y = pos_y + ((speed * sin(angle*pi/180)*time));
  obj.setPosition(pos_x, pos_y);
}