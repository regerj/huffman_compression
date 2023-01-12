#include "compressor.h"

Compressor::Compressor()
{
    std::cout << "Please input an argument, quitting now..." << std::endl;
    exit(-1);
}

Compressor::Compressor(std::string file_path)
{
    file_manager = new FileManager(file_path);
    std::map<std::string, int> frequency_map = file_manager->generate_map();
    
    huffman_code = new HuffmanCode(frequency_map);
    codebook = huffman_code->get_codelist();

    print_codebook();

    compress_message(file_path);
}

void Compressor::print_codebook()
{
    for(auto it = codebook.begin(); it != codebook.end(); it++)
        std::cout << "Plaintext: " << it->first << "\tCodeword: " << it->second << std::endl;
}

void Compressor::compress_message(std::string plaintext_file_name)
{
    std::string output_file_path;
    output_file_path = plaintext_file_name + ".out";

    std::ifstream input_file_handle;
    input_file_handle.open(plaintext_file_name, std::ifstream::in);

    std::ofstream output_file_handle;
    output_file_handle.open(output_file_path, std::ofstream::app);
    
    std::string word;
    while(input_file_handle >> word)
    {
        output_file_handle << codebook[word];
    }

    input_file_handle.close();
    output_file_handle.close();
}

Compressor::~Compressor()
{
    
}