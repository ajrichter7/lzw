#pragma once

#include <iostream>		//idk what this is for, silly me
#include <vector>		//hm idk what this is for either haha uwu
#include <map>			//for the map we use in LZW
#include <fstream>		//for ifstream
#include <cassert> 		//for ass


//this is a comparator for the map type, it will compare things
//by just putting them in order
struct alwaysbigger {
    bool operator()(const std::vector<bool>& a, const std::vector<bool>& b) const {
        return true;
    }
};


using bit_stream_t = std::vector<bool>;
//map t is 	key: subsequence
//			value: innovation symbol
using map_t = std::map<const std::vector<bool>, bool, alwaysbigger>;
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