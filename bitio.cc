
#include "bitio.hh"

/*
* A simple class to perform stream I/O on individual bits.
* Before reading any bits, ensure your input stream still has valid inputs.
*/

// Construct with one of either an input stream or output (the other null)
BitIO::BitIO(std::ostream* os, std::istream* is) {
	if (!((os && is) || (!os && !is))) { //makes sure only one stream open
		os_ = os;
		is_ = is;
		buffer_ = 0;
		position_ = 7;
		flag_ = true;
	}
	else {
		assert(false);
	}
}

// Flushes out any remaining output bits and trailing zeros, if any:
//check if buffer isn't zero
BitIO::~BitIO() {
	if (position_ != 7 && os_) {
		*os_ << buffer_;
	}
}

// Output a single bit (buffered), will be done while there are still bits to read
// |s the mask with the buffer, void return 
void BitIO::output_bit(bool bit) {
	if (bit) {
		int mask = 1;
		mask <<= position_;
		buffer_ |= mask;
	}
	position_ -= 1;
	if (position_ < 0) {
		*os_ << buffer_;
		buffer_ = 0;
		position_ = 7;
	}
}

// Read a single bit (or trailing zero), &s the byte and the mask will return the
// new buffer
bool BitIO::input_bit() {
	if (flag_) {
		byte_ = is_->get();
		flag_ = false;
	}
	int mask = 1;
	mask <<= position_;
	buffer_ = byte_ & mask;
	position_ -= 1;
	if (position_ < 0) {
		byte_ = is_->get();
		position_ = 7;
	}
	return buffer_;
}
