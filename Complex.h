//
// Created by egbor on 2023-09-07.
//

#ifndef COMPLEXNUMBERCALCUATOR_COMPLEX_H
#define COMPLEXNUMBERCALCUATOR_COMPLEX_H


#include <stdbool.h>

typedef enum Operator {
    ADD, SUB
} Operator;

typedef struct Complex {
    int real;
    Operator operator;
    int imaginary;
    char term;
    bool isSquared;
} Complex;

// Addition
Complex addComplex(Complex complex, Complex complex1);

// Product
Complex productImaginary(const Complex *imaginary, const Complex *complex1);
Complex productReal(int real, const Complex *complex);
Complex productComplex(const Complex *a, const Complex *b);

// Utilities
Complex createComplexNum(const char input[]);
void toString(Complex complex);


#endif //COMPLEXNUMBERCALCUATOR_COMPLEX_H
