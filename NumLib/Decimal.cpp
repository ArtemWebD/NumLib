#include "Number.h"
#include "Decimal.h"
#include <iostream>

void setSign(Decimal* decimal)
{
	if (decimal->value < 0)
	{
		decimal->sign = '-';
	}
	else if (decimal->value > 0)
	{
		decimal->sign = '+';
	}
	else
	{
		decimal->sign = '\0';
	}
}

void separateDecimal(Decimal* decimal)
{
	int temp = decimal->value;
	float n;

	decimal->integer = createNumber(temp);
	decimal->fractional = createNumber(modf(decimal->value, &n));
}

Decimal createDecimal(Number integer, Number fractional)
{
	Decimal decimal;

	decimal.sign = '\0';

	if (integer.sign == '\0')
	{
		decimal.sign = fractional.sign;
	}
	else
	{
		decimal.sign = integer.sign;
	}

	absNumber(&integer);
	absNumber(&fractional);

	decimal.integer = integer;
	decimal.fractional = fractional;

	decimal.value = integer.value + fractional.value / 10.0;

	return decimal;
}

Decimal createDecimal(float value)
{
	Decimal decimal;

	decimal.sign = '\0';
	decimal.value = value;

	if (value < 0)
	{
		decimal.sign = '-';
	}
	else if (value > 0)
	{
		decimal.sign = '+';
	}

	separateDecimal(&decimal);

	return decimal;
}

void printDecimal(Decimal decimal)
{
	std::cout << decimal.value << std::endl;
}

void addDecimal(Decimal* decimal, Decimal sumDecimal)
{
	decimal->value += sumDecimal.value;
	setSign(decimal);
	separateDecimal(decimal);
}

void addDecimal(Decimal* decimal, Number number)
{
	decimal->value += number.value;
	setSign(decimal);
	separateDecimal(decimal);
}

void multiplyDecimal(Decimal* decimal, Decimal factor)
{
	decimal->value *= factor.value;
	setSign(decimal);
	separateDecimal(decimal);
}

void multiplyDecimal(Decimal* decimal, Number factor)
{
	decimal->value *= factor.value;
	setSign(decimal);
	separateDecimal(decimal);
}

void divideDecimal(Decimal* decimal, Decimal divider)
{
	decimal->value /= divider.value;
	setSign(decimal);
	separateDecimal(decimal);
}

void divideDecimal(Decimal* decimal, Number divider)
{
	decimal->value /= divider.value;
	setSign(decimal);
	separateDecimal(decimal);
}

char getDecimalSign(Decimal decimal)
{
	return decimal.sign;
}

void absDecimal(Decimal* decimal)
{
	decimal->value = abs(decimal->value);
	absNumber(&decimal->integer);
	absNumber(&decimal->fractional);
	decimal->sign = '+';
}
