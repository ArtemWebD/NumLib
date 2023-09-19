#include "Number.h"
#include "Fraction.h"
#include <iostream>

void setSign(Fraction* number)
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

int getDivider(int a, int b)
{
	if (b == 0)
	{
		return a;
	}

	return getDivider(b, a % b);
}

int getMax(Fraction fraction)
{
	if (fraction.value < 1)
	{
		return fraction.denominator.value;
	}

	return fraction.numeric.value;
}

int getMin(Fraction fraction)
{
	if (fraction.value < 1)
	{
		return fraction.numeric.value;
	}

	return fraction.denominator.value;
}

void reduceFraction(Fraction* fraction)
{
	int maxDivider = getDivider(getMax(*fraction), getMin(*fraction));

	fraction->numeric.value /= maxDivider;
	fraction->denominator.value /= maxDivider;
}

Fraction createFraction(Number numeric, Number denominator)
{
	Fraction fraction;

	fraction.value = numeric.value * 1.0 / denominator.value;

	absNumber(&numeric);
	absNumber(&denominator);

	fraction.numeric = numeric;
	fraction.denominator = denominator;

	setSign(&fraction);

	return fraction;
}

Fraction createFraction(Number value)
{
	return createFraction(value, value);
}

void printFraction(Fraction fraction)
{
	char sign;

	if (fraction.sign == '-')
	{
		sign = '-';
	}
	else
	{
		sign = '\0';
	}

	std::cout << sign << abs(fraction.numeric.value) << "/" << abs(fraction.denominator.value) << std::endl;
}

void addFraction(Fraction* fraction, Number number)
{
	Fraction temp = createFraction(number, createNumber(1));
	addFraction(fraction, temp);
}

void addFraction(Fraction *fraction, Fraction sumFraction)
{
	Fraction temp = sumFraction;

	multiplyNumber(&fraction->numeric, temp.denominator);
	multiplyNumber(&temp.numeric, fraction->denominator);
	
	multiplyNumber(&fraction->denominator, temp.denominator);

	if (fraction->sign == '-')
	{
		fraction->numeric.sign = fraction->sign;
		fraction->numeric.value *= -1;
	}

	if (temp.sign == '-')
	{
		temp.numeric.sign = sumFraction.sign;
		temp.numeric.value *= -1;
	}

	addNumber(&fraction->numeric, temp.numeric);

	reduceFraction(fraction);
	
	fraction->value = fraction->numeric.value * 1.0 / fraction->denominator.value;
	absNumber(&fraction->numeric);
	setSign(fraction);
}

void multiplyFraction(Fraction *fraction, Fraction factor)
{
	multiplyNumber(&fraction->numeric, factor.numeric);
	multiplyNumber(&fraction->denominator, factor.denominator);

	reduceFraction(fraction);

	fraction->value *= factor.value;
	setSign(fraction);
}

void multiplyFraction(Fraction* fraction, Number factor)
{
	Fraction temp = createFraction(factor, createNumber(1));
	multiplyFraction(fraction, temp);
}

void divideFraction(Fraction* fraction, Fraction divider)
{
	Number temp = divider.numeric;
	divider.numeric = divider.denominator;
	divider.denominator = temp;

	multiplyFraction(fraction, divider);
}

void divideFraction(Fraction* fraction, Number divider)
{
	Fraction temp = createFraction(divider, createNumber(1));
	divideFraction(fraction, temp);
}

char getFractionSign(Fraction fraction)
{
	return fraction.sign;
}

void absFraction(Fraction* fraction)
{
	fraction->value = abs(fraction->value);
	absNumber(&fraction->numeric);
	absNumber(&fraction->denominator);
	setSign(fraction);
}
