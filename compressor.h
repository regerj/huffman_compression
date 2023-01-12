#pragma once

#include "header.h"

typedef std::map<std::string, std::string> stringMap;

class Compressor
{
    public:
        Compressor();
        Compressor(std::string);
        ~Compressor();
    private:
        stringMap codebook;
        FileManager * file_manager;
        HuffmanCode * huffman_code;

        void compress_message(std::string);
        void print_codebook();
};