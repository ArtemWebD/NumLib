#include "Variable.h"
#include "Number.h"
#include "Decimal.h"
#include "Fraction.h"
#include "IrrationalNumber.h"
#include <math.h>

Variable createVariable()
{
	Variable variable;
	return variable;
}

void setVariable(Variable* variable, Number number)
{
	variable->value = number.value;
	variable->sign = number.sign;
}

void setVariable(Variable* variable, Decimal number)
{
	variable->value = number.value;
	variable->sign = number.sign;
}

void setVariable(Variable* variable, Fraction number)
{
	variable->value = number.value;
	variable->sign = number.sign;
}

void setVariable(Variable* variable, IrrationalNumber number)
{
	variable->value = number.value;
	variable->sign = number.sign;
}

char getSign(Variable number)
{
	return number.sign;
}

void absVariable(Variable* number)
{
	number->sign = '+';
	number->value = abs(number->value);
}
