#include "lempel_ziv.hh"
#include "bitio.hh"

namespace LZW 
{
	bit_stream_t compress(std::vector<bool> input) {
#if 0
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
				output.push_back(ZLW_map[current]);
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
			output.push_back(ZLW_map[current]);
		}
#endif
		bit_stream_t output;
		return output;
	}


	//this will take the name of a file and then read from it
	bit_stream_t compress(std::string fn, std::ostream& os) {
	//alex ignore this

		//opening file from name
		std::string word;
		std::ifstream input_file (fn);

		//first check to confirm that file is open
		//std::string assert_message = "the file " + fn + " isn't open, aborting";
		assert(input_file.is_open());


		//output
		BitIO outputter(&os, nullptr);

	//ok don't ignore this:

		/*
		(1) Make a map w 256 code words which will coorespond to the ASCII symbols but
		will use 12 bit or 16 bit codings for the values

		| table |

		index : value = cooresponding ASCII
		0 : 0000 0000 0000 0000 = NUL
		1 : 0000 0000 0000 0001 = SOH
		.
		.
		.
		
		Should be a dictionary or map idk how c++ works

		nextcode = 256

		stringPrev = inputfile.getnextcharacter;
		while (can get a new character ~~> character=inputfile.getnextcharacter)
			index <= find(stringPrev, character)

			if table[index] exists: then stringPrev = stringPrev + character
			else:
				if nextcode <= (max number for 12 bit or 16 bit encodings ie 4000-sum or 65500-sum)
					{
					want to add the new stringPrev to the dictionary with the value of nextcode and increment nextcode++
					output the code
					stringPrev = character
					}

		// Otherwise we still want to make sure to output the last characters dont forget!
		output the code
		stringPrev = character
		*/
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

		bit_stream_t output;
		return output;
	}


	std::vector<bool> decompress_to_bools (bit_stream_t input)
	{
		std::vector<bool> output;
		return output;
	}


	//given a file name, this will get bits
	std::string decompress_to_string (std::string fn)
	{
		//use bitio to get things from a file name
		std::ifstream input_file(fn);

		BitIO next_bit(nullptr,&input_file);

		//to get the next bit, use
		bool next = next_bit.input_bit();
		//it will return a bool

		std::string output;
		return output;
	}
}
