#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

void replace(std::string filename, std::string str1, std::string str2) {
	std::ifstream input(filename);
	if (input.fail()) {
		std::cout << "FILE OPEN FAILED" << std::endl;
		exit(1);
	}
	std::ostringstream ss;
	ss << input.rdbuf();
	std::string file = ss.str();
	input.close();
	std::size_t pos = file.find(str1, 0);
	while (pos != std::string::npos) {
		file.erase(pos, str1.length());
		file.insert(pos, str2);
		pos += str2.length();
		pos = file.find(str1, pos);
	}
	std::ofstream output(filename + ".replace");
	if (output.fail()) {
		std::cout << "FILE OPEN FAILED" << std::endl;
		exit(1);
	}
	output << file << std::endl;
	output.close();
}

int main(int argc, char** argv) {
	if (argc != 4) {
		std::cout << "USAGE : ./replace [FILENAME] [STRING1] [STRING2]" << std::endl;
	} else {
		replace(argv[1], argv[2], argv[3]);
	}
}
