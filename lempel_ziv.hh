#pragma once

#include <iostream>
#include <vector>


//this is an implementation for lempel ziv

namespace LZW
{
	//this will compress a string of bools 
	vector<bool> compress (vector<bool> input);

	//overloads for taking in numbers and strings
	vector<bool> compress (string int);
	vector<bool> compress (string input);



	decompress
}