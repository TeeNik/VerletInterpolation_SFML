#include "Verlet/Input.h"

InputData Input::Data = InputData();

void Input::Update(const sf::RenderWindow& window)
{
    Data.isLMBPressed = false;
    Data.isRMBPressed = false;
    const sf::Vector2i mp = sf::Mouse::getPosition(window);
    Data.mousePos = Vector2(mp.x, mp.y);
}

void Input::PollEvent(const sf::Event& event)
{
    if (event.mouseButton.button == sf::Mouse::Left)
    {
        Data.isLMBPressed = true;
    }
    else if (event.mouseButton.button == sf::Mouse::Right)
    {
        Data.isRMBPressed = true;
    }
}
