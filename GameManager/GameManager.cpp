m#include "GameManager.h"

GameManager::GameManager(sf::RenderWindow& window)
{
	this->window = &window;

}

/**
* @brief Responsible for the simulation of the game and handling
* needed processes.
*/
void GameManager::Execution()
{
	while (window->isOpen())
	{
		switch (UI::GUI.CurrPage)
		{
		case UI::MAIN:
			CreateMainMenu();
			break;
		case UI::SETTINGS:
			CreateOptionsMenu();
			break;
		}
	}
}

void GameManager::CreateMainMenu()
{
	CurrPage = new MainMenu(*window);
	CurrPage->GetInput();
	delete CurrPage;
}

void GameManager::CreateOptionsMenu()
{
	Menu* PrevPage = CurrPage;
	//CurrPage = new Settings(*window);
	delete CurrPage;
	CurrPage = PrevPage;
}