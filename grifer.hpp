#ifndef GRIFER_HPP_
#define GRIFER_HPP_
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include "gameobj.hpp"

class Grifer : public GameObj {
public:
    Grifer(float pos_x, float pos_y, float speed, float angle , std::string file, sf::Vector2f centre);
    void Update(float time);
};
#endif