//
// Created by jlgerber on 4/16/17.
//

#ifndef CPP_HAPPY_FUN_TIME_STDLOCK_HPP
#define CPP_HAPPY_FUN_TIME_STDLOCK_HPP

#include <mutex>
#include <iostream>

struct ShippingContainer {
    explicit ShippingContainer(int num) : things{num} {};

    int things;
    std::mutex m_mu;
};

//
// Transfer function
//
void transfer(ShippingContainer &from, ShippingContainer &to, int num) {
    //
    std::unique_lock<std::mutex> lock_from(from.m_mu, std::defer_lock);
    std::unique_lock<std::mutex> lock_to(to.m_mu, std::defer_lock);

    // lock both not worying about order
    std::lock(lock_from, lock_to);

    if (num > from.things)
        num = from.things;

    from.things -= num;
    to.things   += num;
    // unlocking happens in destructors.
}

int stdlock(){
    ShippingContainer st_a(156);
    ShippingContainer st_b(45);

    std::thread t1(transfer, std::ref(st_a),std::ref(st_b), 20);
    std::thread t2(transfer, std::ref(st_a), std::ref(st_b), 11);

    t1.join();
    t2.join();

    std::cout << "shipping container a has " << st_a.things << " things " << std::endl;
    std::cout << "shipping container b has " << st_b.things << " things " << std::endl;

    return 0;
}
#endif //CPP_HAPPY_FUN_TIME_STDLOCK_HPP
