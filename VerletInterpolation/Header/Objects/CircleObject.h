#pragma once
#include <SFML/Graphics.hpp>

class CircleObject
{

public:
	CircleObject();

	void Update(float DeltaTime);
	void Render(sf::RenderWindow& window);

protected:
	sf::CircleShape Shape;


};