all: main.cpp BigInt.cpp
	g++ main.cpp BigInt.cpp -o BigInt -lm
	
windows: main.cpp BigInt.cpp
	g++ main.cpp BigInt.cpp -o BigInt -lm