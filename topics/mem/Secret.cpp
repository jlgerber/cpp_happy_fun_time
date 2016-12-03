//
// Created by Jonathan Gerber on 11/22/16.
//

#include "Secret.hpp"
#include <string>
#include <iostream>

using namespace std;

Secret::Secret() : _secret{nullptr} {}

Secret::Secret(const string& s) :
    _secret{new string(s)}
{

};

void Secret::tell() const {

    cout << "calling " << __PRETTY_FUNCTION__ << endl;
    if(_secret)
        cout << "secret is " << *(_secret) << endl;
    else
        cout << "No Secret Yet" << endl;
};

Secret::~Secret() {
    if(_secret != nullptr) {
        delete _secret;
        _secret = nullptr;
    }
};
