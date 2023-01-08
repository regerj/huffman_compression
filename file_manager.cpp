#include "file_manager.h"

FileManager::FileManager()
{
    std::cout << "Enter the file name: ";
    std::getline(std::cin, file_name);
    return;
}

FileManager::FileManager(std::string file_name)
{
    this->file_name = file_name;
}

std::string FileManager::get_file_name()
{
    return file_name;
}

void FileManager::set_file_name(std::string file_name)
{
    this->file_name = file_name;
}

std::map<std::string, int> FileManager::generate_map()
{
    std::map<std::string, int> my_map;
    file_handle.open(file_name, std::ifstream::in);

    std::string word;
    while(file_handle >> word)
    {
        auto iter = my_map.insert(std::pair<std::string, int>(word, 1));
        if(iter.second)
        {
            iter.first->second++;
        }
    }
}

FileManager::~FileManager()
{
    file_handle.close();
}