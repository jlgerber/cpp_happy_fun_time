//
// Created by Jonathan Gerber on 9/27/16.
//

#pragma once

class Tree {

    struct Node {
        vector<shared_ptr<Node>>children;
        Data data;
    };
    shared_ptr<Node> root;
    shared_ptr<Data> find(/*..*/) {
        // uses share_ptr aliasing constructor
        /*...*/return {spn, &(spn->data)};
    }
};

//shared pointer to data getting returned. we want to track the Node.
// in comes shared pointer alias constructor
// {parent, pointer to parent's data}
// {spn, &(spn->data)}