//
// Created by Jonathan Gerber on 12/3/16.
//

#include <iostream>
//#include <utility>
//#include <string>
#include <vector>
#include <sstream>

#include "utils.hpp"

using namespace std;

int main(int argc, char *argv[], char* envp[]) {
    auto search_term = string{""};
    if(argc > 1) {
        search_term = argv[1];
    }

    while(*envp) {
        Stringpair ep = toPair(*envp++);
        std::size_t found = ep.first.find(search_term);
        if (found!=std::string::npos) {
            cout << ep.first << endl;
            for(auto&& v : ep.second) {
                if(v != "")
                    cout << '\t' << v << endl;
            }
            cout << endl;
        }
    }


    return 0;
}
