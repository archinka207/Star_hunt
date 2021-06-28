#ifndef GRIFER_HPP_
#define GRIFER_HPP_
#include <SFML/Graphics.hpp>

class Grifer {
public:
    Grifer();
    void Update(float time);
    void Draw(sf::RenderWindow &window);
    bool Rect(sf::Rect<int> &rectangle);
};
#endif