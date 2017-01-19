//
// Created by Jonathan Gerber on 1/18/17.
//
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

void map() {
    string str = "hello world!", result;
    cout << str << endl;
    transform(str.begin(), str.end(), back_inserter(result), ::toupper);
    cout << result << endl;
}

bool IsOdd (int i) { return ((i%2)==1); }

void filter() {
    int myints[] = {1,2,3,4,5,6,7,8,9};            // 1 2 3 4 5 6 7 8 9

    // bounds of range:
    int* pbegin = myints;                          // ^
    int* pend = myints+sizeof(myints)/sizeof(int); // ^                 ^

    pend = remove_if (pbegin, pend, IsOdd);   // 2 4 6 8 ? ? ? ? ?
    // ^       ^
    cout << "the range contains:";
    for (int* p=pbegin; p!=pend; ++p)
        cout << ' ' << *p;
    cout << '\n';

}

void reduce() {


}
int main() {
    map();
    filter();
    return 0;
}