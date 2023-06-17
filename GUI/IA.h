#ifndef _INTERACTIVES_
#define _INTERACTIVES_

#include "../DEFS.h"

class Interactives
{
protected:
	sf::Vector2f Position;
	sf::Vector2f OriginalSize;
	sf::Color PrimaryColor;

	UI::ActionType action;
	bool hover;

	static sf::RenderWindow* window;
public:
	static void SetRenderWindow(sf::RenderWindow& window)
	{
		Interactives::window = &window;
	}

	/**
	* @brief Draws the Interactive object on the screen.
	*/
	virtual void Draw() = 0;

	/**
	* @brief Checks if the cursor is on the object.
	* 
	* @return boolean
	*/
	virtual bool CheckHover(const sf::Vector2i mouse) const = 0;

	void SetHover(bool hover);

	void SetAction(UI::ActionType action);

	virtual void SetPosition(sf::Vector2f position);

	virtual void SetSize(sf::Vector2f size) = 0;

	UI::ActionType GetAction() const { return action; }

	/**
	* @brief Updates any changes to the object in the current frame.
	*/
	virtual void update() = 0;
};

#endif