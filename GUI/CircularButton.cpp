#include "CircularButton.h"
#include <math.h>

CircularButton::CircularButton(float radius, const std::string image)
{
	Position = sf::Vector2f(0, 0);
	OriginalRadius = radius;

	ButtonShape.setRadius(radius);
	ButtonTexture.loadFromFile(image);
	ButtonIcon.setTexture(ButtonTexture);
	ButtonIcon.setScale(0.05, 0.05);

	SetTheme();

	hover = false;
}

void CircularButton::SetPosition(sf::Vector2f position)
{
	sf::Vector2f Center = position;
	Center.x += ButtonIcon.getLocalBounds().width * ButtonIcon.getScale().y - OriginalRadius;
	Center.y += ButtonIcon.getLocalBounds().height * ButtonIcon.getScale().y - OriginalRadius;

	Position = position;
	ButtonShape.setPosition(Position);
	ButtonIcon.setPosition(Center);
}

void CircularButton::SetSize(sf::Vector2f size)
{
	const float radius = size.x > size.y ? size.y / 2 : size.x / 2;
	ButtonShape.setRadius(radius);
	const sf::Vector2f scale = ButtonIcon.getScale();
	const float Rchange = scale.x * ((radius - OriginalRadius) / OriginalRadius) + scale.x;
	ButtonIcon.setScale(sf::Vector2f(Rchange, Rchange));
	OriginalRadius = radius;
}

/**
* @brief Changes the object's theme to be equivalent to the selected theme.
*/
void CircularButton::SetTheme()
{
	const UI::theme& theme = UI::GUI.themes[UI::GUI.index];
	PrimaryColor = theme.BG_color;
	ButtonShape.setFillColor(PrimaryColor);
}

/**
* @brief Draws the Interactive object on the screen.
*/
void CircularButton::Draw()
{
	update();
	Interactives::window->draw(ButtonShape);
	Interactives::window->draw(ButtonIcon);
}

/**
* @brief Checks if the cursor is on the object.
*
* @return boolean
*/
bool CircularButton::CheckHover(const sf::Vector2i mouse) const
{
	sf::Vector2i Center = sf::Vector2i(ButtonShape.getPosition());
	Center.x += int(OriginalRadius);
	Center.y += int(OriginalRadius);

	const float radius = sqrt(powf(mouse.x - Center.x, 2) + pow(mouse.y - Center.y, 2));
	const float curr_radius = ButtonShape.getRadius();

	if (radius > curr_radius) return false;

	return true;
}

/**
* @brief Updates any changes to the object in the current frame.
*/
void CircularButton::update()
{

	if (hover == true)
	{
		ButtonShape.setFillColor(UI::GUI.themes[UI::GUI.index].Accent_color);
	}
	else
	{
		ButtonShape.setFillColor(UI::GUI.themes[UI::GUI.index].BG_color);
	}
}