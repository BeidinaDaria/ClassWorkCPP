#include <iostream>

class Student {
private:
    std::string name;
    int age;
public:
    Student(std::string name, int age) {
        this->age = age;
        this->name = name;
    }
    void show() {
        std::cout << "Name: " << name << " age: " << age << std::endl;
    }
};

int main(){
    Student st1("Paul",22);
    st1.show();
}