#include <SFML/Graphics.hpp>
#include "gamer.hpp"

float gamer_x = 400.f;
float gamer_y = 400.f;
int angle_sped = 5;
int gamer_sped = 0;
sf::CircleShape gamer(20.f, 3);

void InitGamer() {
  gamer.setPosition(gamer_x,gamer_y);
  gamer.setFillColor(sf::Color::White);
  gamer.setOrigin(sf::Vector2f(20.f,20.f));
}

void UpdateGamer() {
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
    gamer.setRotation(angle_sped);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
    angle_sped += 3;
    gamer.setRotation(angle_sped);
  }

  if (gamer_sped > 0) {
      gamer_sped -= 1;
  }
  else if (gamer_sped < 0) {
      gamer_sped += 1;
  }
  gamer_x += gamer_sped * (angle_sped / 10);
  gamer_y += gamer_sped;
  gamer.setPosition(gamer_x,gamer_y);
}

void DrawGamer(sf::RenderWindow &window) {
  window.draw(gamer);
}
