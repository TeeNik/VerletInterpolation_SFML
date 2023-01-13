#pragma once
#include "Verlet/VerletObject.h"

class VerletObject;

class Constraint
{
public:
	virtual void ApplyConstraint(VerletObject& object) = 0;
};

class CircleConstraint : public Constraint
{
public:
	CircleConstraint(Vector2 position, float radius);
	virtual void ApplyConstraint(VerletObject& object) override;
protected:
	const Vector2 position;
	const float radius;
};

class RectConstraint : public Constraint
{
public:
	RectConstraint();
	virtual void ApplyConstraint(VerletObject& object) override;

	Vector2 position;
	Vector2 bounds;
};