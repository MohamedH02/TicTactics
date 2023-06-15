#include "MainMenu.h"


MainMenu::MainMenu(sf::RenderWindow& window)
{
	this->window = &window;
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
	Button* PLAY = new Button(sf::Vector2f(680, 450), ButtonSize, "Play");
	Button* SETTINGS = new Button(sf::Vector2f(680, 530), ButtonSize, "Options");
	Button* EXIT = new Button(sf::Vector2f(680, 610), ButtonSize, "Exit");

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
* @brief Get the object which the mouse is currently above.
*
* @param position - The cursor (x, y) coordinates.
*/
void MainMenu::GetHover(sf::Vector2f position)
{
	// Check if the current selected is still selected.
	//if (selected && selected->CheckHover(position))
	//	return;

	//int i;
	//for (i = 0; i < IA.size(); i++)
	//{
	//	if (IA[i]->CheckHover(position))
	//	{
	//		IA[i]->SetHover(true);
	//		selected->SetHover(false);
	//		selected = IA[i];
	//	}
	//}

	//// If nothing is selected.
	//if (i >= IA.size())
	//{
	//	selected->SetHover(false);
	//	selected = NULL;
	//}
}

/**
* @brief Loops on the user's input to handle it.
*/
void MainMenu::GetInput()
{
	sf::Clock clock;
	while (window->isOpen() && UI::GUI.CurrPage == UI::Main)
	{
		sf::Event event;
		float deltatime = clock.restart().asSeconds();
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				UI::GUI.CurrPage = UI::Exit;
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
		UI::GUI.CurrPage = UI::Exit;
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