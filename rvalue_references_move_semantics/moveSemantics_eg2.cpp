//
// Created by Jonathan Gerber on 11/18/16.
//

#include <iostream>
#include <vector>
#include "move_constructor.hpp"

using namespace std;


void moves() {
    vector<A> a_vec;
    cout << "==> push_back A():" << endl;
    a_vec.push_back(A());

    cout << "==> push_back A():" << endl;
    a_vec.push_back(A());

    vector<B> b_vec;
    cout << "==> push_back B()" << endl;
    b_vec.push_back(B());
    cout << "==> push_back B()" << endl;
    b_vec.push_back(B());
}

int main() {
    moves();
    return 0;
}