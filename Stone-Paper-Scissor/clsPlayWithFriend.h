#pragma once

#include "clsInput.h"
#include "clsGameCore.h"
#include "GlobalPlayer.h"

class clsPlayWithFriend {

private:

	static void _GetHowManyRound() {

		Player1.GameRound = clsInput::ReadNumberFrom("How many rounds the game will be?: ", 1);

	}

	static void _Restart() {

		system("cls");

	}


	static void _GetPlayersChoise() {

		Player1.PalyerChoise = (clsGameCore::enChoise)clsInput::ReadNumber("\nPlayer 1: choise [1]Stone, [2]Paper, [3]Scissor: ",1,3);
		Player2.PalyerChoise = (clsGameCore::enChoise)clsInput::ReadNumber("\nPlayer 2: choise [1]Stone, [2]Paper, [3]Scissor: ",1,3);

	}


	static void _HeaderRoundScreen(short roundNumber) {

		cout << '\n' << clsInput::Format(7, "=") << " Round[" << roundNumber << "] " << clsInput::Format(7, "=");

	}

	static void _HeaderFinalBoard() {

		cout << '\n' << clsInput::Format(4, "\t") << clsInput::Format(5, " ") << clsInput::Format(13, "-") << "[Game Result]" << clsInput::Format(13, "-");

	}

	static void _GameOverBoard() {

		cout << '\n' << clsInput::Format(4, "\t") << clsInput::Format(50, "_") << '\n';
		cout << '\n' << clsInput::Format(5, "\t") << clsInput::Format(7, "+") << " G A M E - O V E R " << clsInput::Format(7, "+");
		cout << '\n' << clsInput::Format(4, "\t") << clsInput::Format(50, "_") << '\n';

	}


	static string _RoundWinnerText(short whoWin) {

		string arr[3] = { "Draw", "Player 1", "Player 2" };

		return arr[whoWin];

	}

	static void _ShowRoundScreen(short roundNumber) {

		_HeaderRoundScreen(roundNumber);

		cout << "\nPlayer 1 choise: " << Player1.GetPlayerChoiseText();
		cout << "\nPlayer 2 choise: " << Player2.GetPlayerChoiseText();
		cout << "\nRound Winner: " << _RoundWinnerText(Player1.WhoWinInRound(Player2));
	
		cout << '\n' << clsInput::Format(24, "=") << '\n';

	}


	static void _FinalBoard() {

		_GameOverBoard();

		_HeaderFinalBoard();

		cout << '\n' << clsInput::Format(5, "\t") << clsInput::Format(3, " ") << "Game Round         : " << Player1.GameRound << '\n';
		cout << clsInput::Format(5, "\t") << clsInput::Format(3, " ") << "Player 1 win times : " << Player1.GetPlayerWinTime() << '\n';
		cout << clsInput::Format(5, "\t") << clsInput::Format(3, " ") << "Player 2 win times : " << Player2.GetPlayerWinTime() << '\n';
		cout << clsInput::Format(5, "\t") << clsInput::Format(3, " ") << "Draw times         : " << Player1.GetDrawTime() << '\n';
		cout << clsInput::Format(5, "\t") << clsInput::Format(3, " ") << "Final Winner is    : " << _RoundWinnerText(Player1.WhoWinInGame(Player2)) << '\n';

		cout << clsInput::Format(4, "\t") << clsInput::Format(5, " ") << clsInput::Format(39, "-") << "\n\n";
		//cout << '\n' << clsInput::Format(4, "\t") << clsInput::Format(50, "_") << "\n\n";

	}


public:

	static void GameWithFriend() {
	
		_GetHowManyRound();
		_Restart();

		short roundNumber = 1;

		while (roundNumber <= Player1.GameRound) {

			_GetPlayersChoise();
			_ShowRoundScreen(roundNumber);

			roundNumber++;

		}

		_FinalBoard();

	}





};

