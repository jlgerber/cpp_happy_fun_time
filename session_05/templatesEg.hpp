//
// Created by Jonathan Gerber on 11/6/16.
//

#pragma once
#include <iostream>

//
// Secret class template
//
template <typename T>
class Secret {
    T secret;
public:
    Secret(const T& rhs) {
        secret = rhs;
    }

    const T& getSecret() const { return secret; }

    void share() const {
        std::cout << "The secret is " << secret << std::endl;
    }
};

//
// max function template
//

template <class T>
 const T& max(  T& lhs,  T& rhs) {
    return lhs > rhs ? lhs : rhs;
}


// simple class to use as an example
class Employee {
    std::string name;
    int employee_id;
public:
    Employee(const std::string& name_, int id) : name(name_), employee_id(id) {};
    bool operator>(const Employee& other) { return this->employee_id <= other.employee_id; };

    const std::string& getName() const {return name;}
    const int& getId() const { return employee_id; }

    friend std::ostream &operator<<(std::ostream &os, const Employee &employee) {
        os << "<" << employee.name << ", id: " << employee.employee_id << ">";
        return os;
    }
};

// max specialization


template <>
const Employee& max<Employee>(Employee & lhs, Employee & rhs) {

    return lhs.getName() > rhs.getName() ? lhs : rhs;
}

