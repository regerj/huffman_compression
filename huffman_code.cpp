#include "huffman_code.h"

HuffmanCode::HuffmanCode()
{
    std::cout << "Please input an argument, quitting now..." << std::endl;
    exit(-1);
}

HuffmanCode::~HuffmanCode()
{

}

HuffmanCode::HuffmanCode(std::map<std::string, int> &val)
{
    generate_queue(val);
    generate_nodes();
    generate_tree();
    generate_codelist();
}

void HuffmanCode::generate_queue(std::map<std::string, int> &val)
{
    for(auto it = val.begin(); it != val.end(); it++)
    {
        my_queue.push(std::pair<int, std::string>(it->second, it->first));
    }
}

void HuffmanCode::generate_nodes()
{
    while(!my_queue.empty())
    {
        auto curr = my_queue.top();
        my_queue.pop();
        Node * new_node = new Node;
        new_node->val = curr;
        nodes.push(std::make_pair(curr.first, new_node));
    }
}

void HuffmanCode::generate_tree()
{
    Node * combined = nullptr;
    while(nodes.size() != 1)
    {
        Node * first = nodes.top().second;
        int first_prio = nodes.top().first;
        nodes.pop();

        Node * second = nodes.top().second;
        int second_prio = nodes.top().first;
        nodes.pop();

        combined = new Node;
        combined->left = first;
        combined->right = second;
        nodes.push(std::make_pair(first_prio + second_prio, combined));
    }
}

void HuffmanCode::generate_codelist()
{
    // TODO:    1. Use the nodes queue (should only contain the head) to 
    // TODO        traverse the tree and generate the codelist with a left
    // TODO        being a 0 and a right being a 1.

    std::string codeword = "";
    std::string plaintext = "";
    
    while(codeword.find('0') != std::string::npos || codeword == "")
    {
        codeword = "";
        plaintext = "";

        // Start from head
        Node * iter = nodes.top().second;
        Node * prev;
        Node * double_prev;
        while(true)
        {
            if(iter->left)
            {
                prev = iter;
                iter = iter->left;
                codeword.append("0");
            }
            else if(iter->right)
            {
                prev = iter;
                iter = iter->right;
                codeword.append("1");
            }
            else
            {
                if(iter->val.second == "") 
                {
                    if(prev->left == iter) prev->left = nullptr;
                    else prev->right = nullptr;
                    free(iter);
                    codeword = "";
                    break;
                }
                plaintext = iter->val.second;
                if(prev->left == iter) prev->left = nullptr;
                else prev->right = nullptr;
                free(iter);
                break;
            }
        }
        if(plaintext != "")
            my_codelist[plaintext] = codeword;
    }
    nodes.pop();
}

std::map<std::string, std::string> HuffmanCode::get_codelist()
{
    return my_codelist;
}