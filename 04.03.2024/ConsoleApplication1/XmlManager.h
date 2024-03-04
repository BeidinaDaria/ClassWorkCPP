#pragma once
#include <iostream>
#include <vector>
class XmlManager
{
	std::string path;
public:
	XmlManager(std::string path) :path(path) {}
	std::vector<std::string> readFile();
	void writeFile(std::vector<std::string> arr);
};