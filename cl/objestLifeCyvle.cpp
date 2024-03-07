/*monolit - celiq proekt
mikrosurvisna arhitektura - razbivat monolita
const char* - ne moje da promenqsh stojnostta na stringa
char const* - ne promenqsh kude sochi pointera 
const cahr const* - ne mojesh da promenqsh nito pointera, nito stojnostta
function overloading - funkcii s edno i sushto ime, no razlichni tipove i argumenti
shallow copy - e i e2 sochat kum edna i sushta pamet
deep copy - zadelq se nova pamet za e2
golqma petorka - kostruktor, copy konstruktor, move konstruktor, operator i destruktor*/

#include <iostream>
#include <cstring>

using namespace std;

enum Weekday {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
}

const char* translateDay(Weekday day) {
    char* result;

    switch (day) {
    case Weekday::MONDAY:
        result = strdup("Monday");
        break;

    case Weekday::TUESDAY:
        result = strdup("Tuesday");
        break;

    case Weekday::WEDNESDAY:
        result = strdup("Wednesday");
        break;

    case Weekday::THURSDAY:
        result = strdup("Thursday");
        break;
    
    case Weekday::FRIDAY:
        result = strdup("Friday");
        break;

    case Weekday::SATURDAY:
        result = strdup("Saturday");
        break;

    case Weekday::SUNDAY:
        result = strdup("Sunday");
        break;
    
    default:
        break;
    }

    return result;
}

Weekday translateDay(const char* day) {
    return Weekday::MONDAY;
} // sus string compare

class Event {
    Weekday day;
    char* name;
    char* description;
    unsigned duration;

public:
    Event(const char* name, const char* description, Weekday day, unsigned duration) {
        this->name = strdup(name);
        this->description = strdup(description);
        this->day = day;
        this->duration = duration;
    }

    Event(Event &e) { //vinagi trqbwa po referenciq - copy constructor
        this->name = strdup(e.name);
        this->description = strdup(e.description);
        this->day = e.day;
        this->duration = e.duration;
    }

    Event &operator = (const Event &e) {
        if (this != &e) {
            delete[] this->name;
            delete[] this->description;

            this->name = strdup(e.name);
            this->description = strdup(e.description);
            this->day = e.day;
            this->duration = e.duration;
        }

        return *this;
    }

    ~Event() {
        delete[] this->name;
        delete[] this->description;
    }
};

int main() {
    Event e("Test", "Test Test", Weekday::MONDAY, 60);

    Event e2 = e; //Event e2(e);
}