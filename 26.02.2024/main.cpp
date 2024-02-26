#include <iostream>
#include <vector>

class Product {
protected:
    std::string name;
    std::string img = R"(C:\)";
public:
    Product(std::string name) :name(name) {}
    bool operator==(const Product& pr) {
        return name == pr.name;
    }
    friend std::ostream& operator<<(std::ostream& os, const Product& pr) {
        os << pr.name;
        return os;
    }
};

class Milk:public Product {
public:
    Milk() :Product("Milk") {}
};

class Fish :public Product {
public:
    Fish() :Product("Fish") {}
};

class Sausage :public Product {
public:
    Sausage() :Product("Sausage") {}
};

class Shelf {
    std::vector<Product> cells;
public:
    Shelf(int size) {
        if (size < 0) throw std::exception("Uncorrect size!");
        cells.resize(size,Product(""));
    }
    bool add(Product pr) {
        int i;
        for (i = 0; i < cells.size(); i++) {
            if (cells[i] == Product("")) break;
        }
        if (i < cells.size()) {
            cells[i] = pr;
            return true;
        }
        else return false;
    }
    bool extract(int cell) {
        if ((cell < 0) && (cell >= cells.size())) return false;
        std::cout << cells[cell] << " extracted." << std::endl;
        cells[cell] = Product("");
        return true;
    }
};

class Fridge {
    std::vector<Shelf> shelfs;
public:
    Fridge(int arr[], int size) {
        for (int i = 0; i < size; i++)
            shelfs.push_back(Shelf(arr[i]));
    }
    int addProduct(Product pr) {
        int i = 0;
        while ((i < shelfs.size()) && (!shelfs[i].add(pr)))
            i++;
        if (i == shelfs.size()) return -1;
        return i;
    }
    bool extractProduct(int shelf, int cell) {
        if ((shelf < 0) && (shelf >= shelfs.size())) return false;
        return shelfs[shelf].extract(cell);
    }
};


int main(){
    /*std::vector<int> array1 = {2,5,3,7};
    array1.push_back(45);
    array1[2] = 89;
    for (int i = 0; i < array1.size(); i++) {
        std::cout << array1[i] << " ";
    }
    std::cout << std::endl;
    std::vector<int>::iterator iter = array1.begin();
    while (iter != array1.end()) {
        std::cout << *iter << " ";
        iter++;
    }
    std::cout << std::endl;
    for (auto el : array1) {
        std::cout << el << " ";
    }
    array1.push_back(67);
    array1.pop_back();*/

    int arr[10]{ 2,6,2,2,4,2,6,2,2,4 };
    Fridge fridge(arr, std::size(arr));
    fridge.addProduct(Milk());
    fridge.addProduct(Fish());
    fridge.addProduct(Sausage());
    std::cout<<fridge.extractProduct(1, 0);
}