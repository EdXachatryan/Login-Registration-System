#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <map>
#include <iostream>

using std::string;

struct Entity {
	
	string login;
	string password;
	
	friend std::ostream& operator<< (std::ostream& os, const Entity& ent);
	friend std::istream& operator>> (std::istream& os, Entity& ent);

//private:
//	string secodnaryQuestion;
};

class Records {

	Records();
	~Records();

	bool addEntity(Entity ent);
	Entity getEntity(string loginName);

private:
	void serialize();
	void deserialize();

	std::map<string, Entity> entities;
};

#endif // !ENTITY_H
