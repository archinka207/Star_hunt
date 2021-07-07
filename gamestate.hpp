#ifndef GAMESTATE_HPP_
#define GAMESTATE_HPP_

#include <SFML/Graphics.hpp>

class GameState {
public:
  virtual void Update(float time) = 0;
  virtual void Draw(sf::RenderWindow &window) = 0;
  virtual ~GameState() = default;
};

class MenuState : public GameState {
public:
  void Update(float time);
  void Draw(sf::RenderWindow &window);
};

class PlayingState : public GameState {
public:
  PlayingState();
  void Update(float time);
  void Draw(sf::RenderWindow &window);
private:
  sf::Texture map_t;
  sf::Sprite map;
  sf::Rect<int> map_rect = sf::Rect<int>(sf::Vector2<int>(0,0), sf::Vector2<int>(800,800));

};

#endif
