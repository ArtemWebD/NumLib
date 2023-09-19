#pragma once
#include "Number.h"

struct Decimal {
	Number integer;
	Number fractional;
	float value;
	char sign;
};

Decimal createDecimal(float value);
Decimal createDecimal(Number integer, Number fractional);
void printDecimal(Decimal decimal);
void addDecimal(Decimal* decimal, Decimal sumDecimal);
void addDecimal(Decimal* decimal, Number number);
void multiplyDecimal(Decimal* decimal, Decimal factor);
void multiplyDecimal(Decimal* decimal, Number factor);
void divideDecimal(Decimal* decimal, Decimal divider);
void divideDecimal(Decimal* decimal, Number divider);
char getDecimalSign(Decimal decimal);
void absDecimal(Decimal* decimal);
