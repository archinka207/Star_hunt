#ifndef GRIFER_HPP_
#define GRIFER_HPP_
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include "gameobj.hpp"

class Grifer : public GameObj {
    inline static sf::Texture texture;
public:
    Grifer();
    Grifer(const Grifer& other);
    void Update(float time);
    void Init(float pos_x, float pos_y, float speed, float angle, std::string file, sf::Vector2f centre);
};
#endif