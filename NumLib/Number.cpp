#include "Number.h"
#include <iostream>

Number::Number(int val)
{
	value = val;

	setSign();
}

void Number::printNumber()
{
	std::cout << value << std::endl;
}

void Number::addNumber(Number sumNumber)
{
	value += sumNumber.value;
	setSign();
}

void Number::multiplyNumber(Number factor)
{
	value *= factor.value;
	setSign();
}

void Number::divideNumber(Number divider)
{
	value /= divider.value;
	setSign();
}

char Number::getSign()
{
	return sign;
}

void Number::absNumber()
{
	value = abs(value);
	setSign();
}
