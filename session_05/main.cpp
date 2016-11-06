//
// Created by Jonathan Gerber on 11/6/16.
//

#include <iostream>
#include <string>
#include "templatesEg.hpp"

using namespace std;

int main() {
    cout << "Secret<string>" << endl;
    Secret<string> strSecret("foobar");
    strSecret.share();

    cout << endl << "Secret<int>" << endl;
    Secret<int> intSecret(42);
    intSecret.share();

    cout << endl << "max<int>" <<endl;
    int a = 2;
    int b = 3;
    cout << "max of " << a << " and " << b << " is " << max<int>(a,b) << endl;

    cout << endl << "max<string>" << endl;
    string c("Hello");
    string d("World");
    cout << "max of " << c << " and " << d << " is " << max(c,d) << endl;

    cout << endl << "max<Employee>" << endl;
    Employee dougR("Doug Roble", 4);
    Employee jonathanG("Jonathan Gerber", 1231);
    cout << "max of " << dougR << " and " << jonathanG << " is " << max(dougR,jonathanG) << endl;
    return 0;
}