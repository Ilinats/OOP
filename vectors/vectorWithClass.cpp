/*klas - instrukciq, kudeto nie suzdavame obekti, definirame proces, 
kojto go suzdava po tochno opredeln nachin
klas vs struktuta - razmerut (str e po-malka) i prilojenieto (klas ima unasledqvavne)
modifikatori - public, protected i private(toba e po default)
enkapsulaciq - zatvarqne na dannite, koito ne iskame da izpolzvame i im davame opredelen vhod i izhod, koito iskame da izpolzvame
metod vs funkciq - metodut e v klasa
property - promenliva v klas
vidove konstrukturi - osnoven? i s parametri*/
#include <iostream>

using namespace std;

class Test {
public:
    int a;
    Test() {
        a = 10;
    }
    ~Test() {
        cout << "Destructor" << endl;
    }
};

class Vector {
    int* data;
    size_t size;
    size_t capacity;

    void _resize() {
        this->capacity *= 2;
        int* new_data = new int[this->capacity];
        for (size_t i = 0; i < this->size; i++)
            new_data[i] = this->data[i];
        
        delete[] this->data;
        this->data = new_data;
    }

public:
    Vector() {
        this->capacity = 5;
        this->data = new int[this->capacity];
        this->size = 0;
    }

    Vector(int* data, size_t size, size_t capacity) {
        this->capacity = capacity;
        this->size = size;
        this->data = new int[this->capacity];
        for (size_t i = 0; i < size; i++)
            this->data[i] = data[i];

    }

    ~Vector() {
        delete[] this->data;
    }

    int at(int index) {
        if (index < 0 || index >= this->size) {
            cout << "Invalid index" << endl;
            return -1;
        }
        return this->data[index];
    }

    Vector& push_back(int value) {
        if(this->size == this->capacity)
           this->_resize(); 

        this->data[this->size++] = value;
        return *this;
    }
}

int main() {
    Test t;
    cout << t.a << endl;
    Test* t1 = new Test();
    delete t1;
    return 0;
}