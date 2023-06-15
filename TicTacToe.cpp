#include "GameManager/GameManager.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(unsigned(UI::GUI.Width), unsigned(UI::GUI.Height)), "TicTacToe");
	GameManager game(window);
	game.Execution();
}