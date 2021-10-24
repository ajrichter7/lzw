#include "lempel_ziv.hh"


//bit_stream_t = std::vector<bool>;



LZW::compress(std::vector<bool> input) {
	//add each thing to a map
	map_t ZLW_map;

	//this is the current unique subsequence
	std::vector<bool> current;
	//iterate through input
	for(int i = 0; i < input.size(); i++) {
		//get unique substrings
		current.push_back(input[i]);
		
		//if current is unique
		if(ZLW_map.find(current) == ZLW_map.end()){
			//we need to add it to the map
			ZLW_map[current] = input[i];
		}

	}


	bit_stream_t output;
	//now we need to iterate through the ZLW_map and 
	//generate the codeeeeeeee
	for (auto it = ZLW_map.begin(); it != ZLW_map.end(); ++it){
		output.push_back
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
