#pragma once
#include <iostream>

class President {
private:
    std::string name;
    static President* instance;
    President(std::string name) {
        this->name = name;
    }
public:
    static President* getInstance(std::string name) {
        if (instance == nullptr) {
            instance = new President(name);
        }
        return instance;
    }
    void show() {
        std::cout << this << " : " << name;
    }
};
President* President::instance = nullptr;
