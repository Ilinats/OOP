#include <iostream>

//virtual - pokazwa, che nqkava definiciq moje da bude promenqna
//hibavo e da pishem override

using namespace std;

class Base {
    public:
        Base() {
            cout << "Base constructor" << endl;
        }

        Base(int x) {
            cout << "Param" << endl;
        }

        ~Base() {
            cout << "Base destructor" << endl;
        }

        void print() const { // const pokazwa, che ne modificirame stojnostta na obekta
            cout << "Base" << endl;
        }
};

class Child : public Base {
    public:
        Child() 
            : Base()
        {
            cout << "Child constructor" << endl;
        }

        Child(int x) 
            : Base(x)
        {
            cout << "Child param" << endl;
        }

        Child(const Child &other) 
            : Base(other)
        {
            cout << "Child copy constructor" << endl;
        }

        ~Child() {
            cout << "Child destructor" << endl;
        }

        Child &operator = (const Child &other) {
            if(this != &other) {
                Base::operator=(other);
                cout << "Child operator" << endl;
            }
            return *this;
        }

        void print() const {
            cout << "Child" << endl;
        }
};

int main() {
    Child c;
    c.print();

    return 0;
}