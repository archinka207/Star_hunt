#include <memory>
#include <SFML/Graphics/Rect.hpp>
#include <math.h>
#include <iostream>
#include "gameobj.hpp"

GameObj::GameObj() {}

void GameObj:: Draw(sf::RenderWindow &window) {
  window.draw(obj);
}

sf::FloatRect GameObj::GetBounds() {
  return obj.getGlobalBounds();
}