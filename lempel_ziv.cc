#include "lempel_ziv.hh"
#include "bitio.hh"
#include "constants.hh"



void output_to_ostream(std::ostream& os, uint16_t index, char inov_c) {
	BitIO bitio(&os, nullptr);
	//first we need to output index
	for (int i = 0; i < 16; i++) {
		bool bit = index & 1;
		bitio.output_bit(bit);
		index = index >> 1; //go to the next thing in index
	}

	//and now we have to output innovation_c
	//8 bits for byte
	int ass = (uint16_t) inov_c;
	for (int i = 0; i < 16; i++) //please let me write my shitty loops
	{
		bool bit = ass & 1;
		bitio.output_bit(bit);
		ass = ass >> 1;
	}

	//OKAY WE DID IT

}


namespace LZW 
{
	bit_stream_t compress(std::vector<bool> input) {

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


		std::unordered_map<std::string, uint16_t> table;

		for (int i = 0; i < 255; i++) {
		  std::string x;
		  char ass = (char)(i + 1);
		  x+=( ass);
		  table[x] = i;
		}

		int nextcode = table.size(); //number of possible substrings

		char cur_c;

		input_file.get(cur_c);

		char next_c;

		std::string cur_string;
		cur_string += cur_c;
		std::cout <<"cur string is initially "  << cur_string <<"and cur_c is "<<cur_c <<std::endl;


		//this should start with the second character
		while (input_file.peek() != EOF )
		{

			input_file.get(next_c);
			std::string next_string = cur_string + next_c;
			if (table.find(next_string) != table.cend()) // if the new string is in table
			{
				std::cout <<"cur string is "<<cur_string<<std::endl;
				cur_string = next_string;
				std::cout <<"cur string is NOW "<<cur_string<<std::endl;
			}

			else
			{
				std::cout <<"next string is "<<next_string<<" and next_code is " <<nextcode<<std::endl;
				if (nextcode <= MAX_16_BIT_ENCODING) 
				{
					table[next_string] = nextcode; 

					nextcode++;

				}
				
				char innovation_c = next_c;


				std::cout <<"code that you're outputting "<<cur_string <<"and the value si " << table[cur_string]<<std::endl; 
				os<<table[cur_string]<<"\n";
				//output_to_ostream(os, table[cur_string], innovation_c);
				cur_string = next_c;
				
			}
		}
		std::cout <<"code that you're outputting "<<cur_string <<"and the value si " << table[cur_string]<<std::endl; 
		os<<table[cur_string];	
		//output_to_ostream(os, table[cur_string], 0);

		
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
	std::string decompress_to_string (std::string fn, std::string of_n)
	{
		std::cout << "\n\n==DECOMPRESSION FILE==\nreading:"<<fn<<std::endl;
		std::ofstream output_file(of_n);


		std::ifstream input_file(fn);

		assert(input_file.is_open());		

		std::vector<std::string> table;
		for (int i = 0; i < 255; i++) {
			std::string x;
		  char ass = (char)(i + 1);
		  x+=( ass);
		  table.push_back(x);
		}

		std::vector<std::string> output;

		uint16_t old_code;
		char getstringbuf[255];

	
		input_file.getline (getstringbuf, 255);
		old_code = atoi(getstringbuf);
		std::cout << "get string buf is "<<getstringbuf<<std::endl;

		std::string cur_string = table[old_code];
		output_file << cur_string ;
		
		std::cout<<"old code is "<<old_code<<" and cur string is " <<cur_string<<std::endl;
		char cur_char = cur_string[0];

		while (input_file.peek() != EOF) {
		  uint16_t new_code;
		  input_file>>(new_code);
		  
		  std::string cur_string = "";
		  if (new_code >= table.size()) {
		    cur_string = table[old_code];
		    cur_string = cur_string + cur_char;
		  } else {
		    cur_string = table[new_code];
		  }
		  output_file<<(cur_string);
		  cur_char = cur_string[0];

		  std::string thing_to_pushbacl = table[old_code] + cur_char;
		  table.push_back(thing_to_pushbacl);
		  old_code = new_code;
		}















#if 0







		int nextcode = 256; //number of possible substrings

		std::unordered_map<std::string, uint16_t> table;

		for(int i = 1; i < 256; ++i) 
		{
			std::string ass = "" + (char) i;
			table[ass] = i-1;
		}

		char old_c;
		char old_c_copy = old_c;


		char new_c;

		std::string prev_string = ""+ old_c;

		auto byte;
		std::ifstream input_file(fn);

//
		vector<std::string> table;
		for (int i = 0; i < 255; i++) {
		  string x = "" + (char)(i + 1);
		  table.push_back(x);
		}

		vector<std::string> output;

		uint16_t code;
		input_file >> code;

		cur_string = table[code];
		output.push_back(cur_string);

		while (! EOF) {
		  input_file >> code;
		  std::string next_string = table[code];
		  std::string next_table_entry = cur_string + next_string[0];
		  table.push_back(next_table_entry);
		  output.push_back(next_string);

		  cur_string = ??
		}
//
		char first_c; 
		input_file.get(first_c);

		std::string cur_string;

		while( input_file.peek() != EOF ) 
		{
			input_file.get(next_c);


			if (table.find(cur_string + next_c) != table.cend()) // if the new char is in the table
			{
				
				prev_string = next_string;

			}









		}



		//use bitio to get things from a file name

		//to get the next bit, use
		bool next = next_bit.input_bit();
		//it will return a bool
#endif
		std::string outputww;
		return outputww;
	}
}
