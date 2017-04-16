//
// Created by jlgerber on 4/10/17.
//
/*!
 * clocks and timers
 */

#include <chrono>
/*
 historically , we have had a problem dealing with time due to precision.
 Chronos is a precision neutral library. It separates duration and timepoint from the clocks.

 Clock - 3 clocks

 1.  std::chrono::system_clock - current time according to the system (not steady)
 2. std::chrono::steady_clock  - runs at a uniform rate
 3. std::chrono::high_resolution_clock - provides the smallest possible tick period.

 Most important attribute of a clock is its frequency or period. In C++ this is represented by a ratio

 THe other important attribute of a clock is its duration.
 eg 2 hours. ( we need a number and a unit )

 duration <int, ratio<1,1>> // number of seconds stored in an int;
 duration <double, ratio<60,1>> // number of minutes stored in a double
 provides predefined duration
 namoseconds, microseconds, milliseconts, seconds, minutes, hours
 */
using std::cout; using std::endl;

int main(){
    // all clock periods are ratio
    std::ratio<2, 10> r;
    cout << r.num << "/" << r.den << endl;

    // get the period of the system clock
    cout << "The system clock period is ";
    cout << chrono::system_clock::period::num << "/" << chrono::system_clock::period::den << endl;

    // duration

    return 0;

}
