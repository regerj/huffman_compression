
CC = g++ -std=c++11
exe_file = huffman.exe
$(exe_file): bin\compressor.o bin\decompressor.o bin\file_manager.o bin\huffman_code.o bin\main.o
	$(CC) bin\compressor.o bin\decompressor.o bin\file_manager.o bin\huffman_code.o bin\main.o -o $(exe_file)
bin\compressor.o: compressor.cpp
	$(CC) -c compressor.cpp
bin\decompressor.o: decompressor.cpp
	$(CC) -c decompressor.cpp
bin\huffman_code.o: huffman_code.cpp
	$(CC) -c huffman_code.cpp
bin\file_manager.o: file_manager.cpp
	$(CC) -c file_manager.cpp
bin\main.o: main.cpp
	$(CC) -c main.cpp
clean:
	rm –rfv *.out *.o $(exe_file)