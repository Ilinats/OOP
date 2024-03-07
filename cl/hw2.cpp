#include <iostream>
#include <cstring>

using namespace std;

class String
{
    char *data;
    size_t length;

public:
    String(const char *data) {
        this->length = strlen(data);
        this->data = new char[this->length + 1];
        strcpy(this->data, data);
    }

    String(const String &other) {
        this->length = other.length;
        this->data = strdup(other.data);
    }

    String &operator=(const String &other) {
        if(this != &other) {
            delete [] this->data;

            this->length = other.length;
            this->data = strdup(other.data);
        }

        return *this;
    }

    ~String() {
        delete [] this->data;
    }

    const char *getCString() const
    {
        return this->data;
    }

    size_t strlength() const
    {
        return this->length;
    }
};

int main()
{
    String myString("Test message");

    cout << "Expected: Test message, got: " << myString.getCString() << endl;

    String stringFromCopyConstructor(myString);
    cout << "Expected: Test message, got: " << stringFromCopyConstructor.getCString() << endl;

    String string("Test message 2");

    string = myString;
    cout << "Expected: Test message, got: " << string.getCString() << endl;
}