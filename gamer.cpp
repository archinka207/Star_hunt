#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
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
float angle_sped = 250.f;
float angle = 90;
float gamer_sped = 0;
float grifer_time;
const float pi = 3.14159265;
const float gamer_max_sped = 2;
const float gamer_min_sped = -2;

sf::Sprite gamer;
sf::Texture gamerTexture;
sf::Clock grifer_clock;
sf::Clock bullet_clock;
long double  bullet_time;

void Gamer::Init() {
  gamerTexture.loadFromFile("image/triangle.png");
  gamerTexture.setSmooth(true);
  gamer.setTexture(gamerTexture);
  gamer.setPosition(gamer_x,gamer_y);
  gamer.setOrigin(sf::Vector2f(15.f,15.f));
}

void Gamer::Update(float time , sf::FloatRect map_rect) {
  bullet_time = bullet_clock.getElapsedTime().asSeconds();
  //передвижение 
  grifer_time = grifer_clock.getElapsedTime().asMilliseconds();
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
  if (bullet_time > 1.0f && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
    bullet_clock.restart();
    bullet_arr.emplace_back(gamer_x, gamer_y, angle);
  }
  for (Bullet &bullet : bullet_arr) {
    bullet.Update(time);
  }
  // тут заполняю и обновляю массив гриферов 
  if (grifer_time > 3000) {
    grifer_clock.restart();
    grifer_arr.emplace_back();
  }
  for (Grifer &grifer : grifer_arr) {
    grifer.Update(time);
  }


  cout << "bullet_arr.size() = " << bullet_arr.size() << endl;
  cout << "grifer_arr.size() = " << grifer_arr.size() << endl;
  // чек на столкновение грифера и пули
  for (size_t i = 0; i < grifer_arr.size(); i++) {
    for (size_t j = 0; j < bullet_arr.size(); j++) {
      if (bullet_arr[j].GetBounds().intersects(grifer_arr[i].GetBounds())) {
        grifer_arr.erase(grifer_arr.begin() + i);
        bullet_arr.erase(bullet_arr.begin() + j);
        --i;
        break;
      }
    }
  }
  // чек на выход из карты
  for (size_t i = 0; i < bullet_arr.size(); ++i) {
    if (!bullet_arr[i].GetBounds().intersects(map_rect)) {
      bullet_arr.erase(bullet_arr.begin() + i);
      --i;
    }
  }
}


void Gamer::Draw(sf::RenderWindow &window) {
  window.draw(gamer);
  // тут отрисовываю пули
  for (Bullet &bullet : bullet_arr) {
    bullet.Draw(window);
  }
  // тут отрисовываю гриферов
  for (Grifer &grifer : grifer_arr) {
    grifer.Draw(window);
  }
}
