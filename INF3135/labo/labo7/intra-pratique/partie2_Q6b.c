#include <stdio.h>

union bidon {
    struct essence {
        float x;
        int y;
    }e;
    struct machin {
        float z;
        float t;
    }m;
    float u;
};

int main(void) {
    union bidon bid;
    bid.e.x = 5.21;
    bid.e.y = 2;
    bid.u = 2.21;

    printf("%.2f et %.2f et %.2f\n", bid.e.x, bid.m.z, bid.u);
    

    printf("Size of int = %zu bytes\n", sizeof(int));
    printf("Size of float = %zu bytes\n", sizeof(float));
    printf("Size of struct essence = (sizeof(x) + sizeof(y)) = (%zu + %zu) = %zu bytes\n", sizeof(int), sizeof(float), sizeof(struct essence));
    printf("Size of struct machin = (sizeof(z) + sizeof(t)) = (%zu + %zu) = %zu bytes\n", sizeof(int), sizeof(float), sizeof(struct machin));
    printf("Size of union bidon = (taille du plus grand membre : essence ou machine : %zu) = %zu bytes\n", sizeof(struct machin), sizeof(union bidon));

    return 0;
}