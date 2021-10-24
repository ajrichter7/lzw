#pragma once

#include <iostream>
#include <vector>


using bit_stream_t = std::vector<bool>;
//this is an implementation for lempel ziv

namespace LZW
{
	//this will compress a string of bools 
	bit_stream_t compress (std::vector<bool> input);

	//overloads for taking in numbers and strings
	bit_stream_t compress (std::vector<int> input);
	bit_stream_t compress (std::string input);


	//we need decompress for bool vectors, strings, and ints
	std::vector<bool> decompress_to_bools (bit_stream_t input);
	std::vector<int> decompress_to_ints (bit_stream_t input);
	std::string decompress_to_string (bit_stream_t input);
}