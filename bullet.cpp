#include <memory>
#include <SFML/Graphics.hpp>
#include "bullet.hpp"
#include <math.h>
#include <iostream>

sf::Texture bullet_texture;
sf::Sprite bullet;
const int bullet_spide = -4;
const float pi = 3.14159265;
float bullet_x;
float bullet_y;
float bullet_angle;
sf::Rect<int> bullet_rect(sf::Vector2<int>(bullet_x, bullet_y), sf::Vector2<int>(10,15));

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
  std::cout << bullet_angle << std::endl;
}

void Bullet::Update(long double time) {
  bullet_x = bullet_x + ((bullet_spide * cos(bullet_angle*pi/180)*time));
  bullet_y = bullet_y + ((bullet_spide * sin(bullet_angle*pi/180)*time));
  bullet.setPosition(bullet_x,bullet_y);
  bullet_rect.left = bullet_x;
  bullet_rect.top = bullet_y;
}

sf::Rect<int> Bullet::Get_rect() {
  return bullet_rect;
}

void Bullet::Draw(sf::RenderWindow &window) {
  window.draw(bullet);
}
