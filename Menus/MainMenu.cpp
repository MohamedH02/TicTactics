#include "MainMenu.h"


MainMenu::MainMenu(sf::RenderWindow& window)
{
	this->window = &window;
	selected =  -1;
	Interactives::SetRenderWindow(window);

	Setup();

}

MainMenu::~MainMenu()
{
	
}

/**
* @brief Declares the IAs and inizialies the menu.
*/
void MainMenu::Setup()
{
	UI::theme theme = UI::GUI.themes[UI::GUI.index];

	// BackGround.
	BackGround.setFillColor(theme.BG_color);
	//BackGroundTexture.loadFromFile(".\\Assets\\Images\\Xbg.jpeg");
	//BackGround.setTexture(&BackGroundTexture);

	// Title
	font.loadFromFile(".\\Assets\\Fonts\\Montserrat\\static\\Montserrat-ExtraBold.ttf");
	Title.setString("TicTactics");
	Title.setFont(font);
	Title.setFillColor(theme.Primary_color);
	Title.setLetterSpacing(1);
	Title.setCharacterSize(275);
	sf::Vector2f pos;
	pos.x = (UI::GUI.Width - Title.getLocalBounds().width) / 2;
	pos.y = 70;
	Title.setPosition(pos);


	sf::Vector2f ButtonSize(240, 60);
	// Buttons. 
	Button* PLAY = new Button(ButtonSize, 10, 10, "Play");
	PLAY->SetPosition(sf::Vector2f(680, 450));
	PLAY->SetAction(UI::SelectModes);

	Button* SETTINGS = new Button(ButtonSize, 10, 10, "Options");
	SETTINGS->SetPosition(sf::Vector2f(680, 530));
	SETTINGS->SetAction(UI::OpenSettings);

	Button* EXIT = new Button(ButtonSize, 10, 10, "Exit");
	EXIT->SetPosition(sf::Vector2f(680, 610));
	EXIT->SetAction(UI::ExitGame);

	IA.push_back(PLAY);
	IA.push_back(SETTINGS);
	IA.push_back(EXIT);
	
	float radius = 20;
	CircularButton* Next_theme = new CircularButton(radius, ".\\Assets\\Icons\\right-arrow.png");
	CircularButton* Prev_theme = new CircularButton(radius, ".\\Assets\\Icons\\left-arrow.png");
	Next_theme->SetPosition(sf::Vector2f(UI::GUI.Width * 0.97 - radius * 2, UI::GUI.Height / 2 - radius));
	Prev_theme->SetPosition(sf::Vector2f(UI::GUI.Width * 0.03, UI::GUI.Height / 2 - radius));

	IA.push_back(Next_theme);
	IA.push_back(Prev_theme);

	Resize();
}

/**
* @brief Updates the position and scale of Objects on resizing.
*/
void MainMenu::Resize()
{
	const float WIDTH = UI::GUI.Width;
	const float HEIGHT = UI::GUI.Height;
	BackGround.setSize(sf::Vector2f(WIDTH, HEIGHT));
}

/**
* @brief Handles the up arrow key input.
*/
void MainMenu::MoveUp()
{
	if (selected != -1)
		IA[selected]->SetHover(false);
	if (selected <= 0)
		selected = 2;
	else
		selected--;
	IA[selected]->SetHover(true);
}

/**
* @brief Handles the down arrow key input.
*/
void MainMenu::MoveDown()
{
	if (selected != -1)
		IA[selected]->SetHover(false);
	selected++;
	if (selected > 2)
		selected = 0;
	selected %= IA.size();
	IA[selected]->SetHover(true);
}

/**
* @brief Handles the left arrow key input.
*/
void MainMenu::MoveLeft()
{
	if (selected != -1)
		IA[selected]->SetHover(false);
	if (selected != 4)
		selected = 4;
	IA[selected]->SetHover(true);
	UI::ActionType action = IA[selected]->GetAction();

}

/**
* @brief Handles the right arrow key input.
*/
void MainMenu::MoveRight()
{
	if (selected != -1)
		IA[selected]->SetHover(false);
	if (selected != 3)
		selected = 3;
	IA[selected]->SetHover(true);
	UI::ActionType action = IA[selected]->GetAction();
}

/**
* @brief Handles the user's mouse input.
*/
void MainMenu::HandleMouseInput()
{
	const sf::Vector2i mouse_position = sf::Mouse::getPosition(*window);	// Gets mouse position relative to the local given window.
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		GetHover(mouse_position);
	}
	else if (selected != -1 && IA[selected]->CheckHover(mouse_position))
	{
		CheckAction();
	}
}

/**
* @brief Handles the user's keyboard input.
*
* @param key - The pressed key.
*/
void MainMenu::HandleKeyInput(sf::Event::KeyEvent key)
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
void MainMenu::CheckAction()
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
		break;
	case UI::NextTheme:
		break;
	}
}

/**
* @brief Updates the GUI.
*
* @param deltatime - The deltaTime of each cycle.
*/
void MainMenu::UpdateInterface(float deltatime)
{
	window->clear();
	Draw();
	window->display();
}

/**
* @brief Draws the Objects and IAs on the window.
*/
void MainMenu::Draw()
{
	window->draw(BackGround);
	window->draw(Title);
	for (auto& x : IA) x->Draw();
}