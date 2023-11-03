#include "IrrationalNumber.h"
#include "Decimal.h"
#include "Fraction.h"
#include <iostream>
#include <string>

void setSign(IrrationalNumber* number)
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

IrrationalNumber createIrrationalNumber(float value)
{
	IrrationalNumber decimal;

	decimal.value = value;
	setSign(&decimal);

	return decimal;
}

void printIrrationalNumber(IrrationalNumber number)
{
	std::cout << number.value << "..." << std::endl;
}

void addIrrationalNumber(IrrationalNumber* number, IrrationalNumber sumNumber)
{
	number->value += sumNumber.value;
	setSign(number);
}

void addIrrationalNumber(IrrationalNumber* number, Decimal sumDecimal)
{
	number->value += sumDecimal.value;
	setSign(number);
}

void addIrrationalNumber(IrrationalNumber* number, Number sumNumber)
{
	number->value += sumNumber.value;
	setSign(number);
}

void multiplyIrrationalNumber(IrrationalNumber* number, IrrationalNumber factor)
{
	number->value *= factor.value;
	setSign(number);
}

void multiplyIrrationalNumber(IrrationalNumber* number, Decimal factor)
{
	number->value *= factor.value;
	setSign(number);
}

void multiplyIrrationalNumber(IrrationalNumber* number, Number factor)
{
	number->value *= factor.value;
	setSign(number);
}

void divideIrrationalNumber(IrrationalNumber* number, IrrationalNumber divider)
{
	number->value /= divider.value;
	setSign(number);
}

void divideIrrationalNumber(IrrationalNumber* number, Decimal divider)
{
	number->value /= divider.value;
	setSign(number);
}

void divideIrrationalNumber(IrrationalNumber* number, Number divider)
{
	number->value /= divider.value;
	setSign(number);
}

char getIrrationalNumberSign(IrrationalNumber number)
{
	return number.sign;
}

void absIrrationalNumber(IrrationalNumber* number)
{
	number->value = abs(number->value);
	number->sign = '+';
}
