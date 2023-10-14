#include "Entity.h"

std::ostream& operator<< (std::ostream& os, const Entity& ent) {
	os << ent.login << ":" << ent.password;
	return os;
}

std::istream& operator>> (std::istream& os, Entity& ent) {
	string log, sep, pass;

	os >> log >> sep >> pass;

	ent.login = log;
	ent.password = pass;
	return os;
}

Records::Records() {
	
	try
	{
		deserialize();
	}
	catch (const std::exception&)
	{
		std::cout << "ERROR: Reading from Data base was failed \n";
	}
}

Records::~Records() {
	try
	{
		serialize();
	}
	catch (const std::exception&)
	{
		std::cout << "ERROR: Writing to Data base was failed \n";
	}
}

bool Records::addEntity(Entity ent) {
	
	if (entities.find(ent.login) != entities.end()) {
		return false;
	}

	entities.insert({ ent.login, ent });
	return true;
}

Entity Records::getEntity(string loginName) {

	if (entities.find(loginName) == entities.end())
		throw std::exception("No such entity");

	return entities.at(loginName);
}

void Records::serialize() {



}