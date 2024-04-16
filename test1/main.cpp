#include <iostream>
#include <string>
#include <cstring>
#include <exception>

using namespace std;

class Race
{
    // TODO add the necessary fields
    char* raceName;
    double* results;
    size_t numberOfResults;

public:
    static int numberOfTotalRaces;

    Race() : raceName(strdup("")), results(new double[1]), numberOfResults(1)
    {
        numberOfTotalRaces ++;
    };

    Race(const char *raceName, const double *results, size_t numberOfResults) {
        if(raceName == nullptr || results == nullptr)
            throw invalid_argument("Name and results can't be nullptr");

        if(numberOfResults <= 0)
            throw invalid_argument("Results must be bigger than zero");

        this->raceName = strdup(raceName);
        this->numberOfResults = numberOfResults;
        this->results = new double[numberOfResults];

        for (size_t i = 0; i < numberOfResults; ++i)
            this->results[i] = results[i];

        numberOfTotalRaces++;
    };

    Race(const Race &other) {
        this->raceName = strdup(other.raceName);
        this->results = other.results;
        this->numberOfResults = other.numberOfResults;

        numberOfTotalRaces++;
    };

    ~Race() {
        delete[] this->raceName;
        delete[] this->results;
        numberOfTotalRaces--;
    };

    Race &operator=(const Race &other) {
        if(this != &other) {
            delete[] this->raceName;
            delete[] this->results;

            this->raceName = strdup(other.raceName);
            this->results = other.results;
            this->numberOfResults = other.numberOfResults;
        }

        return *this;
    };

    static int getTotalRaces() {
        return numberOfTotalRaces;
    };

    void printRaceInformation() const {
        cout << "Total races: " << this->getTotalRaces() << ", ";

        double avrResult = 0;
        for (size_t i = 0; i < this->numberOfResults; ++i)
            avrResult += this->results[i];

        cout << "Race name: " << this->raceName << ", Avr res: " << avrResult / this->numberOfResults << endl;
    };
};

class Formula1Race : public Race
{
    // TODO add the necessary fields
    string* teams;
    size_t numberOfTeams;

public:
    Formula1Race(const char *raceName, const double *results, size_t numberOfResults, const string *teams, size_t numberOfTeams) 
        :   Race(raceName, results, numberOfResults)
    {
        if(teams == nullptr)
            throw invalid_argument("Teams can't be nullptr");

        if(numberOfTeams <= 0)
            throw invalid_argument("Teams must be more than zero");

        this->numberOfTeams = numberOfTeams;
        this->teams = new string[numberOfTeams];
        for (size_t i = 0; i < numberOfTeams; ++i)
            this->teams[i] = teams[i];
    };

    Formula1Race(const Formula1Race &other) 
        : Race(other)
    {
        this->teams = other.teams;
        this->numberOfTeams = other.numberOfTeams;
    };

    ~Formula1Race() {
        delete[] this->teams;
    };

    Formula1Race &operator=(const Formula1Race &other) {
        if(this != &other) {
            Race::operator=(other);
            delete[] this->teams;
            this->teams = other.teams;
            this->numberOfTeams = other.numberOfTeams;
        }

        return *this;
    };

    void printRaceInformation() const {
        Race::printRaceInformation();

        for (size_t i = 0; i < this->numberOfTeams; ++i)
            cout << this->teams[i] << endl;
    }
};

int Race::numberOfTotalRaces = 0;

int main()
{
    double* results = new double[5]{1, 2, 3, 4, 5};
    string* teams = new string[3]{"RedBull", "Ferrari", "McLaren"};

    Race* r = nullptr;
    Race* r2 = nullptr;
    Formula1Race* f1 = nullptr;
    cout << r->numberOfTotalRaces << endl;

    try {
        r = new Race("Monza", results, 5);
        cout << "When creating Race: " << r->getTotalRaces() << endl;
        f1 = new Formula1Race("Monza", results, 5, teams, 3);

        f1->printRaceInformation();

        delete f1;
        cout << "When deleting f1 race: " << r->getTotalRaces() << endl;

        delete r;
        cout << "When deleting race: " << r->getTotalRaces() << endl;
    } catch (const invalid_argument &e) {
        cout << e.what() << endl;
    }

    return 0;

}