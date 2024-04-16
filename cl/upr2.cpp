#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Registry {
protected:
    char* registryName;
    string* records;
    size_t numberOfRecords;
public:
    static int numberOfActiveRegisters;

    Registry() :
        registryName(strdup("")), records(new string[2]), numberOfRecords(2)
    {
        numberOfActiveRegisters += 2;
    }

    Registry(const char* name, const string* records, const size_t numberOfRecords) {
        if(name == nullptr || records->empty())
            throw invalid_argument("Name and records cant be nullptr");
        
        if(numberOfRecords <= 0)
            throw invalid_argument("Records must be bigger than zero");

        this->registryName = strdup(name);
        this->numberOfRecords = numberOfRecords;

        this->records = new string[this->numberOfRecords];
        for (size_t i = 0; i < numberOfRecords; ++i)
            this->records[i] = records[i];

        numberOfActiveRegisters++;
    }

    Registry(const Registry &other) {
        this->registryName = strdup(other.registryName);
        this->records = other.records;
        this->numberOfRecords = other.numberOfRecords;

        numberOfActiveRegisters++;
    }

    Registry &operator = (const Registry &other) {
        if(this != &other) {
            delete [] this->registryName;
            delete[] this->records;
            this->registryName = strdup(other.registryName);
            this->records = other.records;
            this->numberOfRecords = other.numberOfRecords;
        }

        return *this;
    }

    ~Registry() {
        delete [] this->registryName;
        delete[] this->records;
        numberOfActiveRegisters--;
    }

    static int getActiveRegistries() {
        return numberOfActiveRegisters;
    }

    virtual void printRegistryInformation() const {
        cout << registryName << endl;
        for (size_t i = 0; i < numberOfRecords; ++i)
            cout << records[i] << endl;
    }
};

class PhoneRegistry : public Registry {
    string* phoneNumbers;
    size_t numberOfPhoneNumbers;

public:
    PhoneRegistry(const char* name, const string* records, const int numberOfRecords, const string* phoneNumbers, const size_t numberOfPhoneNumbers) :
        Registry(name, records, numberOfRecords)
    {
        if(phoneNumbers->empty()) 
            throw invalid_argument("Musnt be a nullptr");

        if(numberOfPhoneNumbers <= 0)
            throw invalid_argument("Number of phone numbers must be bigger than zero");

        this->numberOfPhoneNumbers = numberOfPhoneNumbers;
        this->phoneNumbers = new string[this->numberOfPhoneNumbers];
        for (size_t i = 0; i < numberOfPhoneNumbers; ++i)
            this->phoneNumbers[i] = phoneNumbers[i];
    }

    PhoneRegistry(const PhoneRegistry &other) :
        Registry(other)
    {
        this->phoneNumbers = other.phoneNumbers;
        this->numberOfPhoneNumbers = other.numberOfPhoneNumbers;
    }

    PhoneRegistry &operator = (const PhoneRegistry &other) {
        if(this != &other) {
            Registry::operator=(other);
            delete [] this->phoneNumbers;
            this->numberOfPhoneNumbers = other.numberOfPhoneNumbers;
            this->phoneNumbers = other.phoneNumbers;
        }

        return *this;
    }

    ~PhoneRegistry() {
        delete [] this->phoneNumbers;
    }


    void printRegistryInformation() const override {
        cout << registryName << endl;
        for (size_t i = 0; i < numberOfRecords; ++i) {
            cout << records[i] << " ";
            
            if (i < numberOfPhoneNumbers)
                cout << phoneNumbers[i];
            else
                cout << "-";

            cout << endl;
        }
    }
};

int Registry::numberOfActiveRegisters = 0;

int main() {
    string records[] = {"Record 1", "Record 2", "Record 3"};
    string phoneNumbers[] = {"123456789", "987654321"};

    Registry* registry = nullptr;
    PhoneRegistry* phoneRegistry = nullptr;

    try {
        registry = new Registry("Registry", records, 3);
        phoneRegistry = new PhoneRegistry("Phone Registry", records, 3, phoneNumbers, 2);
    } catch (const invalid_argument &e) {
        cout << e.what() << endl;
    }

    registry->printRegistryInformation();
    cout << "Active registries: " << Registry::getActiveRegistries() << endl;

    phoneRegistry->printRegistryInformation();
    cout << "Active registries: " << Registry::getActiveRegistries() << endl;

    delete registry;
    delete phoneRegistry;

    cout << "Active registries: " << Registry::getActiveRegistries() << endl;

    return 0;
}