#ifndef _INTERACTIVES_
#define _INTERACTIVES_

#include "../DEFS.h"

class Interactives
{
protected:
	sf::Vector2f Position;
	sf::Vector2f OriginalSize;
	sf::Color PrimaryColor;
	static sf::RenderWindow* window;
public:
	static void SetRenderWindow(sf::RenderWindow& window)
	{
		Interactives::window = &window;
	}

	virtual void Draw() = 0;
};

#endif