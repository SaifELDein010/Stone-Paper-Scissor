#pragma once

#include <iostream>

class clsGameCore {


private:

	
	short _GameRound = 0;

	short _PlayerWinTimes = 0;
	short _DrawTimes = 0;

	static short  _RandomNumbers(int from, int to) {

		short number = rand() % (to - from + 1) + from;

		return number;

	}


public:

	enum enChoise {

		enStone = 1, enPaper = 2, enScissor = 3

	};

	enChoise PlayerChoise;

	

	void SetGameRound(short gameRound) {

		_GameRound = gameRound;

	}

	short GetGameRound() {

		return _GameRound;

	}

	__declspec(property(get = GetGameRound, put = SetGameRound)) short GameRound;


	void SetPalyerChoise(enChoise playerChoise) {

		PlayerChoise = playerChoise;

	}


	enChoise GetPlayerChoise() {

		return PlayerChoise;

	}

	string GetPlayerChoiseText() {

		string arr[4] = { "", "Stone", "Paper", "scissor" };

		return arr[PlayerChoise];

	}

	__declspec(property(get = GetPlayerChoise, put = SetPalyerChoise)) enChoise PalyerChoise;


	void SetPlayerWinTime(short times) {

		_PlayerWinTimes = times;

	}

	short GetPlayerWinTime() {

		return _PlayerWinTimes;

	}

	__declspec(property(get = GetPlayerWinTime, put = SetPlayerWinTime)) short PlayerWinTimes;


	void SetDrawTimes(short times) {

		_DrawTimes = times;

	}

	short GetDrawTime() {

		return _DrawTimes;

	}

	__declspec(property(get = GetDrawTime, put = SetDrawTimes)) short DrawTimes;


	short WhoWinInRound(clsGameCore& player2choise) {

		if (PlayerChoise == player2choise.PlayerChoise) {

			_DrawTimes++;
			return 0;

		}

		switch (PlayerChoise) {

		case enStone:
			if (player2choise.PlayerChoise == enScissor) {

				_PlayerWinTimes++;
				return 1;

			}
			break;

		case enPaper:
			if (player2choise.PlayerChoise == enStone) {

				_PlayerWinTimes++;
				return 1;

			}
			break;

		case enScissor:
			if (player2choise.PlayerChoise == enPaper) {

				_PlayerWinTimes++;
				return 1;

			}
			break;

		}


		player2choise._PlayerWinTimes++;
		return 2;

	}

	short WhoWinInGame(clsGameCore player2choise) {

		if (_PlayerWinTimes == player2choise._PlayerWinTimes)
			return 0;
		else if (_PlayerWinTimes > player2choise._PlayerWinTimes)
			return 1;
		else
			return 2;

	}


	static enChoise ComputerChoise() {

		return (enChoise)_RandomNumbers(1, 3);

	}

};

