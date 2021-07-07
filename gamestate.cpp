#include "gamestate.hpp"
#include "gamer.hpp"
#include "game.hpp"


void MenuState::Update(float time) {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
    Game::ChangeGameState(new PlayingState());
  }
}

void MenuState::Draw(sf::RenderWindow &window) {
  window.clear(sf::Color(100, 200, 100, 255));
}

PlayingState::PlayingState() {
  Gamer::Init();
  map_t.loadFromFile("image/map.png");
  map.setTexture(map_t);
}

void PlayingState::Update(float time) {
  //update game objects
  Gamer::Update(time);
  for (Bullet &b : bullets) {
    b.Update(time);
  }
  for (Grifer &g : grifers) {
    g.Update(time);
  }
  //bullet and grifer collision check
  for (size_t i = 0; i < grifers.size(); ++i) {
    for (size_t j = 0; j < bullets.size(); ++j) {
      if (grifers[i].GetBounds().intersects(bullets[j].GetBounds())) {
        grifers.erase(grifers.begin() + i);
        bullets.erase(bullets.begin() + j);
        --i;
        break;
      }
    }
  }
  //grifers out of bounds check
  for (size_t i = 0; i < grifers.size(); ++i) {
    if (!map.getGlobalBounds().intersects(grifers[i].GetBounds())) {
      grifers.erase(grifers.begin() + i);
      --i;
    }
  }
  //bullets out of bounds check
  for (size_t i = 0; i < bullets.size(); ++i) {
    if (!map.getGlobalBounds().intersects(bullets[i].GetBounds())) {
      bullets.erase(bullets.begin() + i);
      --i;
    }
  }
  //spawn new grifer
  if (grifer_clock.getElapsedTime().asSeconds() >= grifer_tts) {
    grifer_clock.restart();
    grifers.emplace_back();
  }
}

void PlayingState::Draw(sf::RenderWindow &window) {
  window.draw(map);
  Gamer::Draw(window);
  for (Bullet &b : bullets) {
    b.Draw(window);
  }
  for (Grifer &g : grifers) {
    g.Draw(window);
  }
}

void PlayingState::AddBullet(Bullet bullet) {
  bullets.push_back(bullet);
}
