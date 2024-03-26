#include <cstring>
#include <iostream>
#include <exception>
/*pomagat za suzdavane na custom greshki i tqhnoto obrabotvane*/

using namespace std;

const char* StrDup(const char* s) {
    if (s == nullptr)
        throw invalid_argument("Null pointer passed to StrDup");
        
    size_t len = strlen(s);
    char* d = new char[len + 1];

    for(size_t i = 0; i < len; i++)
        d[i] = s[i];

    d[len] = '\0';

    return d;
}

int main() {

    try {
        const char* s = strDup(nullptr);
    } catch(exception& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    return 0;
}