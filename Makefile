all:
	g++ -c -fPIC BigInt.cpp
	g++ -shared -o libbigint.so bigInt.o
	LD_LIBRARY_PATH=./ g++ main.cpp -lbigint -I. -Wl,-rpath,. -L. -o BigInt
	
windows:
	g++ -c BigInt.cpp
	g++ -shared -o BigInt.dll BigInt.o
	g++ main.cpp BigInt.dll -I. -Wl,-rpath,. -L. -o BigInt.exe
	
	
	