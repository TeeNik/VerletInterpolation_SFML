#include "Verlet/VerletSolver.h"
#include "Verlet/Utils.h"

VerletSolver::VerletSolver()
{
}

void VerletSolver::Start()
{
	//objects.reserve(numOfObjects);
	//
	//for (int i = 0; i < numOfObjects; ++i)
	//{
	//	const Vector2 pos(Utils::RandRange(300, 600), 180);
	//	const float radius = Utils::RandRange(10, 50);
	//	objects.emplace_back(pos, Utils::GetRandomColor(i), radius);
	//}

}

void VerletSolver::SpawnObject()
{
	const Vector2 pos(500, 180);
	const float radius = Utils::RandRange(10, 50);
	objects.emplace_back(pos, Utils::GetRandomColor(time), radius);
}

void VerletSolver::Update(float deltaTime)
{
	time += deltaTime;
	const int subSteps = 8;
	const float subDeltaTime = deltaTime / subSteps;

	for (int i = 0; i < subSteps; ++i)
	{
		ApplyGravity();
		SolveCollisions();
		ApplyConstraints();
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

	for (VerletObject& obj : objects)
	{
		obj.Render(window);
	}
}

void VerletSolver::ApplyGravity()
{
	const Vector2 gravity(0, 1000);
	for (VerletObject& obj : objects)
	{
		obj.Accelerate(gravity);
	}
}

void VerletSolver::ApplyConstraints()
{
	for (VerletObject& obj : objects)
	{
		const Vector2 position(480, 360);
		const float constraintRadius = 320;

		const Vector2 toObj = position - obj.position_currect;
		const float dist = toObj.length();
		if (dist > constraintRadius - obj.radius)
		{
			const Vector2 n = toObj / dist;
			obj.position_currect = position - n * (constraintRadius - obj.radius);
		}
	}
}

void VerletSolver::SolveCollisions()
{
	const float responseCoef = 0.75f;

	for (int i = 0; i < objects.size(); ++i)
	{
		VerletObject& co1 = objects[i];
		for (int j = i + 1; j < objects.size(); ++j)
		{
			VerletObject& co2 = objects[j];

			const Vector2 diff = co1.position_currect - co2.position_currect;
			const float dist = diff.length();
			const float sumRad = co1.radius + co2.radius;
			if (dist < sumRad)
			{
				const Vector2 n = diff / dist;
				const float delta = 0.5f * responseCoef * (dist - sumRad);

				const float massRatio1 = co1.radius / (co1.radius + co2.radius);
				const float massRatio2 = co2.radius / (co1.radius + co2.radius);

				co1.position_currect = co1.position_currect - n * massRatio2 * delta;
				co2.position_currect = co2.position_currect + n * massRatio1 * delta;
			}
		}
	}
}

void VerletSolver::UpdateObjects(float deltaTime)
{
	for (VerletObject& obj : objects)
	{
		obj.Update(deltaTime);
	}
}