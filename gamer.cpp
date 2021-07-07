#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <iostream>
#include <math.h>
#include <vector>

#include "gamer.hpp"
#include "bullet.hpp"
#include "grifer.hpp"
#include "game.hpp"

using namespace std;

float gamer_x = 400.f;
float gamer_y = 400.f;
float angle_sped = 250.f;
float angle = 90;
float gamer_sped = 0;
const float pi = 3.14159265;
const float gamer_max_sped = 2;
const float gamer_min_sped = -2;

sf::Sprite gamer;
sf::Texture gamerTexture;

sf::Clock bullet_clock;

void Gamer::Init() {
  gamerTexture.loadFromFile("image/triangle.png");
  gamerTexture.setSmooth(true);
  gamer.setTexture(gamerTexture);
  gamer.setPosition(gamer_x,gamer_y);
  gamer.setOrigin(sf::Vector2f(15.f,15.f));
}

void Gamer::Update(float time) {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    if (gamer_sped < gamer_max_sped) {
      gamer_sped -= 0.3;
    }
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
    if (gamer_sped > gamer_min_sped) {
      gamer_sped += 0.3;
    }
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
     angle -= angle_sped * time;
     if (angle < -360) {
       angle = 0;
     }
     gamer.setRotation(angle);
    }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
     angle += angle_sped * time;
     if (angle > 360) {
         angle = 0;
     }
     gamer.setRotation(angle);
  }

  if (gamer_sped > 0) {
      gamer_sped -= 0.25;
  }
  else if (gamer_sped < 0) {
      gamer_sped += 0.25;
  }
  gamer_x = gamer_x + ((gamer_sped * cos(angle*pi/180)*time));
  gamer_y = gamer_y + ((gamer_sped * sin(angle*pi/180)*time));
  gamer.setPosition(gamer_x,gamer_y);
  // конец передвижения
  //тут заполняю и обновляю массив пуль
  float bullet_time = bullet_clock.getElapsedTime().asSeconds();
  if (bullet_time > 1.0f && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
    bullet_clock.restart();
    Game::GetCurrentGameState<PlayingState>().AddBullet(Bullet(gamer_x, gamer_y, angle));
  }
}


void Gamer::Draw(sf::RenderWindow &window) {
  window.draw(gamer);
}
