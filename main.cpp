#include <iostream>
#include "BigInt.h"
using namespace std;

int main(int argc, char* argv[])
{
	BigInt a("1239");
	BigInt b = "564" ;
	BigInt c;

	c = a * b;
	cout << c.getString()<< endl;

	return 0;
}

