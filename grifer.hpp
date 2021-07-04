#ifndef GRIFER_HPP_
#define GRIFER_HPP_
#include <SFML/Graphics.hpp>

class Grifer {
public:
    Grifer();
    void Update(long double time);
    void Draw(sf::RenderWindow &window);
    bool Rect (sf::Rect<int> &rectangle);
private:
    float grifer_sped = rand()%3+10;
    float grifer_angle;
    float grifer_x = rand()%700;
    float grifer_y = rand()%700;
    sf::Rect<int> grifer_rect = sf::Rect<int>(sf::Vector2<int>(grifer_x, grifer_y), sf::Vector2<int>(110, 300));
    sf::Sprite grifer;
    sf::Texture griferTexture;
};
#endif