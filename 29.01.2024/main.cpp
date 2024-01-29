#include <iostream>
#include <string>

const std::string names[] = { "Grace","Max","Julie","John","Zoe","Jane","Allen","James" };
int random(int a, int b) { return a + rand() % (b - a + 1); }

class Student {
    static int id;
    int uniqueId = 0;
    std::string name = "noname";
    int* marks = nullptr;
    int countMarks = 0;
public:
    Student() :name(names[random(0, 8)]), uniqueId(id++), marks(new int[10]), countMarks(random(1,10)) {
        for (int i = 0; i < countMarks; i++)
            marks[i] = random(2, 5);
    }
    Student(std::string name) {
        this->uniqueId = this->id++;
        this->name = name;
        countMarks = rand() % 10 + 1;
        marks = new int[countMarks];
        for (int i = 0; i < countMarks; i++) {
            marks[i] = rand() % 5 + 1;
        }
    }
    Student(std::string name, int count) {
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
    Student(Student& st) {
        this->uniqueId = st.uniqueId;
        this->name = st.name;
        countMarks = (st.countMarks < 0) ? 0 : st.countMarks;
        if (countMarks >= 1) {
            marks = new int[countMarks];
            for (int i = 0; i < countMarks; i++) {
                marks[i] = st.marks[i];
            }
        }
    }
    int getUniqueId() { return uniqueId; }
    std::string toString() {
        std::string marks = "";
        for (int i = 0; i < countMarks; i++) {
            marks += std::to_string(this->marks[i]) + ", ";
        }
        return "id:" + std::to_string(uniqueId) + ", name:" + name + ", marks:" + marks + "\n";
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
        if (index<0 || index>countMarks - 1) return;
        int* buf = new int[countMarks - 1];
        for (int i = 0; i < index; i++) {
            buf[i] = marks[i];
        }
        for (int i = index + 1; i < countMarks; i++) {
            buf[i - 1] = marks[i];
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
    void changeMark(int index,int mark) {
        if (index<0 || index>countMarks)return;
        marks[index] = mark;
    }
    Student& operator=(Student& st) {
        this->uniqueId = st.uniqueId;
        this->name = st.name;
        countMarks = (st.countMarks < 0) ? 0 : st.countMarks;
        if (countMarks >= 1) {
            marks = new int[countMarks];
            for (int i = 0; i < countMarks; i++) {
                marks[i] = st.marks[i];
            }
        }
        return *this;
    }
    ~Student() {
        if (marks == nullptr) return;
        delete[] marks;
        countMarks = 0;
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

class Group {
    static int id;
    int uniqueId;
    Student* students;
    int groupCount;
public:
    Group():uniqueId(id++),students(nullptr),groupCount(0) {}
    Group(int id, int groupCount) {
        this->uniqueId = id;
        this->groupCount = groupCount;
        this->students = new Student[groupCount];
    }
    void show() {
        std::cout << "Group: "<<uniqueId << std::endl;
        for (int i = 0; i < groupCount; i++)
            std::cout << students[i].toString();
        std::cout << std::endl;
    }
    void changeMark(int ind,int index, int mark) {
        students[ind].changeMark(index, mark);
    }
    void addStudent(Student& st) {
            Student* buf = new Student[groupCount + 1];
            for (int i = 0; i < groupCount; i++) {
                buf[i] = students[i];
            }
            buf[groupCount++] = st;
            delete[] students;
            students = buf;
    }
    void removeStudentByIndex(int index) {
        if (index<0 || index>groupCount - 1) return;
        Student* buf = new Student[groupCount - 1];
        for (int i = 0; i < index; i++) {
            buf[i] = students[i];
        }
        for (int i = index + 1; i < groupCount; i++) {
            buf[i - 1] = students[i];
        }
        delete[] students;
        students = buf;
        groupCount--;
    }
    void transferStudentById(int id,Group& g){
        int i;
        for (i = 0; i < groupCount; i++) {
            if (students[i].getUniqueId()) break;
        }
    }
    ~Group() {
        if (students == nullptr) return;
        delete[] students;
        groupCount = 0;
        students = nullptr;
    }
};
int Group::id = 0;

int main()
{
    srand(time(NULL));
    Group g1(11112, 10);
    g1.show();
    g1.changeMark(9, 0, 12);
    g1.show();
    g1.removeStudentByIndex(0);
    g1.show();
}