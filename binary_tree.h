#pragma once

#include "header.h"

struct Node
{
    std::pair<int, std::string> val;
    Node * left = nullptr;
    Node * right = nullptr;
};

// class BinaryTree
// {
//     public:
//         BinaryTree();
//         ~BinaryTree();

//         void insert(std::pair<int, std::string>);
    
//     private:
//         Node * root;
//         void destroy_tree(Node *);
// };