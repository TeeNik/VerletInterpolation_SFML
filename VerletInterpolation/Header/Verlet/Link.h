#pragma once

class VerletObject;

class Link
{
public:
	Link(VerletObject& obj1, VerletObject& obj2);
	void Apply();

protected:
	VerletObject& object1;
	VerletObject& object2;
	const float targetDist;
};