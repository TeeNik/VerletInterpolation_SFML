#pragma once
#include <SFML/Graphics.hpp>

class Utils
{
public:
	static float RandRange(float min, float max);
	static sf::Color GetRandomColor(float t);
};