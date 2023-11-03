#include <iostream>
#include <windows.h>
#include "Number.h"
#include "Fraction.h"
#include "Decimal.h"
#include "IrrationalNumber.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "RUS");

    cout << "Статические переменные\n";
    cout << "--------------------------------------\n\n";

    cout << "Struct Number" << endl;

    Number numberStatic = createNumber(1);

    cout << "printNumber(): ";

    printNumber(numberStatic);

    cout << "addNumber(3): ";

    Number sumNumber = createNumber(3);

    addNumber(&numberStatic, sumNumber);
    printNumber(numberStatic);

    cout << "multiplyNumber(2): ";

    Number factor = createNumber(2);

    multiplyNumber(&numberStatic, factor);
    printNumber(numberStatic);

    cout << "divideNumber(4): ";

    Number divider = createNumber(4);

    divideNumber(&numberStatic, divider);
    printNumber(numberStatic);

    cout << "getSign(): ";

    char sign = getSign(numberStatic);
    cout << sign << endl;

    cout << "\n\nStruct Fraction" << endl;

    Number a = createNumber(2), b = createNumber(-3);
    Fraction fractionStatic = createFraction(a, b);

    cout << "printFraction(): ";

    printFraction(fractionStatic);

    cout << "addFraction(3/2): ";

    a = createNumber(3);
    b = createNumber(2);
    Fraction sumFraction = createFraction(a, b);

    addFraction(&fractionStatic, sumFraction);
    printFraction(fractionStatic);

    cout << "multiplyFraction(3/2): ";

    multiplyFraction(&fractionStatic, sumFraction);
    printFraction(fractionStatic);

    cout << "divideFraction(3/2): ";

    divideFraction(&fractionStatic, sumFraction);
    printFraction(fractionStatic);

    cout << "addFraction(2): ";

    addFraction(&fractionStatic, createNumber(2));
    printFraction(fractionStatic);

    cout << "multiplyFraction(2): ";

    multiplyFraction(&fractionStatic, createNumber(2));
    printFraction(fractionStatic);

    cout << "divideFraction(2): ";

    divideFraction(&fractionStatic, createNumber(2));
    printFraction(fractionStatic);

    cout << "\n\nStruct Decimal" << endl;

    cout << "printFraction(): ";

    Decimal decimal = createDecimal(1.1);

    printDecimal(decimal);

    cout << "addDecimal(-0.2): ";

    addDecimal(&decimal, createDecimal(-0.2));
    printDecimal(decimal);

    cout << "addDecimal(1): ";

    addDecimal(&decimal, createNumber(1));
    printDecimal(decimal);

    cout << "multiplyDecimal(0.5): ";

    multiplyDecimal(&decimal, createDecimal(0.5));
    printDecimal(decimal);

    cout << "multiplyDecimal(2): ";

    multiplyDecimal(&decimal, createNumber(2));
    printDecimal(decimal);

    cout << "divideDecimal(0.5): ";

    divideDecimal(&decimal, createDecimal(0.5));
    printDecimal(decimal);

    cout << "divideDecimal(2): ";

    divideDecimal(&decimal, createNumber(2));
    printDecimal(decimal);

    cout << "\n\nStruct IrrationalNumber" << endl;

    cout << "printIrrationalNumber(): ";

    IrrationalNumber iNumber = createIrrationalNumber(1.235234245);

    printIrrationalNumber(iNumber);

    cout << "addIrrationalNumber(0,7856456): ";

    IrrationalNumber iSumNumber = createIrrationalNumber(0.7856456);

    addIrrationalNumber(&iNumber, iSumNumber);
    printIrrationalNumber(iNumber);

    cout << "multiplyIrrationalNumber(0,7856456): ";

    IrrationalNumber iFactor = createIrrationalNumber(0.7856456);

    multiplyIrrationalNumber(&iNumber, iFactor);
    printIrrationalNumber(iNumber);

    cout << "divideIrrationalNumber(0,7856456): ";

    IrrationalNumber iDivider = createIrrationalNumber(0.7856456);

    divideIrrationalNumber(&iNumber, iDivider);
    printIrrationalNumber(iNumber);
}
