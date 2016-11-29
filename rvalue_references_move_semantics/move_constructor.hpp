//
// Created by Jonathan Gerber on 11/18/16.
//

#pragma once
#include <iostream>

using std::cout;
using std::endl;

class A {
public:
    A() {
        cout << "constructor called" << endl;
    }
    A(const A& a) {
        cout << "copy constructor called" << endl;
    }
};

class B {
public:
    B() {
        cout << "constructor called" << endl;
    }
    B(const B& b) {
        cout << "copy constructor called" << endl;
    }

    B(B&& b) noexcept {
        cout << "move constructor called" << endl;
    }
};
