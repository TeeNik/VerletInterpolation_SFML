#include "Objects/CircleObject.h"

CircleObject::CircleObject()
{
	shape.setRadius(50.f);
	shape.setPosition(100.f, 100.f);
	shape.setFillColor(sf::Color::Blue);
	shape.setOutlineThickness(10.f);
	shape.setOutlineColor(sf::Color(250, 150, 100));

	position_currect = {480,180};
	position_old = { 480,180 };

	shape.setOrigin(50, 50);
}

void CircleObject::Update(float deltaTime)
{
	const Vector2 gravity(0, 10);
	Accelerate(gravity);
	//ApplyConstraints();
	
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

void CircleObject::ApplyConstraints()
{
	const Vector2 position(800, 450);
	const float radius = 400;

	const Vector2 toObj = position_currect - position;
	const float dist = toObj.length();
	if (dist > radius - 50.0f)
	{
		const Vector2 n = toObj / dist;
		position_currect = position + n * (dist - 50.0f);
	}
}
