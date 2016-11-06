//
// Created by Jonathan Gerber on 11/5/16.
//

#include <iostream>
#include <string>
#include <vector>

#include "PersonSharedPtr.hpp"


void person_eg() {
    std::cout << std::endl << "Person_eg()" <<std::endl << std::endl;

    Person person("Troy", "Mclure");
    person.greet();
    // now lets make a copy of person we want another one
    Person person2 = person;
    person2.greet();
}

void person_eg2() {
    // but i would never do something as dumb as in example 2 you say
    // well what about this?
    std::cout << std::endl << "Person_eg2()" << std::endl << std::endl;
    std::vector<Person> peeps;

    Person person("Troy", "Mclure");
    peeps.push_back(person);
    person.greet();
    peeps[0].greet();
}

int main() {

    person_eg();
    person_eg2();

}
