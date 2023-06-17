#ifndef _CIRCULAR_BUTTON_
#define _CIRCULAR_BUTTON_

#include "IA.h"

class CircularButton : public Interactives
{
	sf::CircleShape ButtonShape;
	sf::Texture ButtonTexture;
	sf::Sprite ButtonIcon;
	float OriginalRadius;

public:
	CircularButton(float radius, const std::string image);

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

#endif