#include "MyString.h"

MyString::MyString(const char str[]) {
	size = 0;
	for (int i = 0; str[i] != '\0'; i++)
		size++;
    this->str = new char[size + 1];
    for (int i = 0; i<size; i++)
        this->str += str[i];
    this->str += '\0';
}

MyString::MyString(const MyString& str) {
    size = str.size;
    this->str = new char[str.size];
    for (int i = 0; str.str[i] != '\0'; i++)
        this->str += str.str[i];
}

void MyString::show() {
    if (size<0)return;
    std::cout << str << std::endl;
}

bool MyString::empty() {
    if ((str == "") || (str == "\0")) return true;
    return false;
}

int MyString::compare(const MyString& str) {
    for (int i = 0; (i < size) && (i < str.size); i++)
        if (this->str[i] != str.str[i]) return (this->str[i] > str.str[i]);
    if (size==str.size) return 0;
    return (size < str.size);
}

int MyString::compare(const char* str) {
    int len = 1;
    for (int i = 0; (i < size) && ('\0' != str[i]); i++) {
        if (this->str[i] != str[i]) return (this->str[i] > str[i]);
        len++;
    }
    if (size == len) return 0;
    return (size < len);
}

void MyString::clear() {
    delete[] str;
    size = 0;
}

int MyString::stoi() {
    int n = 0;
    int ind = 0;
    if (str[ind] == '-') {
        n = (str[1] - 48)*(-1);
        ind = 2;
    }
    for (int i = ind; i < size; i++) {
        if((str[i] >= '0')&&(str[i] <= '9')){
            n = n * 10 + (str[i]-48);
        }
    }
    return n;
}