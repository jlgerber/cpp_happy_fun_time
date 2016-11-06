//
// Created by Jonathan Gerber on 10/28/16.
//

#include "PersonBetter.hpp"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

PersonBetter::PersonBetter(const std::string &fn, const std::string &ln) :
        firstname(new std::string(fn)),
        lastname(new std::string(ln))
{

    cout << "PersonBetter constructor called" << endl;
}

void PersonBetter::greet() const {
    cout << "hi my name is " << *firstname << " " << *lastname << endl;
}

PersonBetter::~PersonBetter() {
    cout << "PersonBetter destructor called" << endl;
    delete firstname;
    firstname = nullptr;
    delete lastname;
    lastname = nullptr;
}

PersonBetter::PersonBetter(const PersonBetter& other) {
    firstname = new std::string(*other.firstname);
    lastname = new std::string(*other.lastname);
}

// assignment operator
PersonBetter& PersonBetter::operator=(const PersonBetter& other) {
    cout<< "operator= canlled" << endl;
    // if the address of me is not the same as the address of other
    if(this != &other) {
        if (firstname != nullptr)
            delete firstname;
        if (lastname != nullptr)
            delete lastname;
        firstname = new std::string(*other.firstname);
        lastname = new std::string(*other.lastname);
    }
    return *this;
}