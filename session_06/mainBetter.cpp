//
// Created by Jonathan Gerber on 10/28/16.
//

#include <iostream>
#include <string>
#include <vector>

#include "PersonBetter.hpp"


void person_eg() {
    std::cout << std::endl << "Person_eg()" <<std::endl << std::endl;

    PersonBetter person("Troy", "Mclure");
    person.greet();
    // now lets make a copy of person we want another one
    PersonBetter person2 = person;
    person2.greet();
}

void person_eg2() {
    // but i would never do something as dumb as in example 2 you say
    // well what about this?
    std::cout << std::endl << "Person_eg2()" << std::endl << std::endl;
    std::vector<PersonBetter> peeps;

    PersonBetter person("Troy", "Mclure");
    peeps.push_back(person);
    person.greet();
    peeps[0].greet();
    // now lets make a copy of person we want another one
}

int main() {

    person_eg();
    person_eg2();

}
