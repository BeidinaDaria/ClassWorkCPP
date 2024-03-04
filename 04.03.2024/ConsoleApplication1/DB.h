#pragma once
#include "User.h"
#include <vector>
#include <string>
class DB
{
	std::vector<User> users;
	DB(std::vector<std::string> arr);
public:
	void addUser(User u);
	User findUserById(int id);
	int getCountUsers();
private:
	void removeUser(int id);
};

