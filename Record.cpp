#include "Record.h"
#include <fstream>

std::ostream& operator<< (std::ostream& os, const credentials& ent) {
	os << ent.login << " : " << ent.password;
	return os;
}

std::istream& operator>> (std::istream& is, credentials& ent) {
	string log, sep, pass;

	is >> log >> sep >> pass;

	ent.login = log;
	ent.password = pass;
	return is;
}

// ====================================================================================

std::ostream& operator<<(std::ostream& os, const personalData& data) {
	os << data.phoneNumber;
	return os;
}

std::istream& operator>> (std::istream& is, personalData& data) {
	string  number;

	is >> number;
	data.phoneNumber = number;
	return is;
}

std::ostream& operator<< (std::ostream& os, const personalDataRecord& ent) {
	os << ent.hash << " : " << ent.pdata;
	return os;
}

std::istream& operator>> (std::istream& is, personalDataRecord& ent) {
	string hash, sep, number;
	is >> hash >> sep >> number;

	ent.hash = hash;
	ent.pdata.phoneNumber = number;
	return is;
}


// ====================================================================================

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

string Records::hash(credentials cred) {
	return cred.login + "::" + cred.password + "__";
}

bool Records::addRecord(credentials cred, personalData data) {
	if (userPasswords.find(cred.login) != userPasswords.end()) {
		return false;
	}
	else {

		userPasswords.insert({ cred.login, cred.password });
		string hashID = hash(cred);
		datas.insert ({ hashID , data });
	}
}

bool Records::checkRecord(credentials cred) {
	
	if (userPasswords.find(cred.login) == userPasswords.end()) {
		return false;
	}
	else {
		if (userPasswords.at(cred.login) != cred.password)
			return false;
	}
	return true;
}

personalData Records::getRecord(credentials cred) {
	if (!checkRecord(cred))
		throw std::exception("No such record with provided credentials");
	
	string hashID = hash(cred);
	return datas.at(hashID);

}

void Records::serialize() {

	std::ofstream outFile { usPassFileName };

	if (outFile.is_open()) {

		for (auto ent : userPasswords) {
			outFile << ent.first << " : " << ent.second;
			outFile << std::endl;
		}
	}
	else {
		std::cout << "Failed to open " << usPassFileName << "\n";
	}

	std::ofstream wf(dataFileName, std::ios::binary);
	if(wf.is_open()) {

		for (auto ent : datas) {
			wf << ent.first << " : " << ent.second;
			wf << std::endl;
		}
	}
	else {
		std::cout << "Failed to open " << dataFileName << "\n";
		}

}

void Records::deserialize() {
	std::ifstream inFile{ usPassFileName };
	string line;
	credentials credential;
	if (inFile.is_open()) {

		while (inFile >> credential) {
			userPasswords.insert({ credential.login, credential.password });
			std::getline(inFile, line);
		}
	}
	else {
		std::cout << "Failed to open " << usPassFileName << "\n";
	}

	std::ifstream inF{ dataFileName, std::ios::binary };
	personalDataRecord data;
	if (inF.is_open()) {
		while (inF >> data) {
			datas.insert({ data.hash,  data.pdata});
			std::getline(inF, line);
		}
	}
	else {
		std::cout << "Failed to open " << dataFileName << "\n";
	}
}