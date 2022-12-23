#include <SFML/Graphics.hpp>
#include <iostream>
#include "Objects/CircleObject.h"

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(960, 720), "SFML Application", sf::Style::Default, settings);

    CircleObject co;
    

    window.setFramerateLimit(30);
    const float deltaTimeLimit = 1.0f / 30;
    sf::Clock clock;

    //sf::CircleShape shape;
    //shape.setRadius(80.f);
    //shape.setPosition(100.f, 100.f);
    //shape.setFillColor(sf::Color::Blue);

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

        co.Update(deltaTime);
        co.Render(window);

        //window.draw(shape);
        window.display();
    }

}