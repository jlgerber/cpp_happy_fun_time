//
// Created by Jonathan Gerber on 12/2/16.
//

#pragma once

#include <random>
#include <iostream>
#include <sstream>

/* Random Engine:
 *     Stateful generator that genrates random values within a predefined min and max
 * */

#pragma  once
using std::cout; using std::endl;
//
// Utilities
//
void header(const std::string& header) {

    cout << endl << endl;
    auto line = std::string(header.size(), '=');
    cout << line << endl;
    cout << header << endl;
    cout << line << endl << endl;
}

void comment(const std::string& comment) {

    auto line = std::string(comment.size(), '-');
    cout << endl << comment << endl;
    cout << line << endl;
}

//
// printRandom
//
void printRandom(std::default_random_engine e) {
    for(int i=0; i<10; i++) {
        cout << e() << " ";
    }
    cout << endl;
}

void default_engine() {
    std::default_random_engine eng;
    header("Default Random Engine");
    std::cout << "min " << eng.min() << std::endl;
    std::cout << "max " << eng.max() << std::endl;

    std::cout << "eng():" << eng() << std::endl;
    std::cout << "eng():" << eng() << std::endl;
    header("Engine is Stateful");

    comment("store state into a stringstream");
    std::stringstream state;
    state << eng; // save current state

    std::cout << "eng():" << eng() << std::endl;
    std::cout << "eng():" << eng() << std::endl;

   comment("restore state");
    state >> eng; // Restore the state
    std::cout << "eng():" << eng() << std::endl;
    std::cout << "eng():" << eng() << std::endl;


}

void set_seed() {
    std::default_random_engine e;
    std::default_random_engine e2;

    header("Initial Engine State");
    comment("given two engines, run through the first ten items of each.");
    printRandom(e);
    printRandom(e2);
    cout << "They each printed the same sequence" << endl;

    header("setting a seed value, using chrono time_since_epoch");
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine e3(seed);
    std::default_random_engine e_control;
    cout << "one engine created without setting a seed value. The second engine created with unique seed." << endl;
    printRandom(e_control);
    printRandom(e3);
    comment("calling e.seed() will reset engine to initial state");
    e3.seed();
    printRandom(e3);
    comment("calling e.seed(109) sets engine to state with 109 seed");
    e3.seed(109);
    printRandom(e3);

}

void shuffleit() {
    header("Shuffle using random");
    comment("We define a deck of cards as a vector of ints, 1-52");
    std::vector<int> carddeck;
    for(int i=1; i<=52; i++)
        carddeck.push_back(i);

    comment("now we use std::shuffle and print the deck:");
    std::shuffle(carddeck.begin(), carddeck.end(), std::default_random_engine());

    for (auto&& i : carddeck ) {
        cout << i << " ";
    }
    cout << endl;
}