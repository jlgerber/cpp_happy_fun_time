//
// Created by Jonathan Gerber on 11/22/16.
//

#ifndef CPP_HAPPY_FUN_TIME_SECRET_HPP
#define CPP_HAPPY_FUN_TIME_SECRET_HPP

#include <string>
#include <iostream>

class Secret {
    std::string* _secret;
public:
    Secret();
    Secret(const std::string& s);
    void tell() const;
    ~Secret();
};

template <typename T>
class SecretT {
    T _secret;
public:
    SecretT(const T& rhs)
    : _secret{rhs}
    {};

    void tell() const {
       std::cout << "secret " << _secret << std::endl;
    };
    SecretT(const SecretT& rhs) {
        _secret = rhs._secret;
    };
    SecretT& operator=(const SecretT& rhs) {
        if (this == &rhs)
            return *this;

        _secret = rhs._secret;
        return *this;
    };

};
#endif //CPP_HAPPY_FUN_TIME_SECRET_HPP
