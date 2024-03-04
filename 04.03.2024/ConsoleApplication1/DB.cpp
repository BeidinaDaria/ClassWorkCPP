#include "DB.h"

DB::DB(std::vector<std::string> arr) {
	int id;
	std::string first, last, email, pass;
	for (std::string str:arr) {
		id = stoi(str.substr(0, str.find_first_of(' ')));
		str.replace(str.begin(), str.begin() + str.find_first_of(' ')+1, "");
		first = str.substr(0, str.find_first_of(' '));
		str.replace(str.begin(), str.begin() + str.find_first_of(' ') + 1, "");
		last = str.substr(0, str.find_first_of(' '));
		str.replace(str.begin(), str.begin() + str.find_first_of(' ') + 1, "");
		email = str.substr(0, str.find_first_of(' '));
		str.replace(str.begin(), str.begin() + str.find_first_of(' ') + 1, "");
		pass = str.substr(0, str.find_first_of(' '));
		users.push_back(User(id, first, last, email, pass));
	}
}

void DB::addUser(User u)
{
	users.push_back(u);
}

User DB::findUserById(int id)
{
	for (int i = 0; i < users.size(); i++) {
		if (users[i].uniqueId == id)
			return users[i];
	}
	throw std::exception("Unvalid id!");
}

int DB::getCountUsers()
{
	return users.size();
}

void DB::removeUser(int id)
{
}
