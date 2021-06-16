#ifndef GAME_HPP_
#define GAME_HPP_

#include <SFML/Graphics.hpp>
#include "gamestate.hpp"

void ChangeGameState(GameState *state);
void UpdateGame();
void DrawGame(sf::RenderWindow &window);

#endif
