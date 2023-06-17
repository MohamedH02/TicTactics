#include "SelectionMenu.h"


SelectionMenu::SelectionMenu(sf::RenderWindow& window)
{
	this->window = &window;
	selected = NULL;
	Interactives::SetRenderWindow(window);

	Setup();

}

SelectionMenu::~SelectionMenu()
{

}

/**
* @brief Declares the IAs and inizialies the menu.
*/
void SelectionMenu::Setup()
{
	UI::theme theme = UI::GUI.themes[UI::GUI.index];
	// BackGround.
	BackGround.setFillColor(theme.BG_color);


	// Buttons.
	const float ButtonWidth = UI::GUI.Width * 0.7 / 3;
	const float ButtonHeight = UI::GUI.Height * 0.7 / 3;
	sf::Vector2f ButtonSize(ButtonWidth, ButtonHeight);
	for (int i = 0; i < int(UI::NUMBER_OF_MODES); i++)
	{
		Button* mode = new Button(ButtonSize, 10, 10, "Place Holder");
		IA.push_back(mode);
	}

	Resize();
}

/**
* @brief Updates the position and scale of Objects on resizing.
*/
void SelectionMenu::Resize()
{
	const float WIDTH = UI::GUI.Width;
	const float HEIGHT = UI::GUI.Height;
	BackGround.setSize(sf::Vector2f(WIDTH, HEIGHT));

	const float ButtonWidth = WIDTH * 0.7 / 3;
	const float ButtonHeight = HEIGHT * 0.8 / 2;
	const sf::Vector2f Start(WIDTH * 0.1, HEIGHT * 0.1);
	sf::Vector2f ButtonSize(ButtonWidth, ButtonHeight);
	for(size_t i = 0; i < IA.size(); i++)
	{
		IA[i]->SetSize(ButtonSize);
		IA[i]->SetPosition(sf::Vector2f(Start.x + (ButtonWidth + WIDTH * 0.05) * (i % 3), Start.y + (ButtonHeight + HEIGHT * 0.05) * (i >= 3)));
	}
}

/**
* @brief Handles the up arrow key input.
*/
void SelectionMenu::MoveUp()
{
	if (selected != -1)
		IA[selected]->SetHover(false);
	if (selected <= -1)
		selected = 0;
	else
		selected = (int(IA.size()) + selected - 3) % int(IA.size());
	IA[selected]->SetHover(true);
}

/**
* @brief Handles the down arrow key input.
*/
void SelectionMenu::MoveDown()
{
	if (selected != -1)
		IA[selected]->SetHover(false);
	if (selected == -1)
		selected = 0;
	else
	{
		selected+= 3;
		selected %= IA.size();
	}
	IA[selected]->SetHover(true);
}

/**
* @brief Handles the left arrow key input.
*/
void SelectionMenu::MoveLeft()
{
	if (selected != -1)
		IA[selected]->SetHover(false);
	if (selected <= 0)
		selected = int(IA.size()) - 1;
	else
		selected--;
	IA[selected]->SetHover(true);
}

/**
* @brief Handles the right arrow key input.
*/
void SelectionMenu::MoveRight()
{
	if (selected != -1)
		IA[selected]->SetHover(false);
	selected++;
	selected %= IA.size();
	IA[selected]->SetHover(true);
}

/**
* @brief Handles the user's mouse input.
*/
void SelectionMenu::HandleMouseInput()
{
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		const sf::Vector2i mouse_position = sf::Mouse::getPosition(*window);	// Gets mouse position relative to the local given window.
		
		GetHover(mouse_position);
	}
	else if (selected)
	{
		CheckAction();
	}
}

/**
* @brief Handles the user's keyboard input.
*
* @param key - The pressed key.
*/
void SelectionMenu::HandleKeyInput(sf::Event::KeyEvent key)
{
	switch (key.code)
	{
	case sf::Keyboard::Escape:
		UI::GUI.CurrPage = UI::EXIT;
		window->close();
		break;
	case sf::Keyboard::Tab:
		if (selected != -1)
			IA[selected]->SetHover(false);
		selected++;
		selected %= IA.size();
		IA[selected]->SetHover(true);
		break;
	case sf::Keyboard::Up:
		MoveUp();
		break;
	case sf::Keyboard::Down:
		MoveDown();
		break;
	case sf::Keyboard::Left:
		MoveLeft();
		break;
	case sf::Keyboard::Right:
		MoveRight();
		break;
	case sf::Keyboard::Enter:
		CheckAction();
		break;
	default:
		break;
	}
}


/**
* @brief Executes the desired action chosen by the user.
*/
void SelectionMenu::CheckAction()
{
	if (selected <= -1) return;

	UI::ActionType action = IA[selected]->GetAction();
	switch (action)
	{
	case UI::SelectModes:
		UI::GUI.CurrPage = UI::SELECTION;
		UI::GUI.PrevPage = UI::MAIN;
		break;
	case UI::OpenSettings:
		UI::GUI.CurrPage = UI::SETTINGS;
		UI::GUI.PrevPage = UI::MAIN;
		break;
	case UI::ExitGame:
		UI::GUI.CurrPage = UI::EXIT;
		window->close();
	}
}

/**
* @brief Updates the GUI.
*
* @param deltatime - The deltaTime of each cycle.
*/
void SelectionMenu::UpdateInterface(float deltatime)
{
	window->clear();
	Draw();
	window->display();
}

/**
* @brief Draws the Objects and IAs on the window.
*/
void SelectionMenu::Draw()
{
	window->draw(BackGround);
	window->draw(Title);
	for (auto& x : IA) x->Draw();
}