#include "RegistrationSystemUI.h"

void RegistrationSystemUI::mainPage() {
	UI ui;
	system("CLS");
	std::cout << ui.welcome << ui.new3Line;
	std::cout << ui.line << ui.newLine;
	std::cout << ui.login << ui.newLine
			<< ui.signIn << ui.newLine
			<< ui.exit << ui.newLine;
	std::cout << ui.line << ui.newLine;
}

void RegistrationSystemUI::login(std::string log, std::string pass) { 
	
	try
	{
		if (!regSystem->login(log, pass)) {
			std::cout << "Wrong credentials \n";
		}
		else {
			std::cout << "You are logged in\n";
		}
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << "\n";
	}
}

void RegistrationSystemUI::signIn(std::string log, std::string pass) {

	if (regSystem->signIn(log, pass))
		std::cout << "You are signed in successfully " << "\n";
	else 
		std::cout << "Your sign in was unsuccessful " << "\n";
}

void RegistrationSystemUI::exit() {
	std::cout << "Exit ...";
	std::exit(0);
}
