#pragma once

class Number {
public:
    int value;
    char sign;

    Number(int value);

    void printNumber();

    static Number createNumber(int value);

    void addNumber(Number sumNumber);

    void multiplyNumber(Number factor);

    void divideNumber(Number divider);

    char getSign();

    void absNumber();
private:
    void setSign()
    {
        if (value > 0)
        {
            sign = '+';
        }
        else if (value < 0)
        {
            sign = '-';
        }
        else
        {
            sign = '\0';
        }
    }
};
