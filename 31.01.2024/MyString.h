#pragma once
#include <iostream>
class MyString{
    char* str;
    int size;
public:
    MyString() :str((char*)""), size(0) {}
    MyString(const char str[]);
    MyString(const MyString& str);
    void show();
    bool empty();
    int compare(const MyString& str);
    int compare(const char* str);
    MyString& operator=(MyString& str) {
        this->size = str.size;
        if (this->size >= 1) {
            this->str = new char[size];
            for (int i = 0; str.str[i] != '\0'; i++)
                this->str += str.str[i];
        }
        return *this;
    }
    void clear();
    int stoi();
};

