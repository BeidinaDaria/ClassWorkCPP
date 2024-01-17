#include <iostream>
#include <string>

std::string names[5]{ "Ave","Mark","Paul","Kate","John" };
int SIZE = 5;

class Car {
private:
    std::string color;
    std::string model;
    float price;
public:
    Car(){}
    Car(std::string color, std::string model) {
        this->color = color;
        this->model = model;
    }
    Car(std::string color, std::string model,float price) {
        this->color = color;
        this->model = model;
        this->price = (price < 0) ? 0 : price;
    }
    void setColor(std::string color) {
        this->color = color;
    }
    void setModel(std::string model) {
        this->model = model;
    }
    void setPrice(float price) {
        this->price = (price < 0) ? 0 : price;
    }
    std::string toString() {
        return "color:" + color + " model: " + model + " price: "+std::to_string(price) + "\n";
    }
    std::string getColor() {
        return color;
    }
    std::string getModel() {
        return model;
    }
    float getPrice() {
        return price;
    }
    Car getByMinPrice(Car c1, Car c2) {
        if (c1.getPrice() > c2.getPrice())
            return c1;
        return c2;
    }
    
};
Car getByMaxPrice(Car* arr, int n) {
    int ind = 0;
    for (int i = 1; i < n; i++)
        ind = (arr[ind].getPrice() > arr[i].getPrice()) ? i : ind;
    return arr[ind];
}

Car* getByColor(Car* arr, int& n) {
    int count = 0;
    for (int i = 0; i < n; i++)
        count = (arr[i].getColor()=="red") ? count+1 : count;
    Car* res = new Car[count];
    int ind = 0;
    for (int i = 0; i < n; i++)
        if (arr[i].getColor() == "red") {
            res[ind] = arr[i];
            ind++;
        }
    n = 2;
    return res;
}

class Student {
    std::string name;
    float avMark;
public:
    Student() {
        name = names[rand() % SIZE];
        avMark = rand() % 4 + 1 + (float)(rand() % 10) / 10;
    }
    std::string toString() {
        return "Name: " + name + " average mark: " + std::to_string(avMark)  + "\n";
    }
};
Student* generateStudents(int size) {
    srand(time(NULL));
    Student* students = new Student[size];
    for (int i = 0; i < size; i++)
        students[i] = Student();
    return students;
}

int main() {
    /*Car car1;
    car1.setColor("red");
    car1.setModel("volva");
    car1.setPrice(11000.3);
    std::cout << car1.toString() << std::endl;
    std::cout << car1.getModel() << std::endl;
    Car* arr = new Car[4]{
        Car("red","volva",10000),
        Car("black","volva",9100),
        Car("red","ferrari",11000),
        Car("blue","volva",6000),
    };
    int size = 4;
    Car* res = getByColor(arr, size);
    for (int i=0;i<size;i++)
        std::cout << res[i].toString();*/

    int size = 10;
    Student* arr = generateStudents(size);
    for (int i = 0; i < size; i++)
        std::cout << arr[i].toString();
}