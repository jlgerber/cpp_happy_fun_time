//
// Created by Jonathan Gerber on 10/27/16.
//
#include <iostream>
#include <string>
#include <vector>

#include "Person.hpp"

void new_var() {
    std::cout << "new_var()" << std::endl << std::endl;
    // allocate a string on the heap, assigning it to a pointer
    std::string *name = new std::string("Fred Flinstone");
    // use the pointer as we have already learned to do
    std::cout<< "his name is "<< *name << std::endl;
    // delete the memory
    delete name;
}

void new_array() {
    std::cout << "new_array()" << std::endl << std::endl;
    std::string* names= new std::string[2] {std::string("fred"), std::string("barney")};
    std::cout << names[0] << " " << names[1] << std::endl;

    delete[] names;
}

void person_eg() {
    std::cout << "Person_eg()" << std::endl << std::endl;

    Person person("Troy", "Mclure");
    person.greet();
}


void person_eg2() {
    std::cout << "Person_eg2()" << std::endl << std::endl;

    Person person("Troy", "Mclure");
    person.greet();
    // now lets make a copy of person we want another one
    auto person2 = person;
    person2.greet();
}

void person_eg3() {
    // but i would never do something as dumb as in example 2 you say
    // well what about this?
    std::cout << "Person_eg3()" << std::endl << std::endl;
    std::vector<Person> peeps;

    Person person("Troy", "Mclure");
    peeps.push_back(person);
    person.greet();
    peeps[0].greet();
    // now lets make a copy of person we want another one
}

int main() {
    new_var();
    new_array();
    person_eg();

   // person_eg2();
    person_eg3();

}
