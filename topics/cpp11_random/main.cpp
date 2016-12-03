//
// Created by Jonathan Gerber on 12/2/16.
//

#include <iostream>
#include "rnd_engine.hpp"
#include "rnd_distribution.hpp"

using namespace std;

int main() {
    default_engine();
    set_seed();
    shuffleit();
    naive();
    distr();
    other_engines();
    return 0;
}