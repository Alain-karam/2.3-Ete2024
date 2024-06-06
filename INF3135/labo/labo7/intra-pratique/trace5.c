#include <stdio.h>

#define CUBE(x) x * x * x

int main() {
    int x = 2, y = 3, z;
    z = y - CUBE(x++);
    printf("%d\n", x + y + z);
    return 0;
}
