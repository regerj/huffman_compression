#include "header.h"

int main()
{
    FileManager file_manager("poem.txt");
    std::map<std::string, int> my_map = file_manager.generate_map();

    for(auto it = my_map.begin(); it != my_map.end(); it++)
        std::cout << "Word: " << it->first << "\tFrequency: " << it->second << std::endl;

    return 0;
}