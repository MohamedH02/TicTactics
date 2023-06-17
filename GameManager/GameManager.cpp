#include "GameManager.h"

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
		case UI::SELECTION:
			CreateSelectionMenu();
			break;
		default:
			UI::GamePhase temp = UI::GUI.PrevPage;
			UI::GUI.CurrPage = UI::GUI.CurrPage;
			UI::GUI.CurrPage = temp;

		}
	}
}

void GameManager::CreateMainMenu()
{
	CurrPage = new MainMenu(*window);
	CurrPage->GetInput();
	delete CurrPage;
}

void GameManager::CreateSelectionMenu()
{
	CurrPage = new SelectionMenu(*window);
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