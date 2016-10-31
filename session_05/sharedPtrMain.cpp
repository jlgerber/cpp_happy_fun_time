//
// Created by Jonathan Gerber on 10/29/16.
//

#include <iostream>
#include "SharedPtr.hpp"
#include <string>

using std::string;
using std::cout;
using std::endl;

void eg() {
    cout << "eg called" << endl;
    SharedPtr<string> sp2;
    {
        cout << "entered inner scope" << endl;
        SharedPtr<string> sp(new string("Fred"));
        sp2 = sp;
        cout << "leaving inner scope" << endl;
    }
    cout << "shared ptr value is " << *sp2 << endl;
    cout << "leaving eg() " << endl;
}
int main() {

    eg();
    return 0;
}