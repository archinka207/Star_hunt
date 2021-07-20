#include "gamestate.hpp"
#include "gamer.hpp"
#include "game.hpp"

sf::Clock bullet_clock;
float bullet_time;
Gamer gamer;

void MenuState::Update(float time) {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
    Game::ChangeGameState(new PlayingState());
  }
}

void MenuState::Draw(sf::RenderWindow &window) {
  window.clear(sf::Color(100, 200, 100, 255));
}


PlayingState::PlayingState() {
  sf::Vector2f new_gamer_centre(15.0f, 15.0f);
  
  gamer.Init(400, 400, 100 , 0, "triangle", new_gamer_centre);
  map_t.loadFromFile("image/map.png");
  map.setTexture(map_t);
  font.loadFromFile("VDS/VDS_Italic_New.ttf");
  text.setFont(font);
  text.setCharacterSize(30);
  text.setPosition(650, 25);
}

void PlayingState::Update(float time) {
  //text update
  std::string scorses_str = std::to_string(player_scores);
  text.setString("scores  " + scorses_str);
  //update game objects
  gamer.Update(time);
  for (Bullet &b : bullets) {
    b.Update(time);
  }
  for (Grifer &g : grifers) {
    g.Update(time);
  }

  // swan new bullet
  float bullet_time = bullet_clock.getElapsedTime().asSeconds();
  if (bullet_time > 1.0f && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
    bullet_clock.restart();
    sf::Vector2f new_bullet_centre(5.0f, 7.0f);
    Game::GetCurrentGameState<PlayingState>().AddBullet(Bullet(gamer.Get_pos_x(), 
                                                        gamer.Get_pos_y(), 200.0f, 
                                                        gamer.Get_angle(), "bullet", 
                                                        new_bullet_centre));
  }
  //bullet and grifer collision check
  for (size_t i = 0; i < grifers.size(); ++i) {
    for (size_t j = 0; j < bullets.size(); ++j) {
      if (grifers[i].GetBounds().intersects(bullets[j].GetBounds())) {
        grifers.erase(grifers.begin() + i);
        bullets.erase(bullets.begin() + j);
        --i;
        player_scores += 1;
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
  window.draw(text);
  gamer.Draw(window);
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
