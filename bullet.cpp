#include <memory>
#include <SFML/Graphics.hpp>
#include "bullet.hpp"
#include "gamer.hpp"
#include <math.h>

sf::Texture bullet_texture;
sf::Sprite bullet;
const int bullet_spide = 6;
const float pi = 3.14159265;
float bullet_x;
float bullet_y;
float bullet_angle;

Bullet::Bullet(float gamer_x_pos, float gamer_y_pos, float gamer_angle) {
  bullet_x = gamer_x_pos;
  bullet_y = gamer_y_pos;
  bullet_angle = gamer_angle;
  bullet_texture.loadFromFile("image/bullet.png");
  //bulet_texture.setSmooth(true);
  bullet.setTexture(bullet_texture);
  bullet.setPosition(bullet_x,bullet_y);
}

void Bullet::Update() {
  bullet_x = bullet_x + (bullet_spide * cos(bullet_angle*pi/180));
  bullet_y = bullet_y + (bullet_spide * sin(bullet_angle*pi/180));
  bullet.setPosition(bullet_x,bullet_y);
}

void Bullet::Draw(sf::RenderWindow &window) {
  window.draw(bullet);
}
