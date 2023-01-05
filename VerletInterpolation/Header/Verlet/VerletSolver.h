#pragma once
#include <vector>
#include "Verlet/CircleObject.h"

class VerletSolver
{
public:
	VerletSolver();

	void Start();
	void Update(float deltaTime);
	void Render(sf::RenderWindow& window);

protected:
	void ApplyGravity();
	void ApplyConstraints();
	void SolveCollisions();
	void UpdateObjects(float deltaTime);

	float RandRange(float min, float max);

	std::vector<CircleObject> objects;
	sf::CircleShape background;

	int numOfObjects = 8;

};