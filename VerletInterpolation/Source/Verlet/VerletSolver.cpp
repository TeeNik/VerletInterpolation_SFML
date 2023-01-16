#include "Verlet/VerletSolver.h"
#include "Verlet/Utils.h"

VerletSolver::VerletSolver() //: CircleConstraint(Vector2(480, 360), 320)
{
}

VerletSolver::~VerletSolver()
{
	for (VerletObject* obj : objects)
	{
		delete obj;
	}
	objects.clear();
	
	for (Link* link : links)
	{
		delete link;
	}
	links.clear();
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

VerletObject* VerletSolver::SpawnObject(Vector2 pos, sf::Color color, float radius)
{
	VerletObject* object = new VerletObject(pos, color, radius);
	objects.push_back(object);
	return object;
}

void VerletSolver::CreateLink(VerletObject& obj1, VerletObject& obj2)
{
	Link* link = new Link(obj1, obj2);
	links.push_back(link);
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
		UpdateLinks(subDeltaTime);
	}
}

void VerletSolver::Render(sf::RenderWindow& window)
{
	for (VerletObject* obj : objects)
	{
		obj->Render(window);
	}
}

void VerletSolver::ApplyGravity()
{
	const Vector2 gravity(0, 1000);
	for (VerletObject* obj : objects)
	{
		obj->Accelerate(gravity);
	}
}

void VerletSolver::ApplyConstraints()
{
	for (VerletObject* obj : objects)
	{
		Constraint.ApplyConstraint(*obj);
	}
}

void VerletSolver::SolveCollisions()
{
	const float responseCoef = 0.75f;

	for (int i = 0; i < objects.size(); ++i)
	{
		VerletObject& co1 = *objects[i];
		for (int j = i + 1; j < objects.size(); ++j)
		{
			VerletObject& co2 = *objects[j];

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
	for (VerletObject* obj : objects)
	{
		obj->Update(deltaTime);
	}
}

void VerletSolver::UpdateLinks(float deltaTime)
{
	for(Link* link : links)
	{
		link->Apply();
	}
}

void VerletSolver::SolveCollisionOpt()
{

	//std::sort(objects.begin(), objects.end(), [](std::unique_ptr<VerletObject>& a, std::unique_ptr<VerletObject>& b))

	const float responseCoef = 0.75f;

	for (int i = 0; i < objects.size(); ++i)
	{
		VerletObject& co1 = *objects[i];
		for (int j = i + 1; j < objects.size(); ++j)
		{
			VerletObject& co2 = *objects[j];

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
