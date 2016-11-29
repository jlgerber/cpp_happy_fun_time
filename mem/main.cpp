//
// Created by Jonathan Gerber on 11/22/16.
//

#include "Secret.hpp"

int main() {
    {
        Secret ss{};
        ss.tell();

        Secret s{"Foo"};
        s.tell();

        using intSecret = SecretT<int> ;
        auto is = intSecret{1};
        is.tell();
    }
    return 0;
}