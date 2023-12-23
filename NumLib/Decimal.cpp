#include "Number.h"
#include "Decimal.h"
#include <iostream>

class Decimal {
public:
    Number integer;
    Number fractional;
    char sign;
    float value;

    void setSign() {
        if (value < 0) {
            sign = '-';
        }
        else if (value > 0) {
            sign = '+';
        }
        else {
            sign = '\0';
        }
    }

    void separate() {
        int temp = static_cast<int>(value);
        float n;
        integer = createNumber(temp);
        fractional = createNumber(modf(value, &n));
    }

    static Decimal createDecimal(Number integer, Number fractional) {
        Decimal decimal;
        decimal.sign = '\0';

        if (integer.sign == '\0') {
            decimal.sign = fractional.sign;
        }
        else {
            decimal.sign = integer.sign;
        }

        absNumber(integer);
        absNumber(fractional);

        decimal.integer = integer;
        decimal.fractional = fractional;

        decimal.value = integer.value + fractional.value / 10.0;

        return decimal;
    }

    static Decimal createDecimal(float value) {
        Decimal decimal;
        decimal.sign = '\0';
        decimal.value = value;

        if (value < 0) {
            decimal.sign = '-';
        }
        else if (value > 0) {
            decimal.sign = '+';
        }

        decimal.separate();

        return decimal;
    }

    void print() {
        std::cout << value << std::endl;
    }

    void add(Decimal sumDecimal) {
        value += sumDecimal.value;
        setSign();
        separate();
    }

    void add(Number number) {
        value += number.value;
        setSign();
        separate();
    }

    void multiply(Decimal factor) {
        value *= factor.value;
        setSign();
        separate();
    }

    void multiply(Number factor) {
        value *= factor.value;
        setSign();
        separate();
    }

    void divide(Decimal divider) {
        value /= divider.value;
        setSign();
        separate();
    }

    void divide(Number divider) {
        value /= divider.value;
        setSign();
        separate();
    }

    char getSign() {
        return sign;
    }

    void abs() {
        value = std::abs(value);
        absNumber(integer);
        absNumber(fractional);
        sign = '+';
    }

private:
    static Number createNumber(int value) {
        Number number;
        number.value = static_cast<float>(value);
        number.sign = (value < 0) ? '-' : '\0';
        return number;
    }

    static void absNumber(Number& number) {
        number.value = std::abs(number.value);
        number.sign = '\0';
    }
};
