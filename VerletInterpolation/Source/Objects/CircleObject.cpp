#include "Objects/CircleObject.h"
#include <iostream>

CircleObject::CircleObject()
{
	shape.setRadius(50.f);
	shape.setPosition(100.f, 100.f);
	shape.setFillColor(sf::Color::Blue);
	//shape.setOutlineThickness(10.f);
	//shape.setOutlineColor(sf::Color(250, 150, 100));

	position_currect = {480,180};
	position_old = { 480,180 };

	shape.setOrigin(50, 50);
}

void CircleObject::Update(float deltaTime)
{
	const Vector2 gravity(0, 1000);
	Accelerate(gravity);
	ApplyConstraints();
	
	const Vector2 velocity = position_currect - position_old;
	std::cout << position_currect.x << "  " << position_currect.y << "  " << velocity.y << std::endl;
	position_old = position_currect;
	const Vector2 acc = acceleration * deltaTime * deltaTime;
	position_currect = position_currect + velocity + acc;
	acceleration = Vector2{0,0};
}

void CircleObject::Render(sf::RenderWindow& window)
{
	sf::CircleShape back;
	back.setFillColor(sf::Color::White);
	back.setRadius(320);
	back.setPosition(480, 360);
	back.setOrigin(320, 320);
	back.setPointCount(128);
	window.draw(back);

	shape.setPosition(position_currect.x, position_currect.y);
	window.draw(shape);
}

void CircleObject::Accelerate(Vector2 acc)
{
	acceleration = acceleration + acc;
}

void CircleObject::ApplyConstraints()
{
	const Vector2 position(480, 360);
	const float radius = 320;

	const Vector2 toObj = position - position_currect;
	const float dist = toObj.length();
	if (dist > radius - 50.0f)
	{
		const Vector2 n = toObj / dist;
		position_currect = position - n * (radius - 50.0f);
	}
}
