//
// Created by jlgerber on 4/16/17.
//

#include <iostream>
#include <thread>
#include <string>

#ifndef CPP_HAPPY_FUN_TIME_NOMUTEX_HPP
#define CPP_HAPPY_FUN_TIME_NOMUTEX_HPP


class Fctor {
public:
    void operator()(std::string& msg) {
        for (int i=0; i < 1000; i++) {
            std::cout << msg << " " << i << std::endl;
        }
    }
};


int nomutex() {
    std::string s = "Calling from t1";
    std::thread t1((Fctor()),std::ref(s));

    try{
        for(int x=0;x<1000;x++) {
            std::cout << std::string("From nomutex ") << x << std::endl;
        }
    } catch(...) {
        t1.join();
        throw;
    }

    t1.join();

    return 0;
}

#endif //CPP_HAPPY_FUN_TIME_NOMUTEX_HPP
