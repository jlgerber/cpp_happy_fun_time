//
// Created by Jonathan Gerber on 9/27/16.
//

#pragma once

class Tree {
    struct Node {
        vector<unique_ptr<Node>> children;
        Node* parent;
        /* ...data...*/
    };

    unique_ptr<Node> root;
    /*...*/
};

