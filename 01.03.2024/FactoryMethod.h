#pragma once
#include <iostream>

class Cookie {
public:
	void virtual info() = 0;
};

class ChocolateCookie :public Cookie {
public:
	void info() {
		std::cout << "Chocolate cookie" << std::endl;
	}
};

class CocosCookie :public Cookie {
public:
	void info() {
		std::cout << "Cocos cookie" << std::endl;
	}
};

class Factory {
public:
	virtual Cookie* createCookies() = 0;
};

class ChocoCookiesFactory:public Factory {
	Cookie* createCookies(){
		return new ChocolateCookie;
	}
};

class CocosCookiesFactory :public Factory {
	Cookie* createCookies() {
		return new CocosCookie;
	}
};