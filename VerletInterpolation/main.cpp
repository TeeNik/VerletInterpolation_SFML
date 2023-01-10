#include <SFML/Graphics.hpp>
#include <iostream>
#include "Verlet/Level.h"

int main()
{
    srand(time(NULL));
    sf::ContextSettings settings;
    settings.antialiasingLevel = 1;

    sf::RenderWindow window(sf::VideoMode(960, 720), "SFML Application", sf::Style::Default, settings);

    Level01 level;

    const int FPS = 60;
    window.setFramerateLimit(FPS);
    const float deltaTime = 1.0f / FPS;

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                window.close();
        }
        level.Update(deltaTime, window);

        window.display();
    }

}