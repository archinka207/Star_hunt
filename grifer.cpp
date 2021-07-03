#include <SFML/Graphics.hpp>
#include "grifer.hpp"
#include <math.h>

sf::Sprite grifer;
sf::Texture griferTexture;
float grifer_sped = rand()%3+10;
float grifer_angle;
float grifer_x = rand()%700;
float grifer_y = rand()%700;
const float pi = 3.14159265;

sf::Rect<int> grifer_rect(sf::Vector2<int>(grifer_x,grifer_y), sf::Vector2<int>(11,30));

Grifer::Grifer() {
    griferTexture.loadFromFile("image/buhlo.png");
    grifer.setTexture(griferTexture);
    grifer.setPosition(sf::Vector2f(grifer_x, grifer_y));
}

void Grifer::Update(float time) {
    grifer_x = grifer_x + (grifer_sped * cos(grifer_angle*pi/180)* time);
    grifer_y= grifer_y+ (grifer_sped * sin(grifer_angle*pi/180)* time);
    grifer.setPosition(grifer_x,grifer_y);
    grifer_rect.left = grifer_x;
    grifer_rect.top = grifer_y;
}

bool Grifer::Rect (sf::Rect<int> &rectangle) {
    if (grifer_rect.intersects(rectangle)) return true;
    else return false;
}
void Grifer::Draw(sf::RenderWindow &window) {
    window.draw(grifer);
}