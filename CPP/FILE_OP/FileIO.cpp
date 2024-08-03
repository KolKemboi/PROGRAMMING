#include <iostream>
#include <fstream>
#include <sstream>
#include <cerrno>
#include <string>


std::string get_file_cont(const char* filename) {
	std::ifstream in(filename, std::ios::binary);
	if (in) {
		std::string fileCont;
		in.seekg(0, std::ios::end);
		fileCont.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&fileCont[0], fileCont.size());
		in.close();
		return fileCont;
	}
	throw(errno);
}

int main() {
	std::cout << "File IO" << std::endl;
	std::string data = get_file_cont("form.txt");
	std::cout << data << std::endl;
}