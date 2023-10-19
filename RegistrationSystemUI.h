#pragma once

#include <string>
#include "RegistrationSystem.h"
#include <memory>

class RegistrationSystemUI
{
public:
	RegistrationSystemUI() {
		mainPage();
		regSystem = std::make_unique<RegistrationSystem>();
	}
	static void mainPage();

	void login(std::string log, std::string pass);
	void signIn(std::string log, std::string pass);
	void exit();

private:
	std::unique_ptr<RegistrationSystem> regSystem = nullptr;

};

struct UI
{
	const string welcome = "\t\t\t\t Welcome to Registration System";
	const string line = "=======================================================";
	const string login = "\t\t\t\t 1. Login";
	const string signIn = "\t\t\t\t 2. Sign in";
	const string exit= "\t\t\t\t 3. Exit";
	const string newLine = "\n";
	const string new3Line = "\n\n\n";

};