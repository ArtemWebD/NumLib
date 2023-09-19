#include "Number.h"
#include <iostream>

void setSign(Number *number)
{
	if (number->value > 0)
	{
		number->sign = '+';
	}
	else if (number->value < 0)
	{
		number->sign = '-';
	}
	else
	{
		number->sign = '\0';
	}
}

Number createNumber(int value)
{
	Number number;

	number.value = value;

	setSign(&number);

	return number;
}

void printNumber(Number number)
{
	std::cout << number.value << std::endl;
}

void addNumber(Number *number, Number sumNumber)
{
	number->value += sumNumber.value;
	setSign(number);
}

void multiplyNumber(Number* number, Number factor)
{
	number->value *= factor.value;
	setSign(number);
}

void divideNumber(Number* number, Number divider)
{
	number->value /= divider.value;
	setSign(number);
}

char getSign(Number number)
{
	return number.sign;
}

void absNumber(Number *number)
{
	number->value = abs(number->value);
	setSign(number);
}
