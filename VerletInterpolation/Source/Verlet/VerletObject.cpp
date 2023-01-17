#include "Verlet/VerletObject.h"
#include <iostream>
#include "Verlet/Utils.h"

VerletObject::VerletObject()
{
	shape.setRadius(radius);
	shape.setOrigin(radius, radius);
	shape.setFillColor(sf::Color::Blue);
	//shape.setOutlineThickness(10.f);
	//shape.setOutlineColor(sf::Color(250, 150, 100));

	position_currect = {650,180};
	position_old = { 650,180 };

	std::cout << "VerletObject constructor\n";
}

//CircleObject::CircleObject(const CircleObject& co)
//{
//	shape = co.shape;
//	position_currect = co.position_currect;
//	position_old = co.position_old;
//	std::cout << "CircleObject copy constructor\n";
//}

VerletObject::VerletObject(const Vector2& initialPosition, sf::Color color, float radius) :
	position_currect(initialPosition),
	position_old(initialPosition)
{
	this->radius = radius;
	shape.setRadius(radius);
	shape.setOrigin(radius, radius);
	shape.setFillColor(color);

	std::cout << "VerletObject constructor\n";
}

VerletObject::~VerletObject()
{
	std::cout << "VerletObject destructor\n";
}

void VerletObject::Update(float deltaTime)
{
	const Vector2 velocity = position_currect - position_old;
	//std::cout << position_currect.x << "  " << position_currect.y << "  " << velocity.y << std::endl;
	position_old = position_currect;
	position_currect = position_currect + velocity + acceleration * deltaTime * deltaTime;
	acceleration = Vector2{0,0};
}

void VerletObject::Render(sf::RenderWindow& window)
{
	shape.setPosition(position_currect.x, position_currect.y);
	window.draw(shape);
}

void VerletObject::Accelerate(Vector2 acc)
{
	acceleration = acceleration + acc;
}

void VerletObject::SetVelocity(Vector2 velocity, float deltaTime)
{
	position_old = position_currect - (velocity * deltaTime);
}