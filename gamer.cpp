#include <SFML/Graphics.hpp>
#include <iostream>
#include "gamer.hpp"
#include <math.h>
using namespace std;
float gamer_x = 400.f;
float gamer_y = 400.f;
float angle_sped = 10;
float angle = 90;
float gamer_sped = 0;

sf::Sprite gamer;
sf::Texture gamerTexture;

void Gamer::Init() {
  gamerTexture.loadFromFile("image/triangle.png");
  gamerTexture.setSmooth(true);
  gamer.setTexture(gamerTexture);
  gamer.setPosition(gamer_x,gamer_y);
  gamer.setOrigin(sf::Vector2f(15.f,15.f));
}

void Gamer::Update() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    if (gamer_sped < gamer_max_sped) {
      gamer_sped -= 2;
    }
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
    if (gamer_sped > gamer_min_sped) {
      gamer_sped += 2;
    }
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
     angle -= angle_sped;
     if (angle < -360) {
       angle = 0;
     }
     gamer.setRotation(angle);
    }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
     angle += angle_sped;
     if (angle > 360) {
         angle = 0;
     }
     gamer.setRotation(angle);
  }

  if (gamer_sped > 0) {
      gamer_sped -= 1;
  }
  else if (gamer_sped < 0) {
      gamer_sped += 1;
  }

  gamer_x = gamer_x + (gamer_sped * cos(angle*pi/180));
  gamer_y = gamer_y + (gamer_sped * sin(angle*pi/180));

  gamer.setPosition(gamer_x,gamer_y);
}

void Gamer::Draw(sf::RenderWindow &window) {
  window.draw(gamer);
}

float Gamer::get_x() {
  return gamer_x;
}
float Gamer::get_y() {
  return gamer_y;
}
float Gamer::get_angle() {
  return angle;
}
