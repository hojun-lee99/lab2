#include <stdio.h>
#include "testlib.h"

int main()
{
    double num1 = 10;
    double num2 = 3;

    printf("%lf + %lf = %lf\n", num1, num2, add(num1, num2));
    printf("%lf - %lf = %lf\n", num1, num2, sub(num1, num2));
    printf("%lf * %lf = %lf\n", num1, num2, mult(num1, num2));
    printf("%lf / %lf = %lf\n", num1, num2, dvid(num1, num2));

}