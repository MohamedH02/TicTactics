#include "IA.h"

sf::RenderWindow * Interactives::window;

void Interactives::SetHover(bool hover)
{
	this->hover = hover;
}

void Interactives::SetAction(UI::ActionType action)
{
	this->action = action;
}