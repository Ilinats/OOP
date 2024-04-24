#include <iostream>
#include <string>
#include <vector>
#include <stdexcept> // Include for std::invalid_argument
//vector <Base> shte shrinkne do Base i shte polzva negovite metodi
//vector <Base*> polzvame pointer, za da ne se shrinkne, shte se oburne s referencii
//virtualna tablica - stack, v kojto se pazqt referencii 

using namespace std;

class Base
{
protected:
    int a;

    virtual bool validateA(int a) const = 0; // napulno virtualen / ako ne go overridnem v nqkoe dete to stava sushto abstracten klas

public:
    virtual void print() const = 0;

    int getA() const {
        return a;
    }

    void setA(int a) {
        validateA(a);
        this->a = a;
    }

    virtual ~Base() { // pri decata parvim samo ako ima zadelena dinamichna pamet, zashtoot inache se vika avtomatichno

    }
};

class Child : public Base {

protected:
    bool validateA(int a) const override {
        if(a > 0) {
            throw invalid_argument("getA - a is positive");
        }
        return true;
    }

public:
    void print() const override {
        cout << "Child print function" << endl;
    }
};

class Child2 : public Base {
protected:
    bool validateA(int a) const override {
        if(a < 0) {
            throw invalid_argument("getA - a is negative");
        }
        return true;
    }

public:
    void print() const override {
        cout << "Child2 print function" << endl;
    }
};

int main() {
    vector<Base> arr;

    Child c;
    c.setA(5);
    cout << c.getA() << endl;
    Child2 c2;
    c2.setA(-2);
    cout << c2.getA() << endl;

    return 0;
}