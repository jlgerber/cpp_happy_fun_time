//
// Created by jlgerber on 4/16/17.
//

#include "nomutex.hpp"
#include "withmutex.hpp"
#include "uniquelock.hpp"
#include "stdlock.hpp"
#include "precondvar.hpp"

using namespace std;

enum class CallMode {
    NoMutex,
    Mutex,
    UniqueLock,
    StdLock,
    PreCondVar
};
int main() {

    CallMode mode = CallMode::PreCondVar;

    switch (mode) {
        case CallMode::NoMutex:
            return nomutex();
        case CallMode::Mutex:
            return withmutex();
        case CallMode::UniqueLock:
            return uniquelock();
        case CallMode::StdLock:
            return stdlock();
        case CallMode::PreCondVar:
            return precondvar();
    }
}