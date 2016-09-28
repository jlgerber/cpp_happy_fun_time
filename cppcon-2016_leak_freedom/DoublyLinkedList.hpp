//
// Created by Jonathan Gerber on 9/27/16.
//

#pragma once

class LinkedList {

    struct Node {
        unique_ptr<Node> next;

        Node *prev;
        /*..data..*/
    };

    unique_ptr<Node> root;
    /*...*/
};