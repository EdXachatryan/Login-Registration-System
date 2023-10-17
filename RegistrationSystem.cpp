#include "RegistrationSystem.h"
#include "Record.h"

void RegistrationSystem::login(std::string log, std::string pass) {

	try
	{
		if (!ptrDB.checkRecord({ log, pass })) {
			std::cout << "Wrong credentials \n";
		}
		else {
			std::cout << "You are logged in\n";
			personalData pd = ptrDB.getRecord({ log, pass });
			std::cout << "Your number is: " << pd.phoneNumber << "\n";
		}

	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << "\n";
	}

}

void RegistrationSystem::signIn(std::string log, std::string pass) {

	personalData pd{ "25623145" };
	if (ptrDB.addRecord({ log, pass }, pd)) {
		std::cout << "You are signed in successfully " << "\n";
	}
	else {
		std::cout << "Your sign in was unsuccessful " << "\n";
	}
}