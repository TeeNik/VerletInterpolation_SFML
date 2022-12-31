#include "VerletSolver.h"

VerletSolver::VerletSolver()
{
}

void VerletSolver::Start()
{
	objects.resize(numOfObjects);
}

void VerletSolver::Update(float deltaTime)
{
	//SolveCollisions();

	for (CircleObject& obj : objects)
	{
		obj.Update(deltaTime);
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

void VerletSolver::ApplyConstraints()
{
}

void VerletSolver::SolveCollisions()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		CircleObject& co1 = objects[i];
		for (int j = 0; j < objects.size(); ++j)
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
				co2.position_currect = co2.position_currect + n * 0.5f * delta;
			}
		}
	}
}
