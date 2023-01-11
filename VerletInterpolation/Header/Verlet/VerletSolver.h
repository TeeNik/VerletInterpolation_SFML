#pragma once
#include <vector>
#include "Verlet/VerletObject.h"

class VerletSolver
{
public:
	VerletSolver();

	void Start();
	void SpawnObject();
	void Update(float deltaTime);
	void Render(sf::RenderWindow& window);
	
protected:
	void ApplyGravity();
	void ApplyConstraints();
	void SolveCollisions();
	void UpdateObjects(float deltaTime);

	std::vector<VerletObject> objects;
	sf::CircleShape background;

	int numOfObjects = 8;
	float time = 0;

};