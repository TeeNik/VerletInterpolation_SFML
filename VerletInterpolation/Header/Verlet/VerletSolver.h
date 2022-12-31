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
	void ApplyConstraints();
	void SolveCollisions();

	std::vector<CircleObject> objects;
	sf::CircleShape background;

	int numOfObjects = 1;

};