CXX=g++
CXX_FLAGS=--std=c++17 -Werror -Wextra -Wall -Pedantic

all: main.cc bitio.cc lempel_ziv.cc
	${CXX} ${CXX_FLAGS} -o lz main.cc bitio.cc lempel_ziv.cc

