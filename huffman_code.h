#pragma once

#include <string>
#include <queue>
#include <vector>
#include <map>
#include <iostream>

#include "binary_tree.h"

// Lord have mercy this is disgusting
typedef std::priority_queue<std::pair<int, std::string>, std::vector<std::pair<int, std::string>>, std::greater<std::pair<int, std::string>>> CustomQueue;

class HuffmanCode
{
    public:
        HuffmanCode();
        HuffmanCode(std::map<std::string, int> &);
        std::map<std::string, std::string> get_codelist();
        ~HuffmanCode();
    private:
        CustomQueue my_queue;
        std::priority_queue<std::pair<int, struct Node *>, std::vector<std::pair<int, struct Node *>>, std::greater<std::pair<int, struct Node *>>> nodes;
        std::map<std::string, std::string> my_codelist;
        void generate_queue(std::map<std::string, int> &);
        void generate_nodes();
        void generate_tree();
        void generate_codelist();
};