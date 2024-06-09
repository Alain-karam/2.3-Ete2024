#include <stdio.h>

int x = 9;

int f(int x) {
    int y = 1;
    x += 4;
    x *= y;

    return x;
}

int main(void) {
    int x = 10;
    f(x);

    x = 10;
    int result = f(x);

    printf("x = %d\n", x);
    printf("f(x) = %d\n", result);
    return 0;
}