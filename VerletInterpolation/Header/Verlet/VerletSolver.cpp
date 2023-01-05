#include "VerletSolver.h"

VerletSolver::VerletSolver()
{
}

void VerletSolver::Start()
{
	objects.reserve(numOfObjects);

	for (int i = 0; i < numOfObjects; ++i)
	{
		const Vector2 pos(RandRange(300, 600), 180);
		const float radius = RandRange(10, 50);
		objects.emplace_back(pos, sf::Color::Blue, radius);
	}

}

void VerletSolver::Update(float deltaTime)
{
	const int subSteps = 8;
	const float subDeltaTime = deltaTime / subSteps;

	for (int i = 0; i < subSteps; ++i)
	{
		ApplyGravity();
		ApplyConstraints();
		SolveCollisions();
		UpdateObjects(subDeltaTime);
	}
}

void VerletSolver::Render(sf::RenderWindow& window)
{
	background.setFillColor(sf::Color::White);
	background.setRadius(320);
	background.setPosition(480, 360);
	background.setOrigin(320, 320);
	background.setPointCount(128);
	window.draw(background);

	for (CircleObject& obj : objects)
	{
		obj.Render(window);
	}
}

void VerletSolver::ApplyGravity()
{
	const Vector2 gravity(0, 1000);
	for (CircleObject& obj : objects)
	{
		obj.Accelerate(gravity);
	}
}

void VerletSolver::ApplyConstraints()
{
	for (CircleObject& obj : objects)
	{
		const Vector2 position(480, 360);
		const float constraintRadius = 320;

		const Vector2 toObj = position - obj.position_currect;
		const float dist = toObj.length();
		if (dist > constraintRadius - 50.0f)
		{
			const Vector2 n = toObj / dist;
			obj.position_currect = position - n * (constraintRadius - obj.radius);
		}
	}
}

void VerletSolver::SolveCollisions()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		CircleObject& co1 = objects[i];
		for (int j = i + 1; j < objects.size(); ++j)
		{
			CircleObject& co2 = objects[j];

			const Vector2 diff = co1.position_currect - co2.position_currect;
			const float dist = diff.length();
			const float sumRad = co1.radius + co2.radius;
			if (dist < sumRad)
			{
				const Vector2 n = diff / dist;
				const float delta = sumRad - dist;
				co1.position_currect = co1.position_currect + n * 0.5f * delta;
				co2.position_currect = co2.position_currect - n * 0.5f * delta;
			}
		}
	}
}

void VerletSolver::UpdateObjects(float deltaTime)
{
	for (CircleObject& obj : objects)
	{
		obj.Update(deltaTime);
	}
}

float VerletSolver::RandRange(float min, float max)
{
	return min + static_cast<float>(rand()) * static_cast<float>(max - min) / RAND_MAX;
}
