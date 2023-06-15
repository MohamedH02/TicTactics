#include "Menu.h"

Menu::~Menu()
{
	for (auto& x : IA)
		delete x;
}