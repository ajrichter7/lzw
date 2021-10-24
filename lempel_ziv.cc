#include "lempel_ziv.hh"


//bit_stream_t = std::vector<bool>;



LZW::compress(std::vector<bool> input) {
	//add each thing to a map
	map_t ZLW_map;
	vector<int>

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

LZW::compress(std::string input) {
	bit_stream_t output;
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
LZW::decompress_to_string (bit_stream_t input)
{
	std::string output;
	return output;
}
