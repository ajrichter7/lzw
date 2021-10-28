#include <iostream>
#include <ostream>
#include <fstream>
#include <cassert>
#include "lempel_ziv.hh"
#include "bitio.hh"


int main(int argc, char** argv) {
	//get arg from user

	assert(argc>1&& "moar args pl0x uwu (read: give me a file to do this on)");

	std::string input_file(argv[1]);
	std::cout<<input_file<<std::endl;

}
