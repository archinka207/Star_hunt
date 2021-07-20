#ifndef GAMEOBJ_HPP_
#define GAMEOBJ_HPP_

#include <memory>
#include <SFML/Graphics.hpp>

class GameObj {
public:
  GameObj();
  //GameObj(GameObj& other);
  virtual void Init(float pos_x, float pos_y, float speed, float angle, std::string file, sf::Vector2f centre) = 0;
  void Draw(sf::RenderWindow &window);
  sf::FloatRect GetBounds();

protected:
  float speed;
  static constexpr float pi = 3.14159265;
  float pos_x;
  float pos_y;
  float angle;
  sf::String file; 
  sf::Vector2f centre;
  //inline static sf::Texture texture;
  sf::Sprite obj;
};

#endif
