#include "RegistrationSystem.h"
#include "Record.h"

bool RegistrationSystem::login(std::string log, std::string pass) {
	
	return ptrDB.checkRecord({ log, pass });
}

bool RegistrationSystem::signIn(std::string log, std::string pass) {
	
	personalData pd{ "" };
	return ptrDB.addRecord({ log, pass }, pd);
}