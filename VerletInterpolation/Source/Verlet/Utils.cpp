#include "Verlet/Utils.h"
#include <stdlib.h>

float Utils::RandRange(float min, float max)
{
	return min + static_cast<float>(rand()) * static_cast<float>(max - min) / RAND_MAX;
}

sf::Color Utils::GetRandomColor(float t)
{
	const float r = sin(t);
	const float g = sin(t + 0.33f * 2.0f * 3.14);
	const float b = sin(t + 0.66f * 2.0f * 3.14);
	return { static_cast<uint8_t>(255.0f * r * r),
			static_cast<uint8_t>(255.0f * g * g),
			static_cast<uint8_t>(255.0f * b * b) };
}
