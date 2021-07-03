#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <vector>

#include "gamer.hpp"
#include "bullet.hpp"
#include "grifer.hpp"

using namespace std;

vector<Bullet> bullet_arr;
vector<Grifer> grifer_arr;

float gamer_x = 400.f;
float gamer_y = 400.f;
float angle_sped = 0.5;
float angle = 90;
float gamer_sped = 0;
float grifer_time;
const float pi = 3.14159265;
const float gamer_max_sped = 2;
const float gamer_min_sped = -2;

sf::Sprite gamer;
sf::Texture gamerTexture;
sf::Clock grifer_clock;

void Gamer::Init() {
  gamerTexture.loadFromFile("image/triangle.png");
  gamerTexture.setSmooth(true);
  gamer.setTexture(gamerTexture);
  gamer.setPosition(gamer_x,gamer_y);
  gamer.setOrigin(sf::Vector2f(15.f,15.f));
}

void Gamer::Update(float time) {
  //cout << gamer_x << "\t" << gamer_y << endl;
  //передвижение 
  grifer_time = grifer_clock.getElapsedTime().asMilliseconds();
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    if (gamer_sped < gamer_max_sped) {
      gamer_sped -= 0.5;
    }
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
    if (gamer_sped > gamer_min_sped) {
      gamer_sped += 0.5;
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
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
    bullet_arr.push_back(Bullet(gamer_x,gamer_y,angle));
  }
  if (bullet_arr.size() != 0) {
    for (int i = 0; i < bullet_arr.size(); i++) {
      bullet_arr[i].Update(time);
    }
  }
  // тут заполняю и обновляю массив гриферов 
  if (grifer_time > 3000) {
    grifer_clock.restart();
    grifer_arr.push_back(Grifer());
  }
  if (grifer_arr.size() != 0) {
    for (int i = 0; i < grifer_arr.size(); i++) {
      grifer_arr[i].Update(time);
    }
  }
  cout << "bullet_arr.size() = " << bullet_arr.size() << endl;
  cout << "grifer_arr.size() = " << grifer_arr.size() << endl;
  // чек на столкновение грифера и пули
  if((grifer_arr.size() != 0) && (bullet_arr.size() != 0)) {
    for (int i = 0; i < grifer_arr.size(); i++) {
      for (int j = 0; j < bullet_arr.size(); j++) {
        sf::Rect<int> rect  = bullet_arr[j].Get_rect() ;
        if (grifer_arr[i].Rect(rect)) {
          grifer_arr.erase(grifer_arr.begin() + i);
          bullet_arr.erase(bullet_arr.begin() + j);
        }
      }
    }
  }
}

void Gamer::Draw(sf::RenderWindow &window) {
  window.draw(gamer);
  // тут отрисовываю пули
  if (bullet_arr.size() != 0) {
    for (int i = 0; i < bullet_arr.size(); i++) {
      bullet_arr[i].Draw(window);
    }
  }
  // тут отрисовываю гриферов
  if (grifer_arr.size() != 0) {
    for (int i = 0; i < grifer_arr.size(); i++) {
      grifer_arr[i].Draw(window);
    }
  }
}
