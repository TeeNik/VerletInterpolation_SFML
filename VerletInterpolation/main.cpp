#include <SFML/Graphics.hpp>
int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(960, 720), "SFML Application", sf::Style::Default, settings);
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

        window.clear();
        window.draw(shape);
        window.display();
    }

}