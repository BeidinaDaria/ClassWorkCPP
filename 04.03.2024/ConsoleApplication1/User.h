#pragma once
#include <iostream>
class User
{
	friend class DB;
	int uniqueId;
	std::string firstName="",lastName="";
	std::string email;
	std::string password; 
	User(int id, std::string first, std::string last,
		std::string mail, std::string pass) :
		uniqueId(id), firstName(first), lastName(last), email(mail), password(pass) {}
};

