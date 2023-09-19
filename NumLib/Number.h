#pragma once

struct Number {
	int value;
	char sign;
};

Number createNumber(int value);
void printNumber(Number number);
void addNumber(Number *number, Number sumNumber);
void multiplyNumber(Number* number, Number factor);
void divideNumber(Number* number, Number divider);
char getSign(Number number);
void absNumber(Number *number);
