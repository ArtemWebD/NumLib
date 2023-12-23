#include "Variable.h"
#include "Number.h"
#include "Decimal.h"
#include "Fraction.h"
#include "IrrationalNumber.h"
#include <math.h>

class Variable {
public:
    float value;
    char sign;

    Variable() : value(0), sign('\0') {}

    void setVariable(const Number& number) {
        value = number.value;
        sign = number.sign;
    }

    void setVariable(const Decimal& number) {
        value = number.value;
        sign = number.sign;
    }

    void setVariable(const Fraction& number) {
        value = number.value;
        sign = number.sign;
    }

    void setVariable(const IrrationalNumber& number) {
        value = number.value;
        sign = number.sign;
    }

    char getSign() const {
        return sign;
    }

    void absVariable() {
        sign = '+';
        value = std::abs(value);
    }
};
