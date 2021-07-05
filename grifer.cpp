#include <SFML/Graphics.hpp>
#include "grifer.hpp"
#include <math.h>
#include <iostream>

const float pi = 3.14159265;

Grifer::Grifer() {
    if (griferTexture.getSize().x != 0 || griferTexture.loadFromFile("image/buhlo.png")) {
        grifer.setTexture(griferTexture);
    }
    grifer.setPosition(sf::Vector2f(grifer_x, grifer_y));
}

void Grifer::Update(long double time) {
    grifer_x = grifer_x + (grifer_sped * cos(grifer_angle*pi/180) * time);
    grifer_y = grifer_y + (grifer_sped * sin(grifer_angle*pi/180) * time);
    grifer.setPosition(grifer_x, grifer_y);
    grifer_rect.left = grifer_x;
    grifer_rect.top = grifer_y;
}

bool Grifer::Rect (sf::Rect<int> &rectangle) {
    return grifer_rect.intersects(rectangle);
}

void Grifer::Draw(sf::RenderWindow &window) {
    window.draw(grifer);
}