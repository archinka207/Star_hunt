#ifndef GAMEOBJ_HPP_
#define GAMEOBJ_HPP_

#include <memory>
#include <SFML/Graphics.hpp>

class GameObj {
public:
  GameObj();
  void Init(float pos_x, float pos_y, float speed, float angle , std::string file, sf::Vector2f centre);
  void Draw(sf::RenderWindow &window);
  sf::FloatRect GetBounds();

protected:
  float speed;
  static constexpr float pi = 3.14159265;
  float pos_x;
  float pos_y;
  float angle;
  sf::String file; 
  // center it is object center
  sf::Vector2f centre;
  inline static sf::Texture texture;
  sf::Sprite obj;
};

#endif
