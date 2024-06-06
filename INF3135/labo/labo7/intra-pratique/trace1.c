#include <stdio.h>

int main() {
    int a[2][3] = {9,8,7,6,5,4};
    printf("%d\n", *(*(a+1)+1));
    return 0;
}
