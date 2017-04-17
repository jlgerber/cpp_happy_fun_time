//
// Created by jlgerber on 4/16/17.
//

#ifndef CPP_HAPPY_FUN_TIME_PRECONDVAR_HPP
#define CPP_HAPPY_FUN_TIME_PRECONDVAR_HPP

#include <mutex>
#include <iostream>
#include <string>
#include <deque>
#include <chrono>

std::deque<int> q;
std::mutex pcv_mu;

void pvc_func_1() {
    int count = 10;
    while(count > 0){
        std::unique_lock<std::mutex> locker(pcv_mu);
        q.push_front(count);
        locker.unlock();
        std::this_thread::sleep_for(std::chrono::seconds(1));
        count--;
    }
}

void pvc_func_2() {
    int data = 0;
    while (data != 1) {
        std::unique_lock<std::mutex> locker(pcv_mu);
        if(!q.empty()) {
            data = q.back();
            q.pop_back();
            locker.unlock();
            std::cout << "I got value from t1: " << data << std::endl;
        } else {
            locker.unlock();
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }
}

int precondvar() {
    std::thread t1(pvc_func_1);
    std::thread t2(pvc_func_2);

    t1.join();
    t2.join();

    return 0;

};
#endif //CPP_HAPPY_FUN_TIME_PRECONDVAR_HPP
