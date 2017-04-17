//
// Created by jlgerber on 4/16/17.
//

#ifndef CPP_HAPPY_FUN_TIME_CONDVAR_HPP
#define CPP_HAPPY_FUN_TIME_CONDVAR_HPP

#include <mutex>
#include <iostream>
#include <string>
#include <deque>
#include <chrono>
#include <condition_variable>

namespace cv {
    std::deque<int> q;
    std::mutex cv_mu;
    std::condition_variable cond;

    void func_1() {
        int count = 10;
        while (count > 0) {
            std::unique_lock<std::mutex> locker(cv_mu);
            //std::cout << "\nT1 - locked. Pushing " << count << "\n";
            q.push_front(count);
            //std::cout << "T1 - unlock and notify_one()" << std::endl;
            locker.unlock();
            cond.notify_one();
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            count--;
        }
    }

    void func_2() {
        int data = 0;
        while (data != 1) {

            std::unique_lock<std::mutex> locker(cv_mu);
            //std::cout << "creating lock in t2" << std::endl;
            cond.wait(locker, [](){ return !q.empty();} );// waits to be signalled. While waiting, locker is unlocked
            //std::cout << "waited. pulling data from q" << std::endl;
            data = q.back();
            q.pop_back();
            locker.unlock();
            //std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "t2 got value from t1: " << data << std::endl;

        }
    }
}

int condvar() {
    std::thread t1(cv::func_1);
    std::thread t2(cv::func_2);


    t1.join();
    t2.join();

    return 0;

};

#endif //CPP_HAPPY_FUN_TIME_CONDVAR_HPP
