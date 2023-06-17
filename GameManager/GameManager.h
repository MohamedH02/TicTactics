#ifndef _GAME_MANAGER_
#define _GAME_MANAGER_

#include "../Menus/Menu.h"
#include "../Menus/MainMenu.h"
#include "../Menus/SelectionMenu.h"
#include "../Menus/Settings.h"

/**
* @brief The main system for the game operations and switching pages.
*/
class GameManager {
	sf::RenderWindow* window;

	Menu* CurrPage;

public:
	GameManager(sf::RenderWindow& window);


	/**
	* @brief Responsible for the simulation of the game and handling
	* needed processes.
	*/
	void Execution();

	void CreateMainMenu();

	void CreateSelectionMenu();
	
	void CreateOptionsMenu();

	void CreatePlayMenu();

};

#endif