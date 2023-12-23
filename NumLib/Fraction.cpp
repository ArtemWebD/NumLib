#include "Number.h"
#include "Fraction.h"
#include <iostream>

class Fraction {
public:
    Number numeric;
    Number denominator;
    char sign;
    double value;

    void setSign() {
        if (value > 0) {
            sign = '+';
        }
        else if (value < 0) {
            sign = '-';
        }
        else {
            sign = '\0';
        }
    }

    int getDivider(int a, int b) {
        if (b == 0) {
            return a;
        }
        return getDivider(b, a % b);
    }

    int getMax() {
        if (value < 1) {
            return denominator.value;
        }
        return numeric.value;
    }

    int getMin() {
        if (value < 1) {
            return numeric.value;
        }
        return denominator.value;
    }

    void reduce() {
        int maxDivider = getDivider(getMax(), getMin());
        numeric.value /= maxDivider;
        denominator.value /= maxDivider;
    }

    static Fraction createFraction(Number numeric, Number denominator) {
        Fraction fraction;
        fraction.value = numeric.value * 1.0 / denominator.value;
        fraction.numeric = numeric;
        fraction.denominator = denominator;
        fraction.setSign();
        return fraction;
    }

    static Fraction createFraction(Number value) {
        return createFraction(value, value);
    }

    void print() {
        char sign;
        if (this->sign == '-') {
            sign = '-';
        }
        else {
            sign = '\0';
        }
        std::cout << sign << std::abs(numeric.value) << "/" << std::abs(denominator.value) << std::endl;
    }

    void add(Number number) {
        Fraction temp = createFraction(number, { 1, '\0' });
        add(temp);
    }

    void add(Fraction sumFraction) {
        Fraction temp = sumFraction;
        multiplyNumber(numeric, temp.denominator);
        multiplyNumber(temp.numeric, denominator);
        multiplyNumber(denominator, temp.denominator);

        if (sign == '-') {
            numeric.sign = sign;
            numeric.value *= -1;
        }

        if (temp.sign == '-') {
            temp.numeric.sign = sumFraction.sign;
            temp.numeric.value *= -1;
        }

        addNumber(numeric, temp.numeric);

        reduce();

        value = numeric.value * 1.0 / denominator.value;
        absNumber(numeric);
        setSign();
    }

    void multiply(Fraction factor) {
        multiplyNumber(numeric, factor.numeric);
        multiplyNumber(denominator, factor.denominator);
        reduce();
        value *= factor.value;
        setSign();
    }

    void multiply(Number factor) {
        Fraction temp = createFraction(factor, { 1, '\0' });
        multiply(temp);
    }

    void divide(Fraction divider) {
        Number temp = divider.numeric;
        divider.numeric = divider.denominator;
        divider.denominator = temp;
        multiply(divider);
    }

    void divide(Number divider) {
        Fraction temp = createFraction(divider, { 1, '\0' });
        divide(temp);
    }

    char getSign() {
        return sign;
    }

    void abs() {
        value = std::abs(value);
        absNumber(numeric);
        absNumber(denominator);
        setSign();
    }

private:
    void absNumber(Number& number) {
        number.value = std::abs(number.value);
        number.sign = '\0';
    }

    void addNumber(Number& a, const Number& b) {
        if (a.sign == '\0' && b.sign == '\0') {
            a.value += b.value;
        }
        else if (a.sign == '\0' && b.sign == '-') {
            if (a.value >= b.value) {
                a.value -= b.value;
            }
            else {
                a.value = b.value - a.value;
                a.sign = '-';
            }
        }
        else if (a.sign == '-' && b.sign == '\0') {
            if (a.value >= b.value) {
                a.value -= b.value;
            }
            else {
                a.value = b.value - a.value;
                a.sign = '\0';
            }
        }
        else if (a.sign == '-' && b.sign == '-') {
            a.value += b.value;
            a.sign = '-';
        }
    }

    void multiplyNumber(Number& a, const Number& b) {
        a.value *= b.value;
        if (a.sign != b.sign) {
            a.sign = '-';
        }
        else {
            a.sign = '\0';
        }
    }
};
