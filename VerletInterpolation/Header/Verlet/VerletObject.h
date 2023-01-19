#pragma once
#include <SFML/Graphics.hpp>
#include "Verlet/Math.h"

class VerletObject
{

public:
	VerletObject();
	//CircleObject(const CircleObject& co);
	VerletObject(const Vector2& initialPosition, sf::Color color, float radius);
	~VerletObject();

	void Update(float deltaTime);
	void Render(sf::RenderWindow& window);
	void Accelerate(Vector2 acc);
	
	Vector2 GetVelocity(float deltaTime) const;
	void SetVelocity(Vector2 velocity, float deltaTime);

	float radius = 50.0f;
	Vector2 position_currect;

protected:
	sf::CircleShape shape;

	Vector2 position_old;
	Vector2 acceleration;
};