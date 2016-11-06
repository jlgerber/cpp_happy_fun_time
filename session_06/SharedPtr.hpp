//
// Created by Jonathan Gerber on 10/29/16.
//

#pragma once
#include <iostream>

template <typename T>
class SharedPtr {
    T* ptr;
    int* cnt;
public:
    SharedPtr() : ptr{nullptr}, cnt{nullptr} {}

    // constructor
    SharedPtr(T* i_ptr) : ptr(i_ptr) {
        cnt = new int(1);
    }


    // copy sontructor
    SharedPtr(const SharedPtr& p) :
            ptr(p.ptr),
            cnt(p.cnt)
    {
        (*cnt)++;
    }
    // assignment operator
    SharedPtr& operator=(const SharedPtr& p) {
        if (this == &p)
            return *this;

        ptr = p.ptr;
        cnt = p.cnt;
        (*cnt)++;
        return *this;
    }

    // destructor
    ~SharedPtr() {
        (*cnt)--;
        std::cout << "SharedPtr destructor called. cnt is " << *cnt << std::endl;
        if (*cnt  <= 0) {
            std::cout << "SharedPtr deleting ptr" << std::endl;
            delete ptr;
            ptr = nullptr;
            *cnt = 0;
        }
    }
    // dereference overload
    T operator*() {
        return *ptr;
    }

};