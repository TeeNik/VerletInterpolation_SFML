#pragma once
#include <vector>
#include "Verlet/VerletObject.h"
#include "Verlet/Constraint.h"
#include "Verlet/Link.h"

class VerletSolver
{
public:
	VerletSolver();
	~VerletSolver();

	void Start();
	void Update(float deltaTime);
	void Render(sf::RenderWindow& window);

	VerletObject* SpawnObject(Vector2 pos, sf::Color color, float radius);
	void CreateLink(VerletObject& obj1, VerletObject& obj2);
	
protected:
	void ApplyGravity();
	void ApplyConstraints();
	void SolveCollisions();
	void UpdateObjects(float deltaTime);
	void UpdateLinks(float deltaTime);

	//Solve Collision Optimisation
	void SolveCollisionOpt();

	std::vector<VerletObject*> objects;
	std::vector<Link*> links;
	
	//CircleConstraint CircleConstraint;
	RectConstraint Constraint;

	int numOfObjects = 8;
	float time = 0;

};