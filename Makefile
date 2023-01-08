
CC = g++ -std=c++11
exe_file = huffman.exe
$(exe_file): compressor.o decompressor.o file_manager.o huffman_code.o main.o
	$(CC) compressor.o decompressor.o file_manager.o huffman_code.o main.o -o $(exe_file)
compressor.o: compressor.cpp
	$(CC) -c compressor.cpp
decompressor.o: decompressor.cpp
	$(CC) -c decompressor.cpp
file_manager.o: file_manager.cpp
	$(CC) -c file_manager.cpp
huffman_code.o: huffman_code.cpp
	$(CC) -c huffman_code.cpp
main.o: main.cpp
	$(CC) -c main.cpp
clean:
	rm –f *.out *.o $(exe_file)