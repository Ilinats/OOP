#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

/**
 * Your task is to add a counter of how many Objects of type String are currently in the memory, and how many have been created.
 */

class String
{
    char *data;
    size_t length;

public:

    static int currentStringCount;
    static int totalStringCount;

    String(const char *data)
    {
        this->length = strlen(data);
        this->data = strdup(data);
        currentStringCount++;
        totalStringCount++;
    }

    String(const String &other)
    {
        this->length = other.length;
        this->data = strdup(other.data);
        currentStringCount++;
        totalStringCount++;
    }

    String &operator=(const String &other)
    {
        if (this != &other)
        {
            delete[] this->data;
            this->length = other.length;
            this->data = strdup(other.data);
        }

        return *this;
    }

    ~String()
    {
        delete[] this->data;
        currentStringCount--;
    }

    const char *getCString() const
    {
        return this->data;
    }

    size_t strlength() const
    {
        return this->length;
    }

    static int getCurrentStringCount() {
        return currentStringCount;
    }

    static int getTotalStringCount() {
        return totalStringCount;
    }
};

int String::currentStringCount = 0;
int String::totalStringCount = 0;

int main()
{
    String *s = new String("Test message");

    vector<String *> arr;
    for (int i = 0; i < 3; i++)
    {
        arr.push_back(new String("Test message"));
    }

    cout << "Expected: 4, got: " << String::getCurrentStringCount() << endl;
    delete s;
    cout << "Expected: 3, got: " << String::getCurrentStringCount() << endl;
    cout << "Expected: 4, got: " << String::getTotalStringCount() << endl;

    return 0;
}