#include <iostream>		//cout, endl
#include <ostream>		//idk??
#include <fstream>		//ifstream,ofstream
#include <cassert>		//for assert
#include <string>		//for string
#include <chrono>		//for benchamring
#include "lempel_ziv.hh"
#include "constants.hh"

//this truncates before the original period
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

	size_t last_period = input_file.find_last_of('.');
	//this will contain the last period
	std::string original_extension = input_file.substr(last_period); 

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


	std::cout <<"compressed to " <<compress_wc <<" BYTES" <<std::endl;


	float milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>( endTime - startTime ).count();
	std::cout <<"tiime to compress: " << milliseconds << "ms"<<std::endl;

	outputfile.close();


	int	decompress_wc;
	std::string decompress_of = "OUTPUT" + original_extension;

	startTime = std::chrono::high_resolution_clock::now();
	decompress_wc = LZW::decompress_to_string(ofname, decompress_of);
	endTime = std::chrono::high_resolution_clock::now();

	std::cout <<"decompressed to " << decompress_wc	<<" huge ass words" <<std::endl;
	milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>( endTime - startTime ).count();
	std::cout <<"time to decompress: " << milliseconds << "ms"<<std::endl;


	outputfile.close();

}
