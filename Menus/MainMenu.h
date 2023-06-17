#ifndef _MAIN_MENU_
#define _MAIN_MENU_

#include "Menu.h"

class MainMenu : public Menu
{
	sf::Texture BackGroundTexture;
	sf::Text Title;
	sf::Font font;
	
public:
	MainMenu(sf::RenderWindow&);
	~MainMenu();

	/**
	* @brief Declares the IAs and inizialies the menu.
	*/
	virtual void Setup();

	/**
	* @brief Updates the position and scale of Objects on resizing.
	*/
	virtual void Resize();

	/**
	* @brief Handles the user's mouse input.
	*/
	virtual void HandleMouseInput();

	/**
	* @brief Handles the user's keyboard input.
	*
	* @param key - The pressed key.
	*/
	virtual void HandleKeyInput(sf::Event::KeyEvent key);

	/**
	* @brief Handles the up arrow key input.
	*/
	virtual void MoveUp();

	/**
	* @brief Handles the down arrow key input.
	*/
	virtual void MoveDown();

	/**
	* @brief Handles the left arrow key input.
	*/
	virtual void MoveLeft();

	/**
	* @brief Handles the right arrow key input.
	*/
	virtual void MoveRight();

	/**
	* @brief Executes the desired action chosen by the user.
	*/
	virtual void CheckAction();

	/**
	* @brief Updates the GUI.
	*
	* @param deltatime - The deltaTime of each cycle.
	*/
	virtual void UpdateInterface(float deltatime);

	/**
	* @brief Draws the Objects and IAs on the window.
	*/
	virtual void Draw();

};

#endif