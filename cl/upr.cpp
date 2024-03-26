#include <iostream>
#include <string>
#include <cstring>

using namespace std;

enum Sex {
    FEMALE,
    MALE,
    OTHER,
    UNDEFINED
};

class Person {
    char* name;
    unsigned int weight;
    unsigned int height;
    const string birthday;
    Sex sex;
    static unsigned personCount;

protected:
    unsigned int age;

public:
    Person() : 
        name(strdup("")), age(0), weight(0), height(0), birthday(""), sex(Sex::UNDEFINED) 
    {
        personCount++;
    }

    Person(const string& birthday, Sex s, unsigned int weight, unsigned int height) :
        name(strdup("")), age(0), weight(weight), height(height), birthday(birthday), sex(s) 
    {
        personCount++;
    }

    Person& operator=(const Person& other) {
        if(this->birthday != other.birthday) {
            throw runtime_error("Cannot change birthday");
        }

        if(this != &other) {
            delete[] this->name;
            this->name = strdup(other.name);
            this->age = other.age;
            this->weight = other.weight;
            this->height = other.height;
        }

        return *this;

    }

    const char *getName() const {
        return this->name;
    }

    void setName(const char *name) {

        if(!name) {
            throw invalid_argument("Name cannot be null");
        }

        delete[] this->name;
        this->name = strdup(name);
    }

    virtual void doSport() const {
        cout << "Doing something" << endl;
    }

    virtual void growUpWithOneYear() {
        this->age++;
        this->height += 5;
        this->weight += 2;
    }

};

class BasketballPlayer : public Person {
    string teamName;

public:
    BasketballPlayer() 
    : Person() {
    }

    BasketballPlayer(const char* name, const string& birthday, unsigned int weight, unsigned int height, unsigned age, Sex s)
    : Person(birthday, s, weight, height) {
        this->setName(name);
        this->age = age;
        this->teamName = "";
    }

    BasketballPlayer& operator=(const BasketballPlayer& other) {
        Person::operator=(other);
        this->teamName = other.teamName;
        return *this;
    }

    ~BasketballPlayer() {
        Person::~Person();
    }

    void doSport() const override {
        cout << "Playing basketball" << endl;
    }
};

unsigned Person::personCount = 0;

int main() {
    Person p1;
    Person p2("01.01.2000", Sex::FEMALE, 50, 160);
    return 0;
}