#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(960, 720), "SFML Application", sf::Style::Default, settings);
    
    window.setFramerateLimit(30);
    sf::Clock clock;

    sf::CircleShape shape;
    shape.setRadius(80.f);
    shape.setPosition(100.f, 100.f);
    shape.setFillColor(sf::Color::Blue);

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                window.close();
        }

        const float deltaTime = clock.getElapsedTime().asMilliseconds();
        clock.restart();

        window.clear();
        window.draw(shape);
        window.display();
    }

}