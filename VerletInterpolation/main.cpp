#include <SFML/Graphics.hpp>
#include <iostream>

#include "Verlet/Level.h"
#include "Verlet/Input.h"

#define ScreenWidth 960
#define ScreenHeight 720

int main()
{
    srand(time(NULL));
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(ScreenWidth, ScreenHeight), "SFML Application", sf::Style::Default, settings);

    Level02 level;
    level.Load();

    Input input;

    const int FPS = 60;
    window.setFramerateLimit(FPS);
    const float deltaTime = 1.0f / FPS;

    while (window.isOpen()) {

        sf::Event event;
        input.Update(window);

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                window.close();
            
            input.PollEvent(event);
        }

        level.Update(deltaTime, window);
        window.display();
    }

}