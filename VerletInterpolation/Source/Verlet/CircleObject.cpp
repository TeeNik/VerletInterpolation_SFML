#include "Verlet/CircleObject.h"
#include <iostream>

CircleObject::CircleObject()
{
	shape.setRadius(radius);
	shape.setOrigin(radius, radius);
	shape.setFillColor(sf::Color::Blue);
	//shape.setOutlineThickness(10.f);
	//shape.setOutlineColor(sf::Color(250, 150, 100));

	position_currect = {650,180};
	position_old = { 650,180 };


	std::cout << "CircleObject constructor\n";
}

CircleObject::CircleObject(const CircleObject& co)
{
	shape = co.shape;
	position_currect = co.position_currect;
	position_old = co.position_old;
	std::cout << "CircleObject copy constructor\n";
}

CircleObject::CircleObject(const Vector2& initialPosition) : 
	position_currect(initialPosition),
	position_old(initialPosition)
{
	shape.setRadius(radius);
	shape.setOrigin(radius, radius);
	shape.setFillColor(sf::Color::Blue);
}

void CircleObject::Update(float deltaTime)
{
	const Vector2 gravity(0, 1000);
	//Accelerate(gravity);
	//ApplyConstraints();
	
	const Vector2 velocity = position_currect - position_old;
	//std::cout << position_currect.x << "  " << position_currect.y << "  " << velocity.y << std::endl;
	position_old = position_currect;
	const Vector2 acc = acceleration * deltaTime * deltaTime;
	position_currect = position_currect + velocity + acc;
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
	const Vector2 position(480, 360);
	const float constraintRadius = 320;

	const Vector2 toObj = position - position_currect;
	const float dist = toObj.length();
	if (dist > constraintRadius - 50.0f)
	{
		const Vector2 n = toObj / dist;
		position_currect = position - n * (constraintRadius - radius);
	}
}
