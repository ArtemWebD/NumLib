#pragma once
#include "Number.h"
#include "Decimal.h"
#include "Fraction.h"
#include "IrrationalNumber.h"

struct Variable {
	int value;
	char sign;
};

Variable createVariable();
void setVariable(Variable *variable, Number number);
void setVariable(Variable* variable, Decimal number);
void setVariable(Variable* variable, Fraction number);
void setVariable(Variable* variable, IrrationalNumber number);
char getSign(Variable number);
void absVariable(Variable* number);