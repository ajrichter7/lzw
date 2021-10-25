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
	while (inp.get(character)) {
		code = huffman.encode(character);
		for (auto i : code) {
			bitio.output_bit(i);
		}
	}

//closes both the input and output streams
	inp.close();
 	out.close();
 	return 0;
}
