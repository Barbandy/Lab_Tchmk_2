#include "BigInt.h"


BigInt::BigInt()
{
	sign = 0;
	elements.push_back(0);
}

BigInt::BigInt(char* str)
{
	sign = 0;
	if(str[0] == '-')
	{
		sign = 1;
	}

	int SizeStr = strlen(str);
	for(int i = SizeStr - 1; i >= sign; i--)
		elements.push_back(str[i] - '0');
	// TODO: проверка
}

BigInt::~BigInt()
{
	elements.clear();
}

char* BigInt::getString()
{
	char* str = new char [elements.size() + 1 + sign]();
	int j = elements.size() + sign - 1;
	for(size_t i = 0; i < elements.size(); i++)
	{
		str[j] = elements[i] + '0';
		j--;
	}
	if(sign == 1)
		str[0] = '-';

	return str;
}

int cmp(BigInt A, BigInt B)
{ 
	int sign_A = 1;
	if(A.sign == 1)
		sign_A = -1;

	if(A.sign != B.sign)
		return sign_A;

	if (A.elements.size() > B.elements.size())
		return sign_A;

	if (A.elements.size() < B.elements.size())
		return -sign_A;

	int	i = A.elements.size() - 1;

	while( A.elements[i] ==  B.elements[i] && i > 0)
	{
		i--;
	}
	return  (A.elements[i] -  B.elements[i]) * sign_A;


	return 0;
}

bool BigInt::operator>(BigInt B)
{
	return cmp(*this, B) > 0;
}

bool BigInt::operator<(BigInt B)
{
	return cmp(*this, B) < 0;
}

bool BigInt::operator<=(BigInt B)
{
	return cmp(*this, B) <= 0;
}

bool BigInt::operator>=(BigInt B)
{
	return cmp(*this, B) >= 0;
}

bool BigInt::operator==(BigInt B)
{
	return cmp(*this, B) == 0;
}

bool BigInt::operator!=(BigInt B)
{
	return cmp(*this, B) != 0;
}

BigInt BigInt::operator + (const BigInt & B) const
{
	BigInt A = *this;

	if (A.sign)
	{
		if (B.sign)
			return -(-A + (-B));
		else
			return B - (-A);
	}
	else if (B.sign)
		return A - (-B);

	int carry = 0; 

	for (size_t i = 0; i < max(A.elements.size(), B.elements.size()) || carry != 0; i++)
	{
		if (i == A.elements.size())
			A.elements.push_back(0);

		A.elements[i] += carry +  (i < B.elements.size() ? B.elements[i] : 0);

		carry = A.elements[i] >= BASE;

		if (carry != 0)
			A.elements[i] -= BASE;
	}

	return A;
}

BigInt BigInt::operator - (const BigInt& B) const
{
	BigInt A = *this;

	if (B.sign)
		return A + (-B);
	else if (A.sign)
		return -(-A + B);
	else if (A < B)
		return -(B - A);

	int carry = 0; 

	for (size_t i = 0; i < B.elements.size() || carry != 0; i++)
	{
		A.elements[i] -= carry +  (i < B.elements.size() ? B.elements[i] : 0);

		carry = A.elements[i] < 0;

		if (carry != 0)
			A.elements[i] += BASE;
	}
	A.DelZeros();
	return A;

}

BigInt BigInt::operator* (const BigInt& B) const
{
	BigInt A = *this;
	BigInt C;
	size_t temp = 0, carry = 0;
	C.elements.resize( A.elements.size() + B.elements.size());
	for(size_t i = 0; i < A.elements.size(); i++)
	{
		carry = 0;
		for(size_t j = 0; j < B.elements.size(); j++)
		{
			temp = A.elements[i] * B.elements[j] + C.elements[i+j] + carry; 
			carry  = temp / BASE;
			C.elements[i + j] = temp % BASE;
		}
		C.elements[i + B.elements.size()] = carry;
	}
	 C.sign = A.sign!=B.sign;

	C.DelZeros();

	return C;
}

void BigInt::DelZeros()
{
	while (this->elements.size() > 1 && this->elements.back() == 0)
		this->elements.pop_back();
	if(this->elements.size() == 1 && this->elements[0] == 0)
		this->sign = 0;


}

BigInt BigInt::operator +=(const BigInt& B)
{
	return *this = *this + B;
}

BigInt BigInt::operator -=(const BigInt& B)
{
	return *this = *this - B;
}

//BigInt BigInt::operator *=(const BigInt& B)
//{
//	return *this = *this * B;
//}
//
//BigInt BigInt::operator /=(const BigInt& B)
//{
//	return *this = *this / B;
//}
//
//BigInt BigInt::operator %=(const BigInt& B)
//{
//	return *this = *this % B;
//}
//
//BigInt BigInt::operator ^=(const BigInt& B)
//{
//	return *this = *this ^ B;
//}

BigInt BigInt::operator -() const
{
	BigInt temp = *this;

	temp.sign = !temp.sign;

	return temp;
}

//BigInt BigInt::operator ++(int)
//{
//	BigInt old = *this;
//	*this = *this + 1;
//	return old;
//}
//
//BigInt BigInt::operator ++()
//{
//	*this = *this + 1;
//	return *this;
//}
//
//BigInt BigInt::operator --(int)
//{
//	BigInt old = *this;
//	*this = *this - 1;
//	return old;
//}
//
//BigInt BigInt::operator --()
//{
//	*this = *this - 1;
//	return *this;
//}
