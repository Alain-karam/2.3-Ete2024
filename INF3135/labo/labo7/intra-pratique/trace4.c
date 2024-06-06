#include <stdio.h>

int x = 9;

int f(int x) {
    int y = 1;
    x += 4;
    x *= y;
    return x;
}

int main() {
    int x = 10;
    f(x);
    printf("%d\n", x);
    return 0;
}
