#include <iostream>
#include <fstream>
#include <string>

#include "huffman.hh"
#include "bitio.hh"

using namespace std;


int main(int argc, char** argv) {
	//returns an error if no input file given
	if (argc < 2) {
		cerr << "Need exactly one argument: input filename" <<endl;
		return -1;
	}

	//opens input file stream
	//reads bytes from input file as bytes not converted to characters
	ifstream inp(argv[1], ios::in | ios::binary);
	//returns an error if input file cannot be opened
	if (!inp.is_open()) {
		cerr<< "Can't open input file " << argv[1] << "!" << endl;
		return -2;
 	}

	//variable declarations needed later in the code
	Huffman huffman;
	int new_int;
	BitIO bitio(nullptr, &inp);

	//seting the name of the output file to the "name_of_the_file_inputed" + .txt
	char* tp = argv[1];
	string fp;
	fp.append(tp);
	fp.append(".txt");

	//opens the output file stream and the new file
	ofstream out;
	out.open(fp);

	//getting the length of the doc
	inp.seekg(0, inp.end); //sets the position to the end of file
	int length = inp.tellg(); //gets the position which is the length of the file
	inp.seekg (0, inp.beg); //resets the position to the beginning of the file
	int length_of_doc = length * 8 ;//get the bit length of the doc

	/* 
	bitio reads one bit at a time and sends that bit to the decoder which returns
	an integer. We check if that integer is nonnegative and not EOF indicating 
	that is it an ASCII character which we can then convert to a character and
	send to the output stream
	Once the EOF is found the files are closed and the function returns
	*/
	for (int i = 0; i < length_of_doc; i++){
		new_int = huffman.decode(bitio.input_bit());
		if (new_int >= 0 && new_int != Huffman::HEOF) {
			out << (char)new_int;
		}
		else if (new_int == Huffman::HEOF) {
			out.close();
			inp.close(); 
			break;
		}
	}
 	return 0;
}
