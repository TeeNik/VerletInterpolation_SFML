#pragma once
#include <SFML/Graphics.hpp>

struct Vector2
{
	float x;
	float y;

	Vector2() : x(0), y(0) {}
	Vector2(float xValue, float yValue) : x(xValue), y(yValue) {}

	Vector2 operator+(const Vector2& a)
	{
		return Vector2(x + a.x, y + a.y);
	}

	Vector2 operator-(const Vector2& a)
	{
		return Vector2(x - a.x, y - a.y);
	}

	Vector2 operator*(float a)
	{
		return Vector2(x * a, y * a);
	}
};

class CircleObject
{

public:
	CircleObject();

	void Update(float deltaTime);
	void Render(sf::RenderWindow& window);

	void Accelerate(Vector2 acc);

protected:
	sf::CircleShape shape;

	Vector2 position_currect;
	Vector2 position_old;
	Vector2 acceleration;

};