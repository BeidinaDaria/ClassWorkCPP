#include <iostream>

template <typename T>
struct node{
    T data;
    node<T>* next;
    node(T data, node<T>* next){
        this->data = data;
        this->next = next;
    }
};

template <typename T>
class mylist{
    node<T>* p;
public:
    mylist(){
        p = nullptr;
    }
    void add_first(T data){
        p = new node<T>(data, p);
    }
    void add(int ind, T data) {
        if (ind == 0) {
            add_first(data);
            return;
        }
        auto p1 = p;
        for (int i = 0; (i < ind-1)&&(p1!=nullptr); i++)
            p1 = p1->next;
        auto p2 = new node<T>(data, p1->next);
        p1->next = p2;
    }
    void del_first() {
        p = p->next;
    }
    void del(int ind) {
        if (ind == 0) {
            del_first();
            return;
        }
        auto p1 = p;
        for (int i = 0; (i < ind - 1) && (p1->next != nullptr); i++)
            p1 = p1->next;
        if (p1->next == nullptr) {
            p1 = nullptr;
            return;
        }
        p1->next = p1->next->next;
    }
    void print() const{
        auto p1 = p;
        while (p1){
            std::cout << p1->data<<" ";
            p1 = p1->next;
        }
        std::cout << std::endl;
    }
    ~mylist(){
        while (p)
        {
            auto p1 = p;
            p = p->next;
            delete p1;
        }
    }
};



int main()
{
    mylist<int> l;
    for (int i = 1; i < 10; i++)
        l.add_first(i);
    l.print();
    l.del(8);
    l.print();
}