#include <iostream>
#include <ostream>
#include <fstream>
#include "lempel_ziv.hh"
#include "bitio.hh"


void readfile(std::string textfile){
	std::ifstream file (textfile);
	std::cout << "die";
	std::string bitstream;
	if (file.is_open()) {
		while (file.good()){
			file >> bitstream;
			std::cout << bitstream;
		}
	}
};

int main(int argc, char** argv) {
	return 0;
}
