#pragma once
#include "IA.h"

class Button : public Interactives
{
	sf::Vector2f OriginalSize;
	sf::RoundedRectangleShape ButtonShape;
	sf::Text ButtonText;
	sf::Font font;

public:
	Button(sf::Vector2f size, float radius, unsigned int cornerPointCount, std::string text);

	virtual void SetPosition(sf::Vector2f position);
	virtual void SetSize(sf::Vector2f size);

	/**
	* @brief Changes the object's theme to be equivalent to the selected theme.
	*/
	virtual void SetTheme();

	/**
	* @brief Draws the Interactive object on the screen.
	*/
	virtual void Draw();

	/**
	* @brief Checks if the cursor is on the object.
	*
	* @return boolean
	*/
	virtual bool CheckHover(const sf::Vector2i mouse) const;

	/**
	* @brief Updates any changes to the object in the current frame.
	*/
	virtual void update();

};