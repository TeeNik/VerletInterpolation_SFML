#include "Verlet/Level.h"

void Level::Load()
{
}

void Level::Update(float deltaTime, sf::RenderWindow& window)
{
}

void Level01::Load()
{
}

void Level01::Update(float deltaTime, sf::RenderWindow& window)
{
	time += deltaTime;
	currentSpawnTime += deltaTime;

	if (currentSpawnTime > spawnCooldown && numOfObjects < maxNumOfObjects)
	{
		++numOfObjects;
		currentSpawnTime = 0.0f;
		solver.SpawnObject();
	}

	solver.Update(deltaTime);
	window.clear();
	solver.Render(window);
}
