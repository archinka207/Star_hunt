#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 600), "SFML works!");

    sf::Time sleepTime = sf::milliseconds(40);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        //-----
        window.clear();
        //window.draw(gamer2);
        window.display();
        sf::sleep(sleepTime);
    }

}
