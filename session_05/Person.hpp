//
// Created by Jonathan Gerber on 10/28/16.
//

#ifndef CPP_HAPPY_FUN_TIME_PERSON_HPP
#define CPP_HAPPY_FUN_TIME_PERSON_HPP
#include <string>

class Person {
    std::string* firstname;
    std::string* lastname;
public:
    Person(const std::string& fn, const std::string& ln);

    void greet() const;

    ~Person();
};


#endif //CPP_HAPPY_FUN_TIME_PERSON_HPP
