#include "Verlet/Level.h"
#include "Verlet/Utils.h"
#include "Verlet/Input.h"
#include <iostream>

void Level::Load()
{
}

void Level::Update(float deltaTime, sf::RenderWindow& window)
{
	time += deltaTime;
}

void Level01::Update(float deltaTime, sf::RenderWindow& window)
{
	Level::Update(deltaTime, window);

	currentSpawnTime += deltaTime;

	if (currentSpawnTime > spawnCooldown && numOfObjects < maxNumOfObjects)
	{
		++numOfObjects;
		currentSpawnTime = 0.0f;

		const Vector2 pos(500, 180);
		const float radius = Utils::RandRange(10, 50);
		const sf::Color color = Utils::GetRandomColor(time);

		VerletObject& obj = *solver.SpawnObject(pos, color, radius);

		const float angle = 30.0f * sin(time) + 3.14f * 0.5f;
		obj.SetVelocity(Vector2(cos(angle), sin(angle) * 100), deltaTime);
	}

	solver.Update(deltaTime);
	window.clear();

	background.setFillColor(sf::Color::White);
	background.setRadius(320);
	background.setPosition(480, 360);
	background.setOrigin(320, 320);
	background.setPointCount(128);

	window.draw(background);
	solver.Render(window);
}

void Level02::Load()
{
	const Vector2 pos1(300, 200);
	VerletObject& obj1 = *solver.SpawnObject(pos1, sf::Color::White, 10);

	const Vector2 pos2(300, 400);
	VerletObject& obj2 = *solver.SpawnObject(pos2, sf::Color::White, 10);

	solver.CreateLink(obj1, obj2);
}

void Level02::Update(float deltaTime, sf::RenderWindow& window)
{
	Level::Update(deltaTime, window);


	const InputData& input = Input::GetInputData();
	std::cout << input.mousePos.x << "  " << input.mousePos.y << std::endl;

	solver.Update(deltaTime);
	window.clear();

	solver.Render(window);
}
