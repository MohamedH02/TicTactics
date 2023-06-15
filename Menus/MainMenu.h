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
	* @brief Get the object which the mouse is currently above.
	*
	* @param position - The cursor (x, y) coordinates.
	*/
	virtual void GetHover(sf::Vector2f position);

	/**
	* @brief Loops on the user's input to handle it.
	*/
	virtual void GetInput();

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