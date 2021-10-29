CXX=g++
CXX_FLAGS=--std=c++17 -Werror -Wextra -Wall -pedantic

all: main.cc lempel_ziv.cc
	${CXX} -o lz main.cc lempel_ziv.cc
