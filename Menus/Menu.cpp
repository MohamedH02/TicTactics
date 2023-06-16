#include "Menu.h"

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
	//Check if the current selected is still selected.
	if (selected && selected->CheckHover(position))
		return;

	int i;
	for (i = 0; i < IA.size(); i++)
	{
		if (IA[i]->CheckHover(position))
		{
			IA[i]->SetHover(true);
			if (selected)
				selected->SetHover(false);
			selected = IA[i];
			break;
		}
	}

	// If nothing is selected.
	if (i >= IA.size() && selected)
	{
		selected->SetHover(false);
		selected = NULL;
	}
}