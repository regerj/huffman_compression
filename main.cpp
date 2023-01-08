#include "header.h"

int main()
{
    FileManager file_manager("poem.txt");
    std::map<std::string, int> my_map = file_manager.generate_map();

    std::cout << "FileManager's file_name: " << file_manager.get_file_name() << std::endl;

    for(auto it = my_map.begin(); it != my_map.end(); it++)
        std::cout << "Word: " << it->first << "\tFrequency: " << it->second << std::endl;

    HuffmanCode my_huffman_code(my_map);
    std::map<std::string, std::string> my_codelist = my_huffman_code.get_codelist();

    for(auto it = my_codelist.begin(); it != my_codelist.end(); it++)
        std::cout << "Plaintext: " << it->first << "\tCodeword: " << it->second << std::endl;
    return 0;
}