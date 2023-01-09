#pragma once

#include "header.h"

struct Node
{
    std::pair<int, std::string> val;
    Node * left = nullptr;
    Node * right = nullptr;
};