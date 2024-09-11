#pragma once

#include <iostream>
#include <string>
#include "clsInput.h"
#include "clsChoisePlayWithWho.h"
#include "GlobalPlayer.h"

using std::string;

class clsGameMenueScreen {

private:

	enum _enMenueOption { Exit = 0, Start = 1 };

	static void _Header() {

		cout << clsInput::Format(5, "\t") << clsInput::Format(26, "=") << '\n';

		cout << clsInput::Format(5, "\t") << clsInput::Format(8, " ") << "Game menue\n";

		cout << clsInput::Format(5, "\t") << clsInput::Format(26, "=") << '\n';


	}

	static void _Restart() {

		system("cls");

	}

	static void _GoBack(string message) {

		cout << message;
		system("pause>0");
		ShowGameMenueScreen();

	}

	static short _ReadOptional() {

		cout << clsInput::Format(4, "\t") << clsInput::Format(8, " ");
		short choise = clsInput::ReadNumber("Choise what do you want [1 or 2]: ", 1, 2);
		return choise;

	}


	static void _GoToGame() {

		clsChoisePlayWithWho::ChoisePlayWithWho();

	}
	

	static void _PerformOptinal(_enMenueOption optional) {

		switch (optional)
		{

		case clsGameMenueScreen::Start:
			_Restart();
			_GoToGame();
			_GoBack("Press any key to go back to game menue...");

			break;

		case clsGameMenueScreen::Exit:

			break;

		}


	}

	static void _RestertGlobalVariable() {

		Player1.DrawTimes = 0;
		Player1.PlayerWinTimes = 0;
		Player2.DrawTimes = 0;
		Player2.PlayerWinTimes = 0;

	}

public:


	static void ShowGameMenueScreen() {

		
		_RestertGlobalVariable();

		_Restart();

		_Header();

		cout << clsInput::Format(5, "\t") << clsInput::Format(3, " ") << "[1] Start.\n";
		cout << clsInput::Format(5, "\t") << clsInput::Format(3, " ") << "[2] Exit.\n";

		cout << clsInput::Format(5, "\t") << clsInput::Format(26, "=") << '\n';

		_PerformOptinal((_enMenueOption)_ReadOptional());

	}



};

