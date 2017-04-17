//
// Created by jlgerber on 4/16/17.
//



#include <iostream>
#include <thread>
#include <string>
#include <mutex>

#ifndef CPP_HAPPY_FUN_TIME_WITHMUTEX_HPP
#define CPP_HAPPY_FUN_TIME_WITHMUTEX_HPP

std::mutex mu;

void print_msg(int idx, std::string& msg) {
    std::lock_guard<std::mutex> guard(mu);
    std::cout << msg << " " << idx << std::endl;
}

class Fctor2 {
public:
    void operator()(std::string& msg) {

        for (int i=0; i < 1000; i++) {
            print_msg(i, std::ref(msg));
        }
    }
};


int withmutex() {
    std::string s = "Calling from t1";
    std::thread t1((Fctor2()),std::ref(s));

    std::cout << "t1 created " << std::endl;

    std::string msg = "Calling From with_mutex ";

    try{
        std::cout << "Looping in with mutex" << std::endl;
        for(int x=0;x<1000;x++) {
            print_msg(x, std::ref(msg));
        }
    } catch(...) {
        t1.join();
        throw;
    }

    t1.join();

    return 0;
}

#endif //CPP_HAPPY_FUN_TIME_WITHMUTEX_HPP
