#include <SFML/Graphics.hpp>
#include <iostream>
#include "gamer.hpp"
#include <math.h>
using namespace std;
float gamer_x = 400.f;
float gamer_y = 400.f;
float angle_sped = 8;
float gamer_sped = 0;

float pi = 3.14159265;
sf::RectangleShape gamer(sf::Vector2f(30.f, 30.f));

void Gamer::Init() {
  gamer.setPosition(gamer_x,gamer_y);
  gamer.setFillColor(sf::Color::White);
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
     angle_sped -= 3;
     if (angle_sped < -360) {
         angle_sped = 0;
     }
     gamer.setRotation(angle_sped);
    }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
     angle_sped += 3;
     if (angle_sped > 360) {
         angle_sped = 0;
     }
     gamer.setRotation(angle_sped);
  }

  if (gamer_sped > 0) {
      gamer_sped -= 1;
  }
  else if (gamer_sped < 0) {
      gamer_sped += 1;
  }

  gamer_x = gamer_x + (gamer_sped * cos(angle_sped*pi/180));
  gamer_y = gamer_y + (gamer_sped * sin(angle_sped*pi/180));

  gamer.setPosition(gamer_x,gamer_y);
  cout << angle_sped << endl;
}

void Gamer::Draw(sf::RenderWindow &window) {
  window.draw(gamer);
}
