#ifndef BULLET_HPP_
#define BULLET_HPP_

#include <memory>
#include <SFML/Graphics.hpp>
#include "gameobj.hpp"

class Bullet : public GameObj {
public:
    Bullet(float pos_x, float pos_y, float speed, float angle , std::string file, sf::Vector2f centre);
    void Update(float time);
};

#endif
