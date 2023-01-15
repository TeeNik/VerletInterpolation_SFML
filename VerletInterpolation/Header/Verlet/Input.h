#pragma once
#include <SFML/Graphics.hpp>
#include "Verlet/Math.h"

struct InputData
{
	bool isLMBPressed = false;
	bool isRMBPressed = false;
	Vector2 mousePos;
};

class Input
{
public:
	void Update(const sf::RenderWindow& window);
	void PollEvent(const sf::Event& event);

	static InputData GetInputData() { return Data; }

protected:
	static InputData Data;

};