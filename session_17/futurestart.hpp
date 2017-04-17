//
// Created by jlgerber on 4/16/17.
//

#ifndef CPP_HAPPY_FUN_TIME_FUTURESTART_HPP
#define CPP_HAPPY_FUN_TIME_FUTURESTART_HPP
#include<mutex>
#include <future>
#include <chrono>
#include <vector>

constexpr int SLEEP_DURATION=1;

namespace fut {
    using namespace std;

    int factorial(int N) {
        int res =1;
        for (int i = N; i > 1; i--) {
            res *= i;
        }

        //cout << "Result is " << res << endl;
        std::this_thread::sleep_for(std::chrono::seconds(SLEEP_DURATION));
        return res;
    }
}

int usefuture() {
    int x;
    //default
    //std::future<int> fu = std::async(std::launch::async | std::launch::deferred, fut::factorial,4);
    std::future<int> fu = std::async(std::launch::async, fut::factorial,4);

    x = fu.get();
    // can only call once
    return 0;
}

//
// Promises
//

namespace prom {
    using namespace std;
    int factorial(std::future<int>& f) {
        int res =1;

        int N = f.get();

        for (int i = N; i > 1; i--) {
            res *= i;
        }

        cout << "Result is " << res << endl;
        return res;
    }
}


int usepromise() {
    int x;

    std::promise<int> p;
    std::future<int> f = p.get_future();

    //default
    //std::future<int> fu = std::async(std::launch::async | std::launch::deferred, fut::factorial,4);
    std::future<int> fu = std::async(std::launch::async, prom::factorial, std::ref(f));

    // do something else
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
    p.set_value(4);

    x = fu.get();

    std::cout << "Get from child: " << x << std::endl;
    // can only call once
    return 0;
}


namespace shf {
    using namespace std;
    int factorial(std::shared_future<int> f) {
        int res =1;

        int N = f.get();

        for (int i = N; i > 1; i--) {
            res *= i;
        }
        std::this_thread::sleep_for(std::chrono::seconds(SLEEP_DURATION));

        return res;
    }
}

int usesharedfuture() {
    int iter = 4;
    int fdepth = 5;
    int x;
    auto start = std::chrono::steady_clock::now();
    std::promise<int> p;
    std::future<int> f = p.get_future();
    std::shared_future<int> sf = f.share();
    std::vector<std::future<int> > futures;

    for(int i=0; i < iter; i++) {
        futures.push_back(std::async(std::launch::async, shf::factorial, sf));
    }

    p.set_value(fdepth);

    for(int i=0; i<iter;i++) {
        x = futures[i].get();
        std::cout << "Future "<< i << " Get from child: " << x << std::endl;
    }

    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    std::cout << "Duration: " << std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl;

    std::cout << "now lets do that in serial and measure the difference" << std::endl;
    start = std::chrono::steady_clock::now();
    for(int i=0; i < iter; i++) {
        std::cout << "Factorial "<< i << " Get now: " << fut::factorial(fdepth) << std::endl;
    }
    end = std::chrono::steady_clock::now();
    diff = end - start;
    std::cout << "Duration: " << std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl;
    // can only call once
    return 0;
}
#endif //CPP_HAPPY_FUN_TIME_FUTURESTART_HPP
