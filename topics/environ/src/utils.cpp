//
// Created by Jonathan Gerber on 12/3/16.
//

#include "utils.hpp"

using namespace std;

using Stringvec = vector<string>;
using Stringpair = pair<string,Stringvec>;


void split(const string &s, char delim, vector<string> &elems) {
    stringstream ss;
    ss.str(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(move(item));
    }
}

std::vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return move(elems);
}

Stringpair toPair(const string& var) {
    auto sv = split(var, '=');
    if (sv.size() == 0)
        return Stringpair("", Stringvec{ string("") } );

    if (sv.size() == 1) {
        Stringvec parts = split(sv[0], ':');
        return Stringpair("", move(parts));
    }

    Stringvec parts = split(sv[1], ':');
    // TODO: change return type to a deque and handle the case where there is more than one =
    return Stringpair(move(sv[0]), move(parts));

}
