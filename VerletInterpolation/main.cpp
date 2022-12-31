#include <SFML/Graphics.hpp>
#include <iostream>
#include "Verlet/VerletSolver.h"

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(960, 720), "SFML Application", sf::Style::Default, settings);

    VerletSolver vs;
    vs.Start();

    const int FPS = 60;
    window.setFramerateLimit(FPS);
    const float deltaTimeLimit = 1.0f / FPS;
    sf::Clock clock;

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                window.close();
        }

        float deltaTime = clock.getElapsedTime().asSeconds();
        if (deltaTime > deltaTimeLimit)
        {
            deltaTime = deltaTimeLimit;
        }

        clock.restart();

        window.clear();

        vs.Update(deltaTime);
        vs.Render(window);

        window.display();
    }

}