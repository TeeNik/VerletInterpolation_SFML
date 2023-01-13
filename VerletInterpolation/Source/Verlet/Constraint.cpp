#include "Verlet/Constraint.h"
#include "Verlet/VerletObject.h"

#define ScreenWidth 960
#define ScreenHeight 720

CircleConstraint::CircleConstraint(Vector2 pos, float rad) :
	position(pos), radius(rad)
{
}

void CircleConstraint::ApplyConstraint(VerletObject& object)
{
	const Vector2 toObj = position - object.position_currect;
	const float dist = toObj.length();
	if (dist > radius - object.radius)
	{
		const Vector2 n = toObj / dist;
		object.position_currect = position - n * (radius - object.radius);
	}
}

RectConstraint::RectConstraint()
{
	bounds = Vector2(ScreenWidth * 0.5f, ScreenHeight * 0.5f);
	position = bounds;
}

void RectConstraint::ApplyConstraint(VerletObject& object)
{
	const Vector2 min = position - bounds;
	const Vector2 max = position + bounds;

	const Vector2 objPos = object.position_currect;
	Vector2 newPos = object.position_currect;
	const float objRad = object.radius;

	if (min.x > objPos.x - objRad)
	{
		const float dist = objPos.x - min.x;
		object.position_currect.x += objRad - dist;
	}
	else if (max.x < objPos.x + objRad)
	{
		const float dist = max.x - objPos.x;
		object.position_currect.x = objPos.x - objRad;
	}
	if (min.y > objPos.y - objRad)
	{
		const float dist = objPos.y - min.y;
		object.position_currect.y += objRad - dist;
	}
	else if (max.y < objPos.y + objRad)
	{
		const float dist = max.y - objPos.y;
		object.position_currect.y -= objRad - dist;
	}
}
