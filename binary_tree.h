#pragma once

#include <string>

struct Node
{
    std::pair<int, std::string> val;
    Node * left = nullptr;
    Node * right = nullptr;
};