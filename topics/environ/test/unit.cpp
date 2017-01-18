//
// Created by Jonathan Gerber on 12/3/16.
//

#include "catch.hpp"
#include "utils.hpp"

using namespace std;

SCENARIO("Strings can be split provided a delimiter using the first form of split.") {

    GIVEN("A string of the form VAR=BLA") {
        const string test_str = "PATH=/usr/local/bin";

        WHEN("calling split on the string using '=' as the delimiter") {
            vector<string> ret_vec;
            split(test_str, '=', ret_vec);

            THEN("ret_vec should be populated with 2 strings: PATH and /usr/local/bin") {
                REQUIRE(ret_vec.size() == 2);
                REQUIRE(ret_vec[0] == "PATH");
                REQUIRE(ret_vec[1] == "/usr/local/bin");
            }
        }
    }

    GIVEN("A string without an '=' in it") {
        const string test_str = "/usr/var";

        WHEN("Calling split on the string using '=- as a delimiter") {
            vector <string> ret_vec;
            split(test_str, '=', ret_vec);

            THEN("ret_vec should be populated with one string: /usr/var") {
                REQUIRE(ret_vec.size() == 1);
                REQUIRE(ret_vec[0] == "/usr/var");
            }
        }
    }
}

SCENARIO("Strins can be split with a delimiter using the second form of split") {

    GIVEN("A string of the form VAR=BLA") {
        const string test_str{"PATH=/usr/local/bin"};

        WHEN("Calling split on the string using '=' as a delimiter") {
            vector<string> ret_vec = split(test_str, '=');

            THEN("the returned vector should have two elements: PATH and /usr/local/bin") {
                REQUIRE(ret_vec.size() == 2);
                REQUIRE(ret_vec[0] == "PATH");
                REQUIRE(ret_vec[1] == "/usr/local/bin");
            }
        }
    }

    GIVEN("A string without an '=' in it") {
        const string test_str = "/usr/var";

        WHEN("Calling split on the string using '=- as a delimiter") {
            vector <string> ret_vec = split(test_str, '=');

            THEN("ret_vec should be populated with one string: /usr/var") {
                REQUIRE(ret_vec.size() == 1);
                REQUIRE(ret_vec[0] == "/usr/var");
            }
        }
    }
}

SCENARIO("Calling toPair") {

    GIVEN("A string representing an environment variable assignment") {
        const string test_str = "PATH=/usr/local/bin";

        WHEN("Calling toPair on it") {
            auto env_pair = toPair(test_str);

            THEN("toPair returns a pair of strings, the first of which is PATH and the second of which is /usr/local/bin"){
                REQUIRE(env_pair.first == "PATH");
                REQUIRE(env_pair.second.size() == 1);
                REQUIRE(env_pair.second[0] == "/usr/local/bin");
            }
        }
    }

    GIVEN("A string representing an environment variable assignment, with multiple paths, separated by a ':'") {
        const string test_str = "PATH=/usr/local/bin:/usr/bin:~/bin";

        WHEN("Calling toPair on it") {
            auto env_pair = toPair(test_str);

            THEN("toPair returns a pair, the first item being PATH and the second being a vector of size 3"){
                REQUIRE(env_pair.first == "PATH");
                REQUIRE(env_pair.second.size() == 3);
                REQUIRE(env_pair.second[0] == "/usr/local/bin");
                REQUIRE(env_pair.second[1] == "/usr/bin");
                REQUIRE(env_pair.second[2] == "~/bin");

            }
        }
    }

    GIVEN("A string without an assignment in it") {
        const string test_str = "/usr/bin";

        WHEN("Calling to pair on it") {
            auto env_pair = toPair(test_str);

            THEN("The first item should be blank and the second item should be /usr/bin") {
                REQUIRE(env_pair.first == "");
                REQUIRE(env_pair.second.size() == 1);
                REQUIRE(env_pair.second[0] == "/usr/bin");
            }
        }
    }
}