#include "lempel_ziv.hh"
#include "bitio.hh"
#include "constants.hh"


uint16_t ReadU16(std::istream& file)
{
  uint16_t val;
  uint8_t bytes[2];

  file.read( (char*)bytes, 2 );  // read 2 bytes from the file
  val = bytes[0] | (bytes[1] << 8);  // construct the 16-bit value from those bytes

  return val;
}

void WriteU16(std::ostream& file, uint16_t val)
{
  uint8_t bytes[2];

  // extract the individual bytes from our value
  bytes[0] = (val) & 0xFF;  // low byte
  bytes[1] = (val >> 8) & 0xFF;  // high byte

  // write those bytes to the file
  file.write( (char*)bytes, 2 );
}







namespace LZW
{
	bit_stream_t compress(std::vector<bool> input) {

		bit_stream_t output;
		return output;
	}


	//this will take the name of a file and then read from it
	int compress(std::string fn, std::ostream& os) {

	/*
Start by constructing the table  with the ASCII characters in the first 256 entries. Get the first character and then since it with is only a single character it is in the table so we want to see if that plus the next character is in the
table which it is not, so then we are going to add that to the new table and increment the size of the table. Note that newcode is a counter to make sure that we don’t go past the number of possible substrings. If we reach that condition,
then we want to just encode the text using the values in the table and stop expanding the table.
 */
		int num_bytes = 0;

		//opening file from name
		std::string word;
		std::ifstream input_file (fn);

		//first check to confirm that file is open
		//std::string assert_message = "the file " + fn + " isn't open, aborting";
		assert(input_file.is_open());


		std::unordered_map<std::string, uint16_t> table;

		//Create a table of ASCII values as the beginning table for the dictionary LZW
		for (int i = 0; i < 255; i++) {
		  std::string x;
		  char ass = (char)(i + 1);
		  x+=( ass);
		  table[x] = i;
		}

		int nextcode = table.size(); //number of possible substrings

		char cur_c;

		// get the first character from the input file
		input_file.get(cur_c);

		char next_c;

		// Declare a new string that is initialized to just the current character will append in loop
		std::string cur_string;
		cur_string += cur_c;
		//std::cout <<"cur string is initially "  << cur_string <<"and cur_c is "<<cur_c <<std::endl;


		//Do this until we are at the end of the file. We want to compress the entire file
		while (input_file.peek() != EOF )
		{

			// Get the next character and append it to the string, then we want to see if the new string in table
			input_file.get(next_c);
			std::string next_string = cur_string + next_c;
			if (table.find(next_string) != table.cend()) // if the new string is in table
			{
		//		std::cout <<"cur string is "<<cur_string<<std::endl;
				cur_string = next_string;
		//		std::cout <<"cur string is NOW "<<cur_string<<std::endl;
			}

			else // if the new string was not in the table and we can still create more substrings to add to the table, then add to table
			{
		//		std::cout <<"next string is "<<next_string<<" and next_code is " <<nextcode<<std::endl;
				if (nextcode <= MAX_16_BIT_ENCODING)
				{
					table[next_string] = nextcode;

					nextcode++;

				}

				char innovation_c = next_c;

				//get the number that we're gonna convert to ascii
//				int number_to_be_converted_to_ascii = table[cur_string]; 

//				std::string rando_ascii = convert_int_to_rando_ascii(number_to_be_converted_to_ascii);

//				if(DEBUGLOGS)std::cout <<"rando ascii is "<<rando_ascii;

//				os<<rando_ascii<<"\n";
				WriteU16(os, table[cur_string]);
				num_bytes+=2;
				//output_to_ostream(os, table[cur_string], innovation_c);
				cur_string = next_c; // the current string becomes the next character

			}
		}
		//Making sure to get the last bits
		//std::cout <<"code that you're outputting "<<cur_string <<"and the value si " << table[cur_string]<<std::endl;
//		int number_to_be_converted_to_ascii = table[cur_string]; 

//		std::string rando_ascii = convert_int_to_rando_ascii(number_to_be_converted_to_ascii);

//		if(DEBUGLOGS)std::cout <<"rando ascii is "<<rando_ascii;

//		os<<rando_ascii;
		WriteU16(os, table[cur_string]);

		num_bytes++;


		input_file.close(); // close the stream

		return num_bytes;
	}


	std::vector<bool> decompress_to_bools (bit_stream_t input)
	{
		std::vector<bool> output;
		return output;
	}







	//given a file name, this will get bits
	int decompress_to_string (std::string fn, std::string of_n)
	{

		/*
Build the same dictionary and then we want to search through the dictionary to find the characters. This function will read in an encoded file and then we will write a decompressed version.
We read in the first value which is a number in ASCII so we look it up in the table we have created. Then we go and check if the next character can be read. If it is a value greater than the table size, then we are going
to want to add the new value as an entry of the old code + new character.
		*/
			
		int wc = 0;


		std::cout << "\n\n==DECOMPRESSION FILE==\nreading:"<<fn<<std::endl;
		std::ofstream output_file(of_n); // Writing to a file


		std::ifstream input_file(fn); // Reading from a file

		assert(input_file.is_open());

		//Construct the table to same way as in compression
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

#if 0
		input_file.getline (getstringbuf, 255);

		if (DEBUGLOGS)	std::cout <<"getstringbuf is: [" <<getstringbuf <<"]"<<std::endl;
		
		old_code = convert_rando_ascii_to_index(getstringbuf);
#endif
		old_code = ReadU16(input_file);
		//std::cout << "get string buf is "<<getstringbuf<<std::endl;
		// Search for the first character in the table and get the corresponding string to output
		std::string cur_string = table[old_code];
		output_file << cur_string ;

		//std::cout<<"old code is "<<old_code<<" and cur string is " <<cur_string<<std::endl;
		char cur_char = cur_string[0];

		// Check to see if we have reached the end of the file
		while (input_file.peek() != EOF) {
		  uint16_t new_code;
		  //input_file>>(new_code);
//		  input_file.getline (getstringbuf, 255);
		  new_code=ReadU16(input_file);
		  //new_code = convert_rando_ascii_to_index(getstringbuf);
		  
		  if (DEBUGLOGS) std::cout <<"newcode is "<<new_code<<std::endl;

		  if (DEBUGLOGS)std::cout << "nold code is " <<old_code<<std::endl;
		  
		  std::string cur_string = "";
			//If there is a new code but it is less than table size then we are going to want to add to table
		  if (new_code >= table.size()) {
		    cur_string = table[old_code];
		    cur_string = cur_string + cur_char;
		  } else {
		    cur_string = table[new_code];
		  }
			//Output cur string which is the string from table
		  output_file<<(cur_string);
		  wc++;
		  cur_char = cur_string[0];
			// add to the table
		  std::string thing_to_pushbacl = table[old_code] + cur_char;
		  table.push_back(thing_to_pushbacl);
			// Old code is now what new code used to be 
		  old_code = new_code;
		}
		return wc;
	}
}
