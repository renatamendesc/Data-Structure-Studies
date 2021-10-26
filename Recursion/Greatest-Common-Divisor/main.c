#include <stdio.h>

int greatestCommonDivisor (int a, int b) {

    if (b < 0) b = -b;

    if (b > 0) return greatestCommonDivisor(b, a % b);

    return a;
}

int main (void) {

    int a, b;

    printf("Type two integer numbers:\n\n");

    printf("a: ");
    scanf("%d", &a);

    printf("b: ");
    scanf("%d", &b);

    printf("\nGreatest Common Divisor of %d and %d: %d\n", a, b, greatestCommonDivisor(a, b));

    return 0;
}
