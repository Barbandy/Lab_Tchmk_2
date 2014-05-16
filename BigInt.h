#pragma once
#define BASE 10
#include <iostream>
#include <vector>
using namespace std;

class BigInt
{
public:
	BigInt();
	BigInt(char* str);
	~BigInt();

	char* getString();
	bool operator > (BigInt B);
	bool operator < (BigInt B);
	bool operator <= (BigInt B);
	bool operator >= (BigInt B);
	bool operator == (BigInt B);
	bool operator != (BigInt B);

	BigInt operator +(const BigInt& B) const;	
	BigInt operator -(const BigInt& B) const;	
	BigInt operator -()const;					  
	BigInt operator *(const BigInt& B) const;
	BigInt operator /(const BigInt& B) const;
	BigInt operator %(const BigInt& B) const;
	BigInt operator ^(const BigInt& B) const;

	BigInt operator +=(const BigInt& B); 	   
	BigInt operator -=(const BigInt& B);	   
	BigInt operator *=(const BigInt& B);	   
	BigInt operator /=(const BigInt& B);		
	BigInt operator %=(const BigInt& B);		
	BigInt operator ^=(const BigInt& B);	   

	BigInt operator ++();	  
	BigInt operator --();	  
	BigInt operator ++(int);   
	BigInt operator --(int);  

private:
	vector<int> elements;
	int sign;
	void DelZeros();
	friend int cmp(BigInt A, BigInt B);

};

