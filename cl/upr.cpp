// Person  <-- BasketballPlayer
//         <-- FootballPlayer

/**
 * name, age, weight, height, birtday, sex - MALE, FEMALE, OTHER, UNDEFINED(default value)
 * Constructor birthday, weight, height, sex
 * Constructor ()
 *
 * Copy constructor
 * Copy assignment operator
 * Destructor
 *
 * constant birthday - '07/07/2007'
 *
 * counter of people created
 *
 * getters
 *
 * setters
 *
 * growUpWithOneYear
 * Person - 1, 5, 2,
 * BasketballPlayer - 1, 7, 10
 * FootballPlayer - 1, 6, 6
 *
 * sport - print different messages for each class
 *
 */
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

enum Sex
{
    MALE,
    FEMALE,
    OTHER,
    UNDEFINED
};

class Person
{
    char *name;
    const string birthday;
    Sex sex;
    static unsigned numberOfPeopleCreated;

protected:
    unsigned int age;
    unsigned int weight;
    unsigned int height;

public:
    Person()
        : name(strdup("")), age(0), weight(0), height(0), birthday(""), sex(Sex::UNDEFINED)
    {
        numberOfPeopleCreated++;
    }

    Person(const string &birthday, unsigned int weight, unsigned int height, Sex s)
        : name(strdup("")), age(0), weight(weight), height(height), birthday(birthday), sex(s)
    {
        numberOfPeopleCreated++;
    }

    // TODO Copy constructor & Destructor
    Person(const Person &other)
        : name(strdup(other.name)), age(other.age), weight(other.weight), height(other.height), birthday(other.birthday), sex(other.sex) 
    {
        numberOfPeopleCreated++;
    }

    ~Person()
    {
        delete[] this->name;
        numberOfPeopleCreated--;
    }

    Person &operator=(const Person &other)
    {
        if (this->birthday != other.birthday)
        {
            throw runtime_error("Differance in birthday field");
        }

        if (this != &other)
        {
            delete[] this->name;
            this->name = strdup(other.name);
            this->age = other.age;
            this->weight = other.weight;
            this->height = other.height;
        }

        return *this;
    }

    const char *getName() const
    {
        return this->name;
    }

    void setName(const char *name)
    {
        if (name == nullptr)
        {
            throw invalid_argument("Nullptr passed as argument!");
        }
        delete[] this->name;
        this->name = strdup(name);
    }
    // TODO the rest of the getters and setters
    const string &getBirthday() const
    {
        return this->birthday;
    }

    unsigned int getAge() const
    {
        return this->age;
    }

    void setAge(unsigned int age)
    {
        if(age <= 0)
            throw invalid_argument("Age must be positive number!");

        this->age = age;
    }

    unsigned int getWeight() const
    {
        return this->weight;
    }

    void setWeight(unsigned int weight)
    {
        if(weight <= 0)
            throw invalid_argument("Weight must be positive number!");

        this->weight = weight;
    }

    unsigned int getHeight() const
    {
        return this->height;
    }

    void setHeight(unsigned int height)
    {
        if(height <= 0)
            throw invalid_argument("Height must be positive number!");

        this->height = height;
    }

    Sex getSex() const
    {
        return this->sex;
    }

    void setSex(Sex* s) {
        if(s == nullptr)
            throw invalid_argument("Nullptr passed as argument!");

        this->sex = *s;
    }

    virtual void doSport() const
    {
        cout << "I am not doing anything..." << endl;
    }

    virtual void growUpWithOneYear()
    {
        this->age++;
        this->weight += 5;
        this->height += 2;
    }

    static unsigned getNumberOfPeopleCreated()
    {
        return numberOfPeopleCreated;
    }
};

class BasketballPlayer : public Person
{
    string teamName;

public:
    BasketballPlayer()
        : Person(),
          teamName("")
    {
    }

    BasketballPlayer(const char *name, const string &birthday, unsigned age, unsigned weight, unsigned height, Sex s, string& teamName)
        : Person(birthday, weight, height, s)
    {
        this->setName(name);
        this->age = age;
        this->teamName = teamName;
    }

    // TODO Copy constructor
    BasketballPlayer(const BasketballPlayer &other)
        : Person(other)
    {
        this->teamName = other.teamName;
    }

    ~BasketballPlayer()
    {
        Person::~Person(); // Call the super destructor
    }

