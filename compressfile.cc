#include <iostream>
#include <fstream>
#include <string>
#include "lempel_ziv.hh"
#include "bitio.hh"

using namespace std;
using namespace LZW;

int main(int argc, char** argv) {

//checks to see if there is less than one argument, if so, will produce an error
	if (argc < 2) {
		cerr << "Need exactly one argument: input filename" <<endl;
		return -1;
	}

//checks to see if the input steam is open, if so it will produce an error
	ifstream inp(argv[1]);
	if (!inp.is_open()) {
		cerr<< "Can't open input file " << argv[1] << "!" << endl;
		return -2;
 	}

//creates an output file with the input file name, and then will add a ".comp"
 	char* tp = argv[1];
 	string fp;
 	fp.append(tp);
 	fp.append(".comp");
 	ofstream out;
 	out.open(fp);

/*
Creates an instance of LZW class and bitio class, and initializes a character
and a vector<bits_t> code. While you can still get a character from the file, we
encode the character into a vector of bits. Then it will output each bit calling
the bitio.output_bit() function.
*/

	BitIO bitio(&out, nullptr);
	LZW::bits_t code;
	char character;
	/*
	This is wrong, you want to get a stream so feed the stream of bits to encoder.
	The encoder checks if it is in the dictionary created (1) if it is then we move
	to next bit, (2) if not then we add this bit to the dictionary. Then output
	those bits, but if we just take in a character with no stopping condition 
	then we always stop after one character so bitio then is wrong.
	*/
	while (inp.get(character)) {
		while (LZW::encode(character)){
			/*
			Not me tryna solve the halting problem lol
			if LZW::encode(character) does not halt then we want to look at the next
			character using peek
			*/
		}
		code << LZW::encode(character);
		for (auto i : code) {
			bitio.output_bit(i);
		}
	}

//closes both the input and output streams
	inp.close();
 	out.close();
 	return 0;
}
