#ifndef REG_SYSTEM_H
#define REG_SYSTEM_H

#include <map>
#include <string>
#include "Record.h"

class RegistrationSystem
{
public:

	bool login(std::string log, std::string pass);
	//void login(credentials cred); // TODO
	bool signIn(std::string log, std::string pass);

private:
	Records ptrDB;
};

#endif // !REG_SYSTEM_H
