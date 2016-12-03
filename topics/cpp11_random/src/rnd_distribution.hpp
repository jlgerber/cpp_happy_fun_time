//
// Created by Jonathan Gerber on 12/2/16.
//

#pragma once

/*
 * How to set range
 * */

void naive() {
    header("Naive implmentation of bounded range");
    comment("we can create an engine with seed and print a value");
    //unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine e(109);//(seed);
    cout << e() << endl;

    comment("but what if we want it to fall in the range [0,5] :");
    for (auto i=0; i< 20; i++)
        cout << e() % 6 << " ";
    cout << endl;
    cout << "The naive way is to use the modulus operator as above ( e() % 6). but there are problems with this approach:" << endl;
    cout << "1. bad quality of randomness" << endl;
    cout << "2. can only provide uniform distribution" << endl;
    cout << endl;
}


template <typename Engine, typename Dist>
void printDist(Engine& e, Dist& distr  ) {
    for(auto i=0; i<20; i++)
        cout << distr(e) << " ";
    cout << endl;
};

void distr() {
    header("Distributions");
    std::default_random_engine e(109);
    comment("using uniform_int_distribution we get an int in range [0,5]");
    std::uniform_int_distribution<int> distr(0, 5); // Range: [0,5]
    printDist(e, distr);

    comment("using uniform_read_distribution, we get a range [0,5)");
    std::uniform_real_distribution<double> distR(0,5);
    e.seed(109);
    printDist(e, distR);

    comment("using poisson_distribution with mean 1.0");
    e.seed(109);
    std::poisson_distribution<int> distP(1.0);
    printDist(e, distP);


    comment("normal distribution");
    std::normal_distribution<double> distN(10.0, 3.0); // mean and std deviation
    std::vector<int> v(20);
    for(int i=0; i < 800; i++) {
        int num = distN(e); // convert double to int
        if (num >= 0 && num < 20)
            v[num]++;
    }
    for(int i=0; i < 20; i++) {
        cout << i << ": " << std::string(v[i], '*') <<endl;
    }
    cout << endl;
}

void other_engines() {
    header("other engines: merseinne twister");

    std::mt19937 e;
    std::default_random_engine de;

    comment("using uniform_int_distribution we get an int in range [0,5].(followed by reference default engine)");
    std::uniform_int_distribution<int> distr(0, 5); // Range: [0,5]
    printDist(e, distr);
    printDist(de, distr);
}