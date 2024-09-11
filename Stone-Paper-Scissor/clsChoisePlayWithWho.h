#pragma once

#include "clsInput.h"
#include "clsPlayWithFriend.h"
#include "clsPlayWithComputer.h"


class clsChoisePlayWithWho {

private:

	enum _enPlayWithWho {

		enFriend = 1, enComputer = 2

	};

	static void Restert() {

		system("cls");

	}



	static void _PlayWithFriend() {

		//cout << "\nGame with friend will be here soon...\n";
		clsPlayWithFriend::GameWithFriend();

	}

	static void _PlayWithComputer() {

		//cout << "\nGame with Computer will be here soon...\n";
		clsPlayWithComputer::GameWithComputer();

	}


	static void _performOption(_enPlayWithWho who) {

		switch (who)
		{

		case clsChoisePlayWithWho::enFriend:
			Restert();
			_PlayWithFriend();
			break;
		
		case clsChoisePlayWithWho::enComputer:
			Restert();
			_PlayWithComputer();
			break;
		
		}


	}

public:

	static void ChoisePlayWithWho() {

		_enPlayWithWho who = (_enPlayWithWho)clsInput::ReadNumber("Please, Enter who play with it [1]Friend, [2]Computer: ", 1, 2);

		_performOption((_enPlayWithWho)who);

	}



};

