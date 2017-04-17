//
// Created by jlgerber on 4/16/17.
//

#ifndef CPP_HAPPY_FUN_TIME_UNIQUELOCK_HPP
#define CPP_HAPPY_FUN_TIME_UNIQUELOCK_HPP

#include <iostream>
#include <thread>
#include <string>
#include <fstream>

class LogFile {
    std::mutex m_mutex;
    std::once_flag m_flag;
    std::ofstream m_f;

public:
    LogFile() {};
    void shared_print(int id, std::string msg) {
        std::call_once(m_flag, [&](){ m_f.open("/tmp/log.txt"); std::cout << "Opened /tmp/log.txt" << std::endl; });

        std::unique_lock<std::mutex> locker(m_mutex, std::defer_lock);
        locker.lock();
        m_f << msg << " " << id << std::endl;
        std::cout << msg << " " << id << std::endl;
        locker.unlock();
    }

    ~LogFile() {
        if(m_f) {
            m_f.close();
            std::cout << "closed m_f" << std::endl;
        }
    }
};


void function_1(LogFile& log) {
    for(int i=0; i>-1000; i--) {
        log.shared_print(i, std::string("From t1"));
    }
}

int uniquelock() {
    LogFile log;
    std::thread t1(function_1, std::ref(log));

    for(int i=0; i<1000; i++) {
        log.shared_print(i, std::string("From Main"));
    }

    t1.join();
    return 0;
}
#endif //CPP_HAPPY_FUN_TIME_UNIQUELOCK_HPP
