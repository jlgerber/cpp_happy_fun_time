//
// Created by Jonathan Gerber on 9/27/16.
//

#pragma once
#include <string>

typedef std::string Data;

class MyClass {
    const unique_ptr<Data[]> array;
    int array_size; // or Data* end;
    /*...*/
public:
    MyClass(size_t num_data) : array(make_unique<Data[]>(num_data));
};