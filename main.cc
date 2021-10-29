#include <iostream>		//cout, endl
#include <ostream>		//idk??
#include <fstream>		//ifstream,ofstream
#include <cassert>		//for assert
#include <string>		//for string
#include <chrono>		//for benchamring
#include "lempel_ziv.hh"
#include "bitio.hh"
#include "constants.hh"


std::string change_extension(std::string filename, std::string new_extension)
{
	//get location of last period
	//stolen from my thesis
	size_t last_period = filename.find_last_of('.');

	//also checks to make sure that the argument given is an actual file
	assert(last_period != filename.size() && "that's not a file name!!");

	std::string new_name = filename.substr(0,last_period) + new_extension;

	return new_name;
}





int main(int argc, char** argv) {
	//get arg from user

	assert(argc>1&& "moar args pl0x uwu (read: give me a file to do this on)");

	std::string input_file(argv[1]);
	if (DEBUGLOGS) std::cout<<"INPUT FILE NAME:" <<input_file<<std::endl;

	//our output file will be a file with the same name as the original, 
	//but with the extension .WE_LOVE_CS_421

	std::string ofname = change_extension(input_file, ".WE_LOVE_CS_421");

	if(DEBUGLOGS)std::cout <<"hi this is main, the ofname is "<<ofname<<std::endl;

	std::ofstream outputfile(ofname);
	//the output file is now open
	assert(outputfile.is_open());


	int compress_wc;
	//construct a lempelziv
	auto startTime = std::chrono::high_resolution_clock::now();
	compress_wc = LZW::compress(input_file, outputfile);
	auto endTime = std::chrono::high_resolution_clock::now();


	std::cout <<"compressed to " <<compress_wc <<" words" <<std::endl;


	float milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>( endTime - startTime ).count();
	std::cout <<"tiime to compress: " << milliseconds<<std::endl;

	outputfile.close();



	startTime = std::chrono::high_resolution_clock::now();
	LZW::decompress_to_string(ofname, "OUTPUT.TXT");
	endTime = std::chrono::high_resolution_clock::now();

	milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>( endTime - startTime ).count();
	std::cout <<"time to decompress: " << milliseconds<<std::endl;


	outputfile.close();

	//ok now it's time to call a lempel ziv
	//compress (input_file, &outputfile);






}
