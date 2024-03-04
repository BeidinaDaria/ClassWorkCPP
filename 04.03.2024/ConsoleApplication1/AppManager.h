#pragma once
#include "XmlManager.h"
#include "DB.h"
class AppManager
{
	DB memory;
	XmlManager xmlMan;

	void updateInDB();
	void updateXmlManager();
public:
	void addUser(User u);
	void removeUserById(int id);
	void showAll();
};

