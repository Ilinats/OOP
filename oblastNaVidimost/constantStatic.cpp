/*static promenliva - ne e obvuzana s obekt, stojnostta v nachaloto se zadava, shte bude dostupna po vsqka vreme chtrez klasa
stattichnite metodi samo mogat da izpolzwat statichnite promenlivi*/

#include <iostream>
#include <cstring>

using namespace std;

class Class {
    const string name;
    int grade;

public:
    static int numberOfClasses; // statichna promenliva, koqto e edna za vsichki obekti ot tozi klas

    Class() 
        : name("A")
    {

    }

    Class(const string &name) // s referenciq, zashtoto inache shte rabotim s kopie, a ne s istinskata pamet
        : name(name), grade(0) // tuk za grade ima edin red po-malko (int grade = 10), dvete tochki kazvat, che inicializirame
    { 
        //tuk biha bili dve operacii (int grade; grade = 10;)
    }

    string getName() const { //const, za da ne davame dostup do private promenlivite
        return this->name;
    }
};

int Class::numberOfClasses = 0;

int main() {

    Class c1;
    cout << c1.getName() << endl;


    return 0;
}