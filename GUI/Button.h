#pragma once
#include "IA.h"

class Button : public Interactives
{
	sf::RectangleShape ButtonShape;
	sf::Text ButtonText;
	sf::Font font;
	bool hover;

public:
	Button(sf::Vector2f position, sf::Vector2f size, std::string text);

	virtual void Draw();
};