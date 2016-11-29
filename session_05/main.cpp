//
// Created by Jonathan Gerber on 11/6/16.
//

#include <iostream>
#include <string>
#include "templatesEg.hpp"

using namespace std;

class Foobar {
    string* secret;
public:
    Foobar(const string& s) {
        secret = new string(s);
    }

    void tell() {
        cout << "my secret " << *secret << endl;
    }

~Foobar() {
        cout << " Hey, I am the destructor" << endl;
        if(secret != nullptr) {
            delete secret;
            secret = nullptr;
        }
    }
};
int main() {
    cout << "Secret<string>" << endl;
    Secret<string> strSecret("foobar");
    strSecret.share();

    auto & s_secret = strSecret.getSecret();
    //s_secret += "foo";
    cout << s_secret << endl;
    cout << strSecret.getSecret() << endl;
    cout << endl << "Secret<int>" << endl;
    Secret<int> intSecret(42);
    intSecret.share();

    cout << endl << "max<int>" <<endl;
    const int a = 2;
    const int b = 3;
    cout << "max of " << a << " and " << b << " is " << max(a,b) << endl;
    const int& maxint = max<int>(a,b);
   // maxint++;

    cout << endl << "max<string>" << endl;
    string c("Hello");
    string d("World");
    cout << "max of " << c << " and " << d << " is " << max(c,d) << endl;


    cout << endl << "max<Employee2>" << endl;
    Employee2 dougR("Doug Roble", 4);
    Employee2 jonathanG("Jonathan Gerber", 1231);
    cout << "max of " << dougR << " and " << jonathanG << " is " << max(dougR,jonathanG) << endl;

    //
    std::string* foo = new std::string{"foo"};
    cout << *foo << endl;
    delete foo;

    {
        auto myfoobar = Foobar("42");
        myfoobar.tell();
    }
    cout << " I am out of here" << endl;

    return 0;
}