    BasketballPlayer &operator=(const BasketballPlayer &other)
    {
        if(this != &other) {
            Person::operator=(other);
            this->teamName = other.teamName;
        }

        return *this;
    }

    void doSport() const override
    {
        cout << "I am playing a basketball game!" << endl;
    }

    // TODO override growUpWithOneYear
    void growUpWithOneYear() override
    {
        this->age++;
        this->weight += 7;
        this->height += 10;
    }

    string getTeamName() const
    {
        return this->teamName;
    }

    void setTeamName(string& teamName)
    {
        if(teamName.empty())
            throw invalid_argument("Team name must not be empty!");
        
        this->teamName = teamName;
    }
};

class FootballPlayer : public Person
{
    // TODO same as BasketballPlayer
    string teamName;

public:
    FootballPlayer()
        : Person(),
          teamName("")
    {
    }

    FootballPlayer(const char *name, const string &birthday, unsigned age, unsigned weight, unsigned height, Sex s, string& teamName)
        : Person(birthday, weight, height, s)
    {
        this->setName(name);
        this->age = age;
        this->teamName = teamName; // Change if you want (make it a constructor's argument)
    }

    FootballPlayer(const FootballPlayer &other)
        : Person(other)
    {
        this->teamName = other.teamName;
    }

    ~FootballPlayer()
    {
        Person::~Person();
    }

    FootballPlayer &operator=(const FootballPlayer &other)
    {
        if(this != &other) {
            Person::operator=(other);
            this->teamName = other.teamName;
        }

        return *this;
    }

    void doSport() const override
    {
        cout << "I am playing a football game!" << endl;
    }

    void growUpWithOneYear() override
    {
        this->age++;
        this->weight += 6;
        this->height += 6;
    }

    string getTeamName() const
    {
        return this->teamName;
    }

    void setTeamName(string& teamName)
    {
        if(teamName.empty())
            throw invalid_argument("Team name must not be empty!");
        
        this->teamName = teamName;
    }

};

unsigned Person::numberOfPeopleCreated = 0;

int main() {
    try {
        Person person("07/07/2000", 70, 180, MALE);
        string teamName = "Lakers";
        BasketballPlayer basketballPlayer("Mike", "07/07/1995", 25, 80, 190, MALE, teamName);
        string teamName2 = "Real Madrid";
        FootballPlayer footballPlayer("David", "07/07/1990", 30, 90, 185, MALE, teamName2);

        person.setName("John");
        cout << "Person's name: " << person.getName() << endl;
        cout << "Person's birthday: " << person.getBirthday() << endl;
        cout << "Person's age: " << person.getAge() << endl;
        cout << "Person's weight: " << person.getWeight() << endl;
        cout << "Person's height: " << person.getHeight() << endl;
        cout << "Person's sex: " << person.getSex() << endl;
        person.doSport();
        person.growUpWithOneYear();
        cout << "Person's age after one year: " << person.getAge() << endl;

        cout << "\nBasketball player's name: " << basketballPlayer.getName() << endl;
        cout << "Basketball player's team: " << basketballPlayer.getTeamName() << endl;
        cout << "Basketball player's age: " << basketballPlayer.getAge() << endl;
        cout << "Basketball player's weight: " << basketballPlayer.getWeight() << endl;
        cout << "Basketball player's height: " << basketballPlayer.getHeight() << endl;
        cout << "Basketball player's sex: " << basketballPlayer.getSex() << endl;
        basketballPlayer.doSport();
        basketballPlayer.growUpWithOneYear();
        cout << "Basketball player's age after one year: " << basketballPlayer.getAge() << endl;

        cout << "\nFootball player's name: " << footballPlayer.getName() << endl;
        cout << "Football player's team: " << footballPlayer.getTeamName() << endl;
        cout << "Football player's age: " << footballPlayer.getAge() << endl;
        cout << "Football player's weight: " << footballPlayer.getWeight() << endl;
        cout << "Football player's height: " << footballPlayer.getHeight() << endl;
        cout << "Football player's sex: " << footballPlayer.getSex() << endl;
        footballPlayer.doSport();
        footballPlayer.growUpWithOneYear();
        cout << "Football player's age after one year: " << footballPlayer.getAge() << endl;
        cout << "Football player's weight after one year: " << footballPlayer.getWeight() << endl;

        cout << "\nTotal number of people created: " << Person::getNumberOfPeopleCreated() << endl;
    } catch(const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}