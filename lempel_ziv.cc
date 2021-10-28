#include "lempel_ziv.hh"
#include "bitio.hh"


LZW::compress(std::vector<bool> input) {
	//add each thing to a map
	map_t ZLW_map;

	//this is the current unique subsequence
	std::vector<bool> current;
	std::vector<bool> next;

	bit_stream_t output;

	//iterate through input
	for(int i = 0; i < input.size(); i++) {
		
		//get unique substrings
		next.push_back(input[i]);
		


		//if next is unique
		if(ZLW_map.find(next) == ZLW_map.end()){
			//we need to add it to the map
			ZLW_map[current] = i;
			//and then add it to the output
			output.append(ZLW_map.find(current));
			output.push_back(input[i]);

			//then we need to delete current and next
			current.clear();
			next.clear();

		}
		else
		{
			current.push_back(input[i]);
		}
	}

	//if the last thing isn't unique, we need to just add the 
	// thing's numerical pos to the end of the output
	if(!current.empty()){
		output.append(ZLW_map.find(current));
	}

	return output;
}


LZW::compress(std::vector<int> input) {
	bit_stream_t output;
	return output;
}

//this will take the name of a file and then read from it
LZW::compress(std::string fn, std::ostream* os) {
//alex ignore this

	//opening file from name
	std::string word;
	std::ifstream input_file (fn);

	//first check to confirm that file is open
	std::string assert_message = "the file " + fn + " isn't open, aborting"; 
	assert(input_file.is_open(), assert_message);
	

	//output
	BitIO outputter(&os, nullptr);

//ok don't ignore this:

	//iterate through all the words in the file
	while(std::getline(input_file,word))
	{


		std::cout << "the current word is "<<word<<std::endl;
		//variable 'word' contains a word from input file

		//iterating through the chars in word
		for(char c : word) {
			//do what you want with c

			std::cout <<"the current letter is "<<c<<std::endl;
		}


		//send the completed bits to Bitio
		outputter.output_bit(1); //this will take care of "1", it can also take care of "0"

	}

	input_file.close();


	return output;
}



LZW::decompress_to_bools (bit_stream_t input)
{
	std::vector<bool> output;
	return output;
}
LZW::decompress_to_ints (bit_stream_t input)
{
	std::vector<int> output;
	return output;
}


//given a file name, this will get bits 
LZW::decompress_to_string (std::string fn)
{
	//use bitio to get things from a file name
	ifstream input_file(fn);

	BitIO* next_bit = new BitIO(nullptr,input_file);

	//to get the next bit, use
	next_bit->input_bit();
	//it will return a bool

	std::string output;
	return output;
}
