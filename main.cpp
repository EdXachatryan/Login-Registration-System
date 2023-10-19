#include "Record.h"
#include "RegistrationSystemUI.h"

int main() {

	RegistrationSystemUI regSystem;
	
	while (true) {
		RegistrationSystemUI::mainPage();
		int userInput;
		std::cout << "Waiting you input ..." << "\n";
		std::cin >> userInput;
		
		switch (userInput)
		{
		case 1: {
			string login, passw;
			std::cout << "Provide login and password" << "\n";
			std::cin >> login >> passw;
			regSystem.login(login, passw);
			break;
		}
		case 2: {
			std::cout << "Provide login and password" << "\n";
			string login, passw;
			std::cin >> login >> passw;
			regSystem.signIn(login, passw);
			break;
		}
		case 3: {
			regSystem.exit();
			break;
		}
		default:
			regSystem.mainPage();
			break;
		}
	}
	return 0;
}