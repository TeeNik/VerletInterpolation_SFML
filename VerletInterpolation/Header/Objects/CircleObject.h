#pragma once
#include <SFML/Graphics.hpp>

class CircleObject
{

public:
	CircleObject();

	void Update(float DeltaTime);
	void Render();

protected:
	sf::CircleShape Shape;


};