#pragma once

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