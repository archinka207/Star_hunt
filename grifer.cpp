#include <SFML/Graphics.hpp>
#include "grifer.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <math.h>
#include <iostream>

const float pi = 3.14159265;

Grifer::Grifer() {
    if (griferTexture.getSize().x != 0 || griferTexture.loadFromFile("image/buhlo.png")) {
        grifer.setTexture(griferTexture);
    }
    grifer.setPosition(sf::Vector2f(grifer_x, grifer_y));
}

void Grifer::Update(float time) {
    grifer_x = grifer_x + (grifer_sped * cos(grifer_angle*pi/180) * time);
    grifer_y = grifer_y + (grifer_sped * sin(grifer_angle*pi/180) * time);
    grifer.setPosition(grifer_x, grifer_y);
}

sf::FloatRect Grifer::GetBounds () {
    return grifer.getGlobalBounds();
}

void Grifer::Draw(sf::RenderWindow &window) {
    window.draw(grifer);
}