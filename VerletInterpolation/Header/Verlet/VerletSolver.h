#pragma once
#include <vector>
#include "Verlet/VerletObject.h"
#include "Verlet/Constraint.h"

class VerletSolver
{
public:
	VerletSolver();

	void Start();
	VerletObject& SpawnObject();
	void Update(float deltaTime);
	void Render(sf::RenderWindow& window);
	
protected:
	void ApplyGravity();
	void ApplyConstraints();
	void SolveCollisions();
	void UpdateObjects(float deltaTime);

	std::vector<VerletObject> objects;
	sf::CircleShape background;
	
	//CircleConstraint CircleConstraint;
	RectConstraint Constraint;

	int numOfObjects = 8;
	float time = 0;

};