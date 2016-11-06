//
// Created by Jonathan Gerber on 10/28/16.
//

#ifndef CPP_HAPPY_FUN_TIME_PERSONBETTER_HPP
#define CPP_HAPPY_FUN_TIME_PERSONBETTER_HPP
#include <string>

class PersonBetter {
    std::string* firstname;
    std::string* lastname;
public:
    PersonBetter(const std::string& fn, const std::string& ln);

    void greet() const;
    PersonBetter(const PersonBetter& other);
    PersonBetter& operator=(const PersonBetter& other);
    ~PersonBetter();
};


#endif //CPP_HAPPY_FUN_TIME_PERSONBETTER_HPP
