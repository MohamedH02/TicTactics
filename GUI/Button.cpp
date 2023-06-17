#include "Button.h"

Button::Button(sf::Vector2f size, float radius, unsigned int cornerPointCount, std::string text): ButtonShape(size, radius, cornerPointCount)
{
	OriginalSize = size;
	Position = sf::Vector2f(0, 0);


	ButtonShape.setSize(OriginalSize);

	if (!font.loadFromFile(".\\Assets\\Fonts\\Montserrat\\static\\Montserrat-Medium.ttf"))
	{
		std::printf("Failed to load font.\n");
		exit(1);
	}
	ButtonText.setFont(font);
	
	ButtonText.setCharacterSize(unsigned int(40));
	ButtonText.setString(text);
	SetTheme();

	hover = false;
}

void Button::SetPosition(sf::Vector2f position)
{
	Position = position;
	ButtonShape.setPosition(Position);
	sf::Vector2f pos;
	pos.x = position.x + (OriginalSize.x - ButtonText.getLocalBounds().width) / 2;
	pos.y = position.y + (OriginalSize.y - ButtonText.getLocalBounds().height) / 3;
	ButtonText.setPosition(pos);
}

void Button::SetSize(sf::Vector2f size)
{
	const unsigned charsize = ButtonText.getCharacterSize();
	const unsigned Xchange = charsize * ((size.x - OriginalSize.x) / OriginalSize.x) + charsize;
	const unsigned Ychange = charsize * ((size.y - OriginalSize.y) / OriginalSize.y) + charsize;
	OriginalSize = size;
	ButtonShape.setSize(size);

	ButtonText.setCharacterSize((Xchange > Ychange) ? Ychange : Xchange);
}

/**
* @brief Changes the object's theme to be equivalent to the selected theme.
*/
void Button::SetTheme()
{
	const UI::theme& theme = UI::GUI.themes[UI::GUI.index];
	PrimaryColor = theme.Secondary_color;
	ButtonShape.setFillColor(PrimaryColor);
	ButtonText.setFillColor(theme.Text_color);
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
	const UI::theme theme = UI::GUI.themes[UI::GUI.index];
	if (hover == true)
	{
		const sf::Vector2f position(Position.x - 5, Position.y - 10);
		const sf::Vector2f size(OriginalSize.x + 10, OriginalSize.y + 5);

		ButtonShape.setFillColor(theme.Primary_color);
		ButtonShape.setPosition(position);
		ButtonShape.setSize(size);

		font.loadFromFile(".\\Assets\\Fonts\\Montserrat\\static\\Montserrat-SemiBold.ttf");
		ButtonText.setFont(font);

		sf::Vector2f pos;
		pos.x = position.x + (OriginalSize.x - ButtonText.getLocalBounds().width) / 2;
		pos.y = position.y + (OriginalSize.y - ButtonText.getLocalBounds().height) / 3;
		ButtonText.setPosition(pos);
	}
	else
	{
		ButtonShape.setFillColor(theme.Secondary_color);
		ButtonShape.setSize(OriginalSize);

		font.loadFromFile(".\\Assets\\Fonts\\Montserrat\\static\\Montserrat-Medium.ttf");
		ButtonText.setFont(font);

		SetPosition(Position);
	}
}