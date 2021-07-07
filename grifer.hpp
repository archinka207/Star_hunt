#ifndef GRIFER_HPP_
#define GRIFER_HPP_
#include <SFML/Graphics.hpp>

class Grifer {
public:
    Grifer();
    void Update(float time);
    void Draw(sf::RenderWindow &window);
    sf::FloatRect GetBounds();
private:
    float grifer_sped = rand()%8+20;
    float grifer_angle = rand()%360;
    float grifer_x = rand()%700;
    float grifer_y = rand()%700;
    sf::Sprite grifer;
    inline static sf::Texture griferTexture;
};
#endif