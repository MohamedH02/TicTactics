#ifndef _DEFINES_
#define _DEFINES_

#include <SFML/Graphics.hpp>
#include <vector>

namespace UI {
	enum Action
	{
		OpenSettings,
		PlayClassic,
		ReturnToPrev,
		ExitGame,

		Total_num
	};

	enum GamePhase
	{
		Main,
		Settings,
		Classic,
		Depth,


		Exit
	};

	__declspec(selectany)			// To prevent redefinition error.
		struct UI_Info {
		float Width, Height,			// Window width and height.
			Menux, Menuy;			// Menu (x, y) coordinates.
		sf::Color BG_color;
		sf::Color Primary_color;
		sf::Color Secondary_color;
		sf::Color Accent_color;
		sf::Color Text_color;

		GamePhase CurrPage, PrevPage;

		UI_Info()
		{
			Width = 1600;
			Height = 900;

			Menux = 1425;
			Menuy = 75;

			Text_color = sf::Color(2, 4, 1, 255);
			BG_color = sf::Color(28, 26, 18, 255);
			Primary_color = sf::Color(234, 179, 134, 255);
			Secondary_color = sf::Color(248, 228, 211, 255);
			Accent_color = sf::Color(234, 179, 134, 255);

			CurrPage = Main;
			PrevPage = Exit;
		}
	}GUI;
}

#endif