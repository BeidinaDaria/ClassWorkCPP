#include "XmlManager.h"
#include <fstream>
#include <string>

std::vector<std::string> XmlManager::readFile()
{
	std::vector<std::string> vec;
	std::string buf;
	std::ifstream in(path);
	if (in.is_open()) {
		while (std::getline(in,buf)) {
			vec.push_back(buf);
		}
	}
	in.close();
    return vec;
}

void XmlManager::writeFile(std::vector<std::string> arr)
{
	std::ofstream out(path);
	if (out.is_open()) {
		for(auto str:arr) {
			out <<str<<std::endl;
		}
	}
	out.close();
}
