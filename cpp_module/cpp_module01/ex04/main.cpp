#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

void replace(char *filename, char *str1, char *str2) {

}

int main(int argc, char** argv) {
	if (argc != 4) {
		std::cout << "USAGE : ./replace [FILENAME] [STRING1] [STRING2]" << std::endl;
	} else {
		replace(argv[1], argv[2], argv[3]);
	}
}
