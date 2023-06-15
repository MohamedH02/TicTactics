#include "Button.h"

Button::Button(sf::Vector2f position, sf::Vector2f size, std::string text)
{
	OriginalSize = size;
	Position = position;
	PrimaryColor = UI::GUI.Secondary_color;


	ButtonShape.setFillColor(PrimaryColor);
	ButtonShape.setSize(OriginalSize);
	ButtonShape.setPosition(Position);

	if (!font.loadFromFile(".\\Assets\\Fonts\\Montserrat\\static\\Montserrat-Medium.ttf"))
	{
		std::printf("Failed to load font.\n");
		exit(1);
	}
	ButtonText.setFont(font);
	ButtonText.setFillColor(UI::GUI.Text_color);
	ButtonText.setCharacterSize(unsigned int(40));
	ButtonText.setString(text);
	sf::Vector2f pos;
	pos.x = (UI::GUI.Width - ButtonText.getLocalBounds().width) / 2;
	pos.y = position.y + (size.y - ButtonText.getLocalBounds().height) / 2;
	ButtonText.setPosition(pos);

	hover = false;
}

void Button::Draw()
{
	Interactives::window->draw(ButtonShape);
	Interactives::window->draw(ButtonText);
}