//
// Created by Jonathan Gerber on 9/27/16.
//

#pragma once

template<class T>
using Pimpl = const unique_ptr<T>;

class MyClass {
    class Impl; // defined in .cpp
    Pimpl<Impl> pimpl;
    /*..implementation..*/
};