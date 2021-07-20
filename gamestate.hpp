#ifndef GAMESTATE_HPP_
#define GAMESTATE_HPP_

#include <vector>
#include <SFML/Graphics.hpp>
#include "bullet.hpp"
#include "grifer.hpp"
#include "gamer.hpp"

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
  void AddBullet(Bullet bullet);
private:
  sf::Texture map_t;
  sf::Sprite map;
  sf::Rect<int> map_rect = sf::Rect<int>(sf::Vector2<int>(0,0), sf::Vector2<int>(800,800));
  std::vector<Bullet> bullets;
  std::vector<Grifer> grifers;
  sf::Clock grifer_clock;
  sf::Font font;
  sf::Text text;
  static constexpr float grifer_tts = 1.0f;
  int player_scores = 0;
};

#endif
