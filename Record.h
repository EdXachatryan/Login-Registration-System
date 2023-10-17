#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <map>
#include <iostream>

using std::string;

struct credentials {
	
	string login;
	string password;
	
	friend std::ostream& operator<< (std::ostream& os, const credentials& ent);
	friend std::istream& operator>> (std::istream& is, credentials& ent);
};

struct personalData
{
	string phoneNumber;

	friend std::ostream& operator<< (std::ostream& os, const personalData& ent);
	friend std::istream& operator>> (std::istream& is, personalData& ent);

};

struct personalDataRecord
{
	string hash;
	personalData pdata;

	friend std::ostream& operator<< (std::ostream& os, const personalDataRecord& ent);
	friend std::istream& operator>> (std::istream& is, personalDataRecord& ent);

};

// user cridentials 
// username -> password => information
// map <string, string> return hashcode wich is key for Entire information

class Records {

public:
	Records();
	~Records();

	bool addRecord(credentials cred, personalData data);
	bool checkRecord(credentials cred);
	personalData getRecord(credentials cred);

private:
	string hash(credentials cred);
	void serialize();
	void deserialize();

	std::map<string, string> userPasswords;
	std::map<string, personalData> datas;

	std::string usPassFileName { "userPasswords.txt" };
	std::string dataFileName{ "data.bin" };
};

#endif // !ENTITY_H
