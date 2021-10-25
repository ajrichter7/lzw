CXX=g++
CXX_FLAGS=--std=c++17 -Werror -Wextra -Wall -Pedantic

all: main.cc bitio.cc lempel_ziv.cc
	${CXX} ${CXX_FLAGS} -o lz main.cc bitio.cc lempel_ziv.cc

compress: compressfile.cc bitio.cc lempel_ziv.cc
	${CXX} ${CXX_FLAGS} -o comp_lz compressfile.cc bitio.cc lempel_ziv.cc

decompress: decompressfile.cc bitio.cc lempel_ziv.cc
	${CXX} ${CXX_FLAGS} -o decomp_lz decompressfile.cc bitio.cc lempel_ziv.cc

