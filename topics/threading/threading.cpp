//
// Created by Jonathan Gerber on 4/13/17.
//

#include <iostream>
#include <thread>
#include <string>
#include <mutex>

using namespace std;

void func_simple() {
    cout << "Hello from thread1\n";
}
void func_simple2() {
    cout << "Hello from thread2\n";
}
void func_simple3 () {
    cout << "hello from thread3\n";
}

class Ftor {
public:
    void operator()() {
        for(int i=0; i > -100; i--) {
            cout << "From Ftor " << i << endl;
        }
    }
};

void messy() {
    Ftor ftor;
    auto t1 = thread(ftor);

    for(int x=0; x < 100; x++) {
        cout << "From Messy " << x << endl;
    }
    t1.join();
}

class Ftor2 {
public:
    void operator()(string& msg){
        cout << "Ftor2 says " << msg << endl;
        msg = "trust is pretty cool";
    }
};

void passing_params() {
    string s = "hard work is the mother of invention. But laziness is the father.";
    //auto t1 = thread((Ftor2()), s);
    // you cannot pass by reference without using a wrapper.
    // you can pass by pointer.
    auto t1 = thread((Ftor2()), std::ref(s));
    cout << "thread id for t1 = " << t1.get_id() << endl;
    cout << "parent thread id " << std::this_thread ::get_id() << endl;
    t1.join();

    s += "WOWOW";

    cout << "from passing_params " << s << endl;
}


void threading_1() {
    constexpr bool detatchit = true;
    auto t1 = thread(func_simple);
    auto t2 = thread(func_simple2);
    if (detatchit) {
        cout << "detatching threads\n";
        t1.detach();
        t2.detach();
    } else {
        cout << "joining threads\n";
        t1.join();
        t2.join();
    }
    if(t1.joinable()) {
        // you can only join or detatch once. So here is the test to see if this is valid.
        t1.join();
    }
}

//
// Data Race and Mutex
//

mutex mu;

void shared_print(string msg, int cnt) {
    std::lock_guard<std::mutex> guard(mu);
    // mu.lock();
    cout << msg << cnt;
    //mu.unlock();
}


int main() {
    cout << "how many treads can i run? " << std::thread::hardware_concurrency() << endl;
   // threading_1();
    //messy();
    passing_params();

    cout << "finishing up...." << endl;
    return 0;
}