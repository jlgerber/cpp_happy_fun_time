//
// Created by Jonathan Gerber on 11/16/16.
//

#include <iostream>
#include <string>
#include <vector>
#include "move_constructor.hpp"


using namespace std;

class Address {
public:
    string city_;

    Address(){}

    Address(const string& city) : city_{city} {
        cout << "City " << city_ << " created" << endl;
    }

    ~Address() {
        cout << "City " << city_ << " destroyed" << endl;
    }
};

void inc(int& x) {x++;}

int meaningOfLife() { return 42;}

void swap_eg() {
    // this has a temporary that gets created as well as a number of assignment operators
    auto swap = [](int &a, int &b) {
        int tmp = a;
        a = b;
        b = tmp;
    };

    // this uses move semantics and rvalue references to do this via std::move.
    auto swap_better = [](int &a, int &b) {
        int tmp(move(a));
        a = move(b);
        b = move(tmp);
    };
}

int main() {
    int a = 0;
    inc(a); //works

    // does not work. 1 is an Rvalue
    //inc(1);

    // neither does this
    //int& mol = meaningOfLife();

    // but an rvalue reference works
    int&& mol = meaningOfLife();

    cout << "meaning of life is " << mol << endl;

    // this sucks because it is going to call the default constructor for each book
    Address book[100];
    // then, on top of this, we are going to call the constructor for paris and an assignment operator to boot.
    book[55] = Address("Paris");

    // we can solve this with a pointer...
    Address* book2[10];
    book2[5] = new Address("Paris Texas");
    // but then we have to remember to clean up.
    delete book2[5];

    // we would like to solve this with a reference.
    /*
    Address& bookref[100];
    bookref[10] = Address("Paris France");
    */
    // but we cannot.

    book[56] = move(Address("Hermosa"));

    return 0;
}