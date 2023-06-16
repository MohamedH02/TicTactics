#include "MainMenu.h"


MainMenu::MainMenu(sf::RenderWindow& window)
{
	this->window = &window;
	selected = NULL;
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
	// BackGround.
	BackGround.setFillColor(UI::GUI.BG_color);
	//BackGroundTexture.loadFromFile(".\\Assets\\Images\\Xbg.jpeg");
	//BackGround.setTexture(&BackGroundTexture);

	// Title
	font.loadFromFile(".\\Assets\\Fonts\\Montserrat\\static\\Montserrat-ExtraBold.ttf");
	Title.setString("TicTactics");
	Title.setFont(font);
	Title.setFillColor(UI::GUI.Primary_color);
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
* @brief Loops on the user's input to handle it.
*/
void MainMenu::GetInput()
{
	sf::Clock clock;
	while (window->isOpen() && UI::GUI.CurrPage == UI::MAIN)
	{
		sf::Event event;
		float deltatime = clock.restart().asSeconds();
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				UI::GUI.CurrPage = UI::EXIT;
				window->close();
			}
			else if (event.type == sf::Event::KeyPressed)
			{
				HandleKeyInput(event.key);
			}
			else
			{
				HandleMouseInput();
			}
		}
		UpdateInterface(deltatime);
	}
}

/**
* @brief Handles the user's mouse input.
*/
void MainMenu::HandleMouseInput()
{
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		const sf::Vector2i mouse_position = sf::Mouse::getPosition(*window);	// Gets mouse position relative to the local given window.
		GetHover(mouse_position);
	}
	else if (selected)
	{
		UI::ActionType action = selected->GetAction();
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
	default:
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