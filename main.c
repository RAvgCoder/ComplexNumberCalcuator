#include "Complex.h"
#include <stdio.h>

int main() {

    Complex first;
    Complex second;
    char input[10];
    printf("Input your first complex number: ");
    gets(input);
    first = createComplexNum(input);

    printf("Input you second complex number: ");
    gets(input);
    second = createComplexNum(input);

    printf("-------------------\n");
    toString(first);
    toString(second);
    printf("-------------------\n");

    toString(productReal(first.real,&second));
    toString(productImaginary(&first,&second));
    printf("-------------------\n");
    toString(productComplex(&first,&second));

}
