#pragma once
#include <SFML/Graphics.hpp>
#include "VerletSolver.h"

class Level
{
public:
	virtual void Load();
	virtual void Update(float deltaTime, sf::RenderWindow& window);

protected:
	float time = 0.0f;

};

class Level01 : public Level
{
public:
	virtual void Update(float deltaTime, sf::RenderWindow& window) override;

protected:
	const int maxNumOfObjects = 20;
	const float spawnCooldown = 1.0f;
	float currentSpawnTime = 0.0f;
	int numOfObjects = 0;

	VerletSolver solver;
	sf::CircleShape background;

};

class Level02 : public Level
{
public:
	virtual void Load() override;
	virtual void Update(float deltaTime, sf::RenderWindow& window) override;

protected:
	VerletSolver solver;

};