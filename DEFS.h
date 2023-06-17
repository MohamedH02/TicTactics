#ifndef _DEFINES_
#define _DEFINES_

#include <SFML/Graphics.hpp>
#include <vector>

namespace UI {
	const unsigned char NUMBER_OF_MODES = 6;

	enum ActionType
	{
		OpenSettings,
		SelectModes,
		NextTheme,
		PreviousTheme,
		PlayClassic,
		ReturnToPrev,
		ExitGame,

		Total_num
	};

	enum GamePhase
	{
		MAIN,
		SELECTION,
		SETTINGS,
		CLASSIC,
		DEPTH,


		EXIT
	};

	struct theme
	{
		sf::Color BG_color;
		sf::Color Primary_color;
		sf::Color Secondary_color;
		sf::Color Accent_color;
		sf::Color Text_color;
	};

	__declspec(selectany)			// To prevent redefinition error.
		struct UI_Info {
		float Width, Height,			// Window width and height.
			Menux, Menuy;			// Menu (x, y) coordinates.
		std::vector<UI::theme> themes;
		unsigned index;

		GamePhase CurrPage, PrevPage;

		UI_Info()
		{
			Width = 1600;
			Height = 900;

			Menux = 1425;
			Menuy = 75;

			index = 0;

			UI::theme main_theme;
			main_theme.Text_color = sf::Color(2, 4, 1, 255);
			main_theme.BG_color = sf::Color(28, 26, 18, 255);
			main_theme.Primary_color = sf::Color(234, 179, 134, 255);
			main_theme.Secondary_color = sf::Color(248, 228, 211, 255);
			main_theme.Accent_color = sf::Color(234, 179, 134, 255);
			themes.push_back(main_theme);

			CurrPage = MAIN;
			PrevPage = EXIT;
		}
	}GUI;
}

#endif