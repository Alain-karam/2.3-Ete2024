#include <stdio.h>

int main() {

    int a[2][3] = {9,8,7,
                   6,5,4};

    printf("%d\n", *(*(a+0)+0)); // 9
    printf("%d\n", *(*(a+0)+1)); // 8
    printf("%d\n", *(*(a+0)+2)); // 7

    printf("%d\n", *(*(a+1)+0)); // 6
    printf("%d\n", *(*(a+1)+1)); // 5
    printf("%d\n", *(*(a+1)+2)); // 4


    return 0;
}


union bidon { 
    struct essence {
        float x;
        int y;
    };
    struct machin {
        float z;
        float t;
    };
    float u;
}