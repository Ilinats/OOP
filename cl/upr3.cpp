#include <iostream>

using namespace std;

class Test {
    size_t parameter; 
public:

    Test(size_t parameter) {
        this->parameter = parameter;
    }

    size_t getParameter() const {
        return parameter;
    }

    void setParameter(size_t parameter) {
        this->parameter = parameter;
    }
};

int main() {
    Test* test = new Test(4);
    cout << "Parameter: " << test->getParameter << endl;
    test->setParameter(27.45);
    cout << "Parameter: " << test->getParameter << endl;

    return 0;
}