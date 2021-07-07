#include <memory>
#include <SFML/Graphics.hpp>
#include "bullet.hpp"
#include <math.h>
#include <iostream>


Bullet::Bullet(float gamer_x_pos, float gamer_y_pos, float gamer_angle) {
  bullet_x = gamer_x_pos;
  bullet_y = gamer_y_pos;
  bullet_angle = gamer_angle;
  bullet_texture.loadFromFile("image/bullet.png");
  //bulet_texture.setSmooth(true);
  bullet.setTexture(bullet_texture);
  bullet.setOrigin(sf::Vector2f(5.f,7.5f));
  bullet.setPosition(bullet_x,bullet_y);
  bullet.setRotation(bullet_angle + 270);
  
}

void Bullet::Update(float time) {
  bullet_x = bullet_x + ((bullet_spide * cos(bullet_angle*pi/180)*time));
  bullet_y = bullet_y + ((bullet_spide * sin(bullet_angle*pi/180)*time));
  bullet.setPosition(bullet_x,bullet_y);
}

sf::FloatRect Bullet::GetBounds() {
  return bullet.getGlobalBounds();
}

void Bullet::Draw(sf::RenderWindow &window) {
  window.draw(bullet);
}
