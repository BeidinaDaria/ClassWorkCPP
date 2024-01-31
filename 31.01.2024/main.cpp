#include "MyString.h"

int main()
{
    MyString s1((char*)"Spanish drack");
    MyString s2 = s1;
    s2.show();
    std::cout << s2.empty() << std::endl;
    MyString s3 = MyString("123");
    MyString s4 = MyString("-123");
    std::cout << s3.stoi() << std::endl;
    std::cout << s4.stoi() << std::endl;
}
