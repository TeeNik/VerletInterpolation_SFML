#include "Verlet/Link.h"
#include "Verlet/VerletObject.h"

Link::Link(VerletObject& obj1, VerletObject& obj2) :
	object1(obj1), object2(obj2),
	targetDist((obj1.position_currect - obj2.position_currect).length())
{
}

void Link::Apply()
{
	const Vector2 diff = object1.position_currect - object2.position_currect;
	const float dist = diff.length();
	const Vector2 n = diff / dist;
	const float delta = 0.5f * (targetDist - dist);
	//if (delta > 0.0001)
	{
		object1.position_currect = object1.position_currect + n * delta;
		object2.position_currect = object2.position_currect - n * delta;
	}
}
