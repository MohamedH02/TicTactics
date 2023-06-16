#include "Button.h"

Button::Button(sf::Vector2f size, float radius, unsigned int cornerPointCount, std::string text): ButtonShape(size, radius, cornerPointCount)
{
	OriginalSize = size;
	Position = sf::Vector2f(0, 0);
	PrimaryColor = UI::GUI.Secondary_color;


	ButtonShape.setFillColor(PrimaryColor);
	ButtonShape.setSize(OriginalSize);

	if (!font.loadFromFile(".\\Assets\\Fonts\\Montserrat\\static\\Montserrat-Medium.ttf"))
	{
		std::printf("Failed to load font.\n");
		exit(1);
	}
	ButtonText.setFont(font);
	ButtonText.setFillColor(UI::GUI.Text_color);
	ButtonText.setCharacterSize(unsigned int(40));
	ButtonText.setString(text);
	

	hover = false;
}

void Button::SetPosition(sf::Vector2f position)
{
	Position = position;
	ButtonShape.setPosition(Position);
	sf::Vector2f pos;
	pos.x = (UI::GUI.Width - ButtonText.getLocalBounds().width) / 2;
	pos.y = position.y + (OriginalSize.y - ButtonText.getLocalBounds().height) / 3;
	ButtonText.setPosition(pos);
}

/**
* @brief Draws the Interactive object on the screen.
*/
void Button::Draw()
{
	update();
	Interactives::window->draw(ButtonShape);
	Interactives::window->draw(ButtonText);
}

/**
* @brief Checks if the cursor is on the object.
*
* @return boolean
*/
bool Button::CheckHover(const sf::Vector2i mouse) const
{
	const sf::Vector2i CurrPos = sf::Vector2i(ButtonShape.getPosition());
	const sf::Vector2i CurrSize = sf::Vector2i(ButtonShape.getSize());

	if (mouse.x < CurrPos.x || mouse.x > CurrPos.x + CurrSize.x)	return false;
	if (mouse.y < CurrPos.y || mouse.y > CurrPos.y + CurrSize.y)	return false;

	return true;
}

/**
* @brief Updates any changes to the object in the current frame.
*/
void Button::update()
{

	if (hover == true)
	{
		const  sf::Vector2f position(Position.x - 5, Position.y - 10);
		const  sf::Vector2f size(OriginalSize.x + 10, OriginalSize.y + 5);

		ButtonShape.setFillColor(UI::GUI.Primary_color);
		ButtonShape.setPosition(position);
		ButtonShape.setSize(size);

		font.loadFromFile(".\\Assets\\Fonts\\Montserrat\\static\\Montserrat-SemiBold.ttf");
		ButtonText.setFont(font);

		sf::Vector2f pos;
		pos.x = (UI::GUI.Width - ButtonText.getLocalBounds().width) / 2;
		pos.y = position.y + (OriginalSize.y - ButtonText.getLocalBounds().height) / 3;
		ButtonText.setPosition(pos);
	}
	else
	{
		ButtonShape.setFillColor(UI::GUI.Secondary_color);
		ButtonShape.setSize(OriginalSize);

		font.loadFromFile(".\\Assets\\Fonts\\Montserrat\\static\\Montserrat-Medium.ttf");
		ButtonText.setFont(font);

		SetPosition(Position);
	}
}