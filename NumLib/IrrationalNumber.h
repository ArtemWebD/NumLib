#pragma once
#include "Number.h"
#include "Decimal.h"

struct IrrationalNumber {
	float value;
	char sign;
};

IrrationalNumber createIrrationalNumber(float value);
void printIrrationalNumber(IrrationalNumber number);
void addIrrationalNumber(IrrationalNumber* number, IrrationalNumber sumNumber);
void addIrrationalNumber(IrrationalNumber* number, Decimal sumDecimal);
void addIrrationalNumber(IrrationalNumber* number, Number sumNumber);
void multiplyIrrationalNumber(IrrationalNumber* number, IrrationalNumber factor);
void multiplyIrrationalNumber(IrrationalNumber* number, Decimal factor);
void multiplyIrrationalNumber(IrrationalNumber* number, Number factor);
void divideIrrationalNumber(IrrationalNumber* number, IrrationalNumber divider);
void divideIrrationalNumber(IrrationalNumber* number, Decimal divider);
void divideIrrationalNumber(IrrationalNumber* number, Number divider);
char getIrrationalNumberSign(IrrationalNumber number);
void absIrrationalNumber(IrrationalNumber* number);
