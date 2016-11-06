//
// Created by Jonathan Gerber on 11/5/16.
//

#pragma once

#include <memory>
#include <string>

class Person{
    std::shared_ptr<std::string> firstname;
    std::shared_ptr<std::string> lastname;
public:
    Person(const std::string& fn, const std::string& ln) :
    firstname(std::make_shared<std::string>(fn)),
    lastname(std::make_shared<std::string>(ln))
    {};

    void greet() const {std::cout << "hi my name is " << *firstname << " " << *lastname << std::endl;};

};