#include <stdio.h>

int main() {

    int a = 44;
    int b = 66;
    int *pa, *pb;

    pa = &a;
    pb = &b;

    printf("a = %d et b = %d\n", a, b);
    printf("*pa = %d et *pb = %d\n", *pa, *pb);
    printf("pa = %p et pb = %p\n", pa, pb);
    printf("---------------------------\n");
    *pa = *pb;
    printf("*pa = *pb;\n");
    printf("---------------------------\n");
    printf("a = %d et b = %d\n", a, b);
    printf("*pa = %d et *pb = %d\n", *pa, *pb);
    printf("pa = %p et pb = %p\n", pa, pb);
}