#include <iostream>
#include <string>

class Student {
    static int id;
    int uniqueId = 0;
    std::string name = "noname";
    int* marks = nullptr;
    int countMarks = 0;
public:
    Student() {}
    Student(std::string name) {
        this->uniqueId = this->id++;
        this->name = name; 
        countMarks = rand() % 10 + 1;
            marks = new int[countMarks];
            for (int i = 0; i < countMarks; i++) {
                marks[i] = rand() % 5 + 1;
            }
    }
    Student(std::string name,int count) {
        this->uniqueId = this->id++;
        this->name = name;
        countMarks = (count < 0) ? 0 : count;
        if (count > 1) {
            marks = new int[count];
            srand(time(NULL));
            for (int i = 0; i < countMarks; i++) {
                marks[i] = rand() % 5 + 1;
            }
        }
    }
    std::string toString() {
        std::string marks = "";
        for (int i = 0; i < countMarks; i++) {
            marks += std::to_string(this->marks[i]) + ", ";
        }
        return "id:" + std::to_string(uniqueId) + ", name:" + name + ", marks:" + marks+"\n";
    }
    void addMark(int mark) {
        if (mark > 1 && mark < 6) {
            int* buf = new int[countMarks + 1];
            for (int i = 0; i < countMarks; i++) {
                buf[i] = marks[i];
            }
            buf[countMarks++] = mark;
            delete[] marks;
            marks = buf;
        }
    }
    void removeMarkByIndex(int index) {
        if (index<0 || index>countMarks-1) return;
        int* buf = new int[countMarks -1];
        for (int i = 0; i < index; i++) {
           buf[i] = marks[i];
        }
        for (int i = index+1; i < countMarks; i++) {
           buf[i-1] = marks[i];
        }
        delete[] marks;
        marks = buf;
        countMarks--;
    }
    double avMark() {
        int sum = 0;
        for (int i = 0; i < countMarks; i++) {
            sum += marks[i];
        }
        return (double)sum / countMarks;
    }
    
    
};
int idByMarks(Student* arr, int size = 0) {
    int ind = -1;
    int mark = 0;
    int m = 0;
    for (int i = 0; i < size; i++) {
        m = arr[i].avMark();
        if (m > mark) {
            mark = arr[i].avMark();
            ind = i;
        }
    }
    return ind;
}

int Student::id = 0;

int main()
{
    /*Student st1("Paul", 10);
    std::cout << st1.toString();
    std::cout << st1.avMark() << std::endl;;
    st1.removeMarkByIndex(5);
    std::cout << st1.toString();
    std::cout << st1.avMark()<<std::endl;*/

    srand(time(NULL));
    int size = 5;
    Student* arr = new Student[size]{ Student("Paul"),Student("John"),Student("Sara"),Student("Rick"),Student("Arunas") };
    for (int i = 0; i < size; i++) {
        std::cout << arr[i].toString();
    }
    //std::cout << idByMarks(arr, size) << std::endl;
    Student st = Student(arr[0]);
    std::cout << arr[0].toString();
    std::cout << st.toString();
    arr[0].addMark(3);
    std::cout << arr[0].toString();
    std::cout << st.toString();
}