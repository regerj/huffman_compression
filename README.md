# Huffman Compression

This is a very simple compression project which leverages Huffman compression to compress a text file. This currently only works for text files. It does not preserve newlines as of right now, but I would like to add that functionality.

## Todo:
- ~~Implement BinaryTree class~~
- ~~Implement FileManager class~~
- ~~Implement HuffmanCode class~~
- Implement Compressor class
- Implement Decompressor class
- Trim binary tree class (it's really not a class at all)
- Add ability to take file path of plaintext in as command line argument
- Add error handling
- Improve build script to work without explicit python call
- Add TCP Socket IPC with a compression and decompression server

## How to Compile:

I have provided a simple build script called `build.py` which has build, run, and clean functionality. You can run this build, run, or clean by passing any of those in as an argument to the script. For example, to run using this script, just enter the following command in your terminal:

```bash
> python ./build.py run
```

This will first build the project, and then run the project. The binary files are located in a seperate subdirectory called `./bin/` which will contain all `.o` files as well as the `.exe` file. This folder along with all of its contents are deleted when you run the build script with the clean option. If you want to make this less verbose, you can use an alias for "python ./build.py". 

## Classes:

### 1. BinaryTree

```cpp
struct Node
{
    std::pair<int, std::string> val;
    Node * left = nullptr;
    Node * right = nullptr;
};
```
This isn't really a class atm but rather just a struct definition for the node of a BST. I will likely clean this one out.

### 2. Compressor

**Unfinished class!**

```cpp
class Compressor
{
};
```

This class will eventaully compress a given text file using a codelist. A codelist could be generated using the HuffmanCode class detailed below.

### 3. Decompressor

**Unfinished class!**

```cpp
class Decompressor 
{
};
```

This class will eventually contain all the necessary functionality to decompress a compressed file, given the compressed file itself as well as the codelist generated from the compressor class.

### 4. FileManager

```cpp
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
```

This class handles analyzing the file itself and generates a wordlist with associated frequencies. I may combine this functionality with the compressor. It seems having a seperate class is kinda unnecessary.

### 5. HuffmanCode

```cpp
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
```

This class takes in a map containing a wordlist and their associated frequencies and computes Huffman coding information. You can retrieve the codelist using the member function get_codelist() in the form of a map with the keys being the plaintext and the values being the codewords as strings of bit.