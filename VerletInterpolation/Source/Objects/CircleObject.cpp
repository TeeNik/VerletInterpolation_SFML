#include "Objects/CircleObject.h"

CircleObject::CircleObject()
{
	shape.setRadius(80.f);
	shape.setPosition(100.f, 100.f);
	shape.setFillColor(sf::Color::Blue);
	shape.setOutlineThickness(10.f);
	shape.setOutlineColor(sf::Color(250, 150, 100));

	position_currect = {};
	position_old = {};
}

void CircleObject::Update(float deltaTime)
{
	const Vector2 gravity(0, 1000);
	Accelerate(gravity);
	
	const Vector2 velocity = position_currect - position_old;
	position_old = position_currect;
	position_currect = position_currect + velocity + acceleration * deltaTime * deltaTime;
	acceleration = Vector2{0,0};
}

void CircleObject::Render(sf::RenderWindow& window)
{
	shape.setPosition(position_currect.x, position_currect.y);
	window.draw(shape);
}

void CircleObject::Accelerate(Vector2 acc)
{
	acceleration = acceleration + acc;
}
