#pragma once
#include <SFML/Graphics.hpp>

struct Vector2
{
	float x;
	float y;

	Vector2() : x(0), y(0) {}
	Vector2(float xValue, float yValue) : x(xValue), y(yValue) {}

	Vector2 operator+(const Vector2& a) const
	{
		return Vector2(x + a.x, y + a.y);
	}

	Vector2 operator-(const Vector2& a) const
	{
		return Vector2(x - a.x, y - a.y);
	}

	Vector2 operator*(float a) const
	{
		return Vector2(x * a, y * a);
	}

	Vector2 operator/(float a) const
	{
		return Vector2(x / a, y / a);
	}

	float length() const
	{
		return std::sqrt(x * x + y * y);
	}
};

class VerletObject
{

public:
	VerletObject();
	//CircleObject(const CircleObject& co);
	VerletObject(const Vector2& initialPosition, sf::Color color, float radius);

	void Update(float deltaTime);
	void Render(sf::RenderWindow& window);
	void Accelerate(Vector2 acc);

	float radius = 50.0f;
	Vector2 position_currect;

protected:
	sf::CircleShape shape;

	Vector2 position_old;
	Vector2 acceleration;
};