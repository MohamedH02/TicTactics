#include "Menu.h"
#include <math.h>

Menu::~Menu()
{
	for (auto& x : IA)
		delete x;
}

/**
* @brief Get the object which the mouse is currently above.
*
* @param position - The cursor (x, y) coordinates.
*/
void Menu::GetHover(const sf::Vector2i position)
{
	const float diff = sqrt(powf(MousePos.x, 2.0) + powf(MousePos.y, 2.0)) - sqrt(powf(position.x, 2.0) + powf(position.y, 2.0));
	if (abs(diff) < 1.0) return;

	if (position == MousePos)	return;
	MousePos = position;

	//Check if the current selected is still selected.
	if (selected != -1 && IA[selected]->CheckHover(position))
		return;

	int i;
	for (i = 0; i < IA.size(); i++)
	{
		if (IA[i]->CheckHover(position))
		{
			IA[i]->SetHover(true);
			if (selected != -1)
				IA[selected]->SetHover(false);
			selected = i;
			break;
		}
	}

	// If nothing is selected.
	if (i >= IA.size() && selected != -1)
	{
		IA[selected]->SetHover(false);
		selected = -1;
	}
}

/**
* @brief Loops on the user's input to handle it.
*/
void Menu::GetInput()
{
	sf::Clock clock;
	UI::GamePhase CurrPage = UI::GUI.CurrPage;
	while (window->isOpen() && UI::GUI.CurrPage == CurrPage)
	{
		sf::Event event;
		float deltatime = clock.restart().asSeconds();
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				UI::GUI.CurrPage = UI::EXIT;
				window->close();
			}
			else if (event.type == sf::Event::Resized)
			{
				Resize();
			}
			else if (event.type == sf::Event::KeyPressed)
			{
				HandleKeyInput(event.key);
			}
			else
			{
				HandleMouseInput();
			}
		}
		UpdateInterface(deltatime);
	}
}

/**
* @brief Update the UI theme.
*/
void Menu::UpdateTheme()
{
	for (auto& x : IA)
		x->SetTheme();
}