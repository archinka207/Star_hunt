#include <memory>
#include <SFML/Graphics/Rect.hpp>
#include <math.h>
#include <iostream>
#include "gameobj.hpp"

GameObj::GameObj() {}

void GameObj::Init(float pos_x, float pos_y, float speed, float angle , std::string file, sf::Vector2f centre) {
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

void GameObj:: Draw(sf::RenderWindow &window) {
  window.draw(obj);
}

sf::FloatRect GameObj::GetBounds() {
  return obj.getGlobalBounds();
}