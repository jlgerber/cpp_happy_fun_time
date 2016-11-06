//
// Created by Jonathan Gerber on 10/28/16.
//

#include "Person.hpp"
#include <iostream>

using std::cout;
using std::endl;

Person::Person(const std::string &fn, const std::string &ln) :
        firstname(new std::string(fn)),
        lastname(new std::string(ln))
{

    cout << "Person constructor called" << endl;
}


void Person::greet() const {
    cout << "hi my name is " << *firstname << " " << *lastname << endl;
    delete firstname;
    delete lastname;
}

Person::~Person() {
    cout << "Person destructor called" << endl;
}
