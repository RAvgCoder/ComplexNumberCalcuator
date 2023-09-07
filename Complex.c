//
// Created by egbor on 2023-09-07.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "Complex.h"

// --------------- Addition -----------------//

Complex addComplex(Complex complex, Complex complex1) {
    int addReal =
            ((!complex.isSquared) ? complex.real : (-1 * complex.imaginary) * ((complex.operator == SUB) ? -1 : 1)) +
            ((!complex1.isSquared) ? complex1.real : (-1 * complex1.imaginary) * ((complex1.operator == SUB) ? -1 : 1));

    int addImaginary = ((complex.isSquared) ? complex.real : complex.imaginary) +
                       ((complex1.isSquared) ? complex1.real : complex1.imaginary);

    Complex val = {
            .real = addReal,
            .operator = (addImaginary < 0) ? SUB : ADD,
            .imaginary = abs(addImaginary),
            .term =complex1.term,
            .isSquared = false
    };

    return val;
}

// ------------- END ADD --------------- //


// --------------- Product --------------------- //

Complex productImaginary(const Complex *imaginary, const Complex *complex1) {
    if (imaginary->term != complex1->term) {
        printf("Term %c doesn't match with %c", imaginary->term, complex1->term);
        exit(404);
    }

    int multi = (imaginary->imaginary * ((imaginary->operator == ADD) ? 1 : -1))
                * (complex1->imaginary * ((complex1->operator == ADD) ? 1 : -1));

    Complex val = {
            .real = complex1->real * (imaginary->imaginary * ((imaginary->operator == ADD) ? 1 : -1)),
            .operator = (multi < 0) ? SUB : ADD,
            .imaginary = abs(multi),
            .term = imaginary->term,
            .isSquared = true
    };
    return val;
}

Complex productReal(const int real, const Complex *complex) {
    Complex val = {
            .real = abs(real * complex->real),
            .operator = ((real * complex->imaginary) < 0) ? SUB : ADD,
            .imaginary = abs(real * complex->imaginary),
            .term = complex->term,
            .isSquared = complex->isSquared
    };
    return val;
}

Complex productComplex(const Complex *a, const Complex *b) {
    Complex productImaginary1 = productReal(a->real, b);
    Complex productImaginary2 = productImaginary(a, b);
    return addComplex(productImaginary1, productImaginary2);
}

// ---------------- END Product ---------------- //


// ------------- Utilities ------------ //

Complex createComplexNum(const char input[]) {
    Complex complex = {0, ADD, 0, 'i', false};
    bool onReal = true;
    char *buffer = malloc(sizeof(short));
    bool nextIsDigit = true;
    int bufferSize = 0;
    for (int i = 0; i < strlen(input); ++i) {
        char curr_char = input[i];
        if (isspace(curr_char)) continue;


        if (!nextIsDigit && i != 0) {
            if (onReal)
                complex.real = atoi(buffer);
            else
                complex.imaginary = atoi(buffer);
            onReal = !onReal;
            nextIsDigit = true;
            free(buffer);
            buffer = malloc(sizeof(short));
        }
        if (isdigit(curr_char)) {
            buffer[bufferSize++] = curr_char;
            nextIsDigit = isdigit(input[i + 1]);
            continue;
        }

        bufferSize = 0;

        if (curr_char == '+' || curr_char == '-') {
            complex.operator = (curr_char == '+') ? ADD : SUB;
        } else {
            complex.term = curr_char;
            break;
        }
    }
    free(buffer);
    return complex;
}

void toString(const Complex complex) {
    char operator;
    char squared[(complex.isSquared) ? 2 : 1];
    strcpy(squared, (complex.isSquared) ? "^2" : "");
    char real[(complex.isSquared) ? 2 : 1];
    sprintf(real, "%d%s", complex.real, ((complex.isSquared) ? "i" : ""));
    switch (complex.operator) {
        case ADD:
            operator = '+';
            break;
        case SUB:
            operator = '-';
            break;
    }
    printf("%s %c %d%c%s\n", real, operator, complex.imaginary, complex.term, squared);
}

// ----------- END Utilities ---------- //