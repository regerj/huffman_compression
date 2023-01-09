#pragma once

#include "header.h"

class FileManager
{
    public:
        FileManager();
        FileManager(std::string file_name);
        std::string get_file_name();
        void set_file_name(std::string);
        std::map<std::string, int> generate_map();
        ~FileManager();
    private:
        std::string file_name;
        std::ifstream file_handle;
};