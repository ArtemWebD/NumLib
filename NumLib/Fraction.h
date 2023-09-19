#pragma once
#include "Number.h"

struct Fraction {
	Number numeric;
	Number denominator;
	float value;
	char sign;
};

Fraction createFraction(Number value);
Fraction createFraction(Number numeric, Number denominator);
void printFraction(Fraction fraction);
void addFraction(Fraction* fraction, Number number);
void addFraction(Fraction *fraction, Fraction sumFraction);
void multiplyFraction(Fraction* fraction, Fraction factor);
void multiplyFraction(Fraction *fraction, Number factor);
void divideFraction(Fraction* fraction, Fraction divider);
void divideFraction(Fraction *fraction, Number divider);
char getFractionSign(Fraction fraction);
void absFraction(Fraction* fraction);
