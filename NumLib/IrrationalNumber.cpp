#include "IrrationalNumber.h"
#include "Decimal.h"
#include "Fraction.h"
#include <iostream>
#include <string>

class IrrationalNumber {
public:
    float value;
    char sign;

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

    static IrrationalNumber createIrrationalNumber(float value) {
        IrrationalNumber irrationalNumber;
        irrationalNumber.value = value;
        irrationalNumber.setSign();
        return irrationalNumber;
    }

    void print() const {
        std::cout << value << "..." << std::endl;
    }

    void add(const IrrationalNumber& sumNumber) {
        value += sumNumber.value;
        setSign();
    }

    void add(const Number& sumNumber) {
        value += sumNumber.value;
        setSign();
    }

    void add(float sumValue) {
        value += sumValue;
        setSign();
    }

    void multiply(const IrrationalNumber& factor) {
        value *= factor.value;
        setSign();
    }

    void multiply(const Number& factor) {
        value *= factor.value;
        setSign();
    }

    void multiply(float factor) {
        value *= factor;
        setSign();
    }

    void divide(const IrrationalNumber& divider) {
        value /= divider.value;
        setSign();
    }

    void divide(const Number& divider) {
        value /= divider.value;
        setSign();
    }

    void divide(float divider) {
        value /= divider;
        setSign();
    }

    char getSign() const {
        return sign;
    }

    void abs() {
        value = std::abs(value);
        sign = '+';
    }
};
