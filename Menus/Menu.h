#ifndef _MENU_
#define _MENU_

#include "../DEFS.h"
#include "../GUI/IA.h"
#include "../GUI/Button.h"

class Menu
{
protected:
	sf::RectangleShape BackGround;
	sf::Vector2i MousePos;
	std::vector<Interactives*> IA;
	int selected;			// The current IA object's index which the cursor is above.
	sf::RenderWindow* window;

public:
	virtual ~Menu();

	/**
	* @brief Declares the IAs and inizialies the menu.
	*/
	virtual void Setup() = 0;

	/**
	* @brief Updates the position and scale of Objects on resizing.
	*/
	virtual void Resize() = 0;

	/**
	* @brief Get the object which the mouse is currently above.
	*
	* @param position - The cursor (x, y) coordinates.
	*/
	virtual void GetHover(const sf::Vector2i position);

	/**
	* @brief Executes the desired action chosen by the user.
	*/
	virtual void CheckAction() = 0;

	/**
	* @brief Loops on the user's input to handle it.
	*/
	void GetInput();
	
	/**
	* @brief Handles the user's mouse input.
	*/
	virtual void HandleMouseInput() = 0;

	/**
	* @brief Handles the user's keyboard input.
	*
	* @param key - The pressed key.
	*/
	virtual void HandleKeyInput(sf::Event::KeyEvent key) = 0;

	/**
	* @brief Handles the up arrow key input.
	*/
	virtual void MoveUp() = 0;

	/**
	* @brief Handles the down arrow key input.
	*/
	virtual void MoveDown() = 0;

	/**
	* @brief Handles the up arrow key input.
	*/
	virtual void MoveLeft() = 0;

	/**
	* @brief Handles the down arrow key input.
	*/
	virtual void MoveRight() = 0;

	/**
	* @brief Updates the GUI.
	* 
	* @param deltatime - The deltaTime of each cycle.
	*/
	virtual void UpdateInterface(float deltatime) = 0;

	/**
	* @brief Draws the Objects and IAs on the window.
	*/
	virtual void Draw() = 0;
};

#endif