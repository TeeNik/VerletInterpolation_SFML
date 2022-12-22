#include "Objects/CircleObject.h"

CircleObject::CircleObject()
{
	Shape.setRadius(80.f);
	Shape.setPosition(100.f, 100.f);
	Shape.setFillColor(sf::Color::Blue);
}

void CircleObject::Update(float DeltaTime)
{
}

void CircleObject::Render(sf::RenderWindow& window)
{
	window.draw(Shape);
}
