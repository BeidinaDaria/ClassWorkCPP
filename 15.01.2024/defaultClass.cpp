#include <iostream>

class Student {
private:
    std::string name;
    int group;
    float avMark;
public:
    Student(std::string name, int group,float avMark) {
        if (group <= 0) group = 1;
        this->group = group;
        this->name = name;
        this->avMark = avMark;
    }
    void show() {
        std::cout << "Name: " << name << " group: " << group<<
            " average mark: " << avMark<< std::endl;
    }
    std::string level() {
        if (avMark < 2.6) return "Двоечник";
        if (avMark < 3.6) return "Троечник";
        if (avMark < 4.6) return "Хорошист";
        return "Отличник";
    }
};

class Fraction {
    int total;
    int numerator;
    int denominator;
public:
    Fraction(int num, int denom){
        this->total = num/denom;
        this->numerator = num % denom;
        this->denominator = denom;
    }
    void show() {
        std::cout <<total<<" "<< numerator << "/" << denominator << std::endl;
    }
    Fraction sum(Fraction f2) {
        int num;
        num = this->numerator*f2.denominator + f2.numerator*this->denominator
            + this->total * this->denominator * f2.denominator + f2.total * this->denominator * f2.denominator;
        int denum = this->denominator*f2.denominator;
        return Fraction(num,denum);
    }
    Fraction operator+(Fraction f2) {
        int num = this->numerator * f2.denominator + f2.numerator * this->denominator
            +this->total*this->denominator*f2.denominator+ f2.total * this->denominator * f2.denominator;
        int denum = this->denominator * f2.denominator;
        return Fraction(num, denum);
    }
};

int main(){
    /*Student st1("Paul", 22);
    st1.show();*/

    setlocale(LC_ALL, "ru");
    Student st1("Paul", 3, 3.7);
    st1.show();
    std::cout << st1.level() << std::endl;

    Fraction f(6, 3);
    f.show();
    Fraction result = f.sum(Fraction(2, 5));
    result.show();
    result = result + f;
    result.show();
}