#include <stdio.h>
#include <stdlib.h>

int mystere(int x) {
    int i = 0;

    while (x != 0) {
        printf("x = %d et i = %d\n", x, i);
        x &= x + (x & -x);
        i++;
    }
    printf("x = %d et i = %d\n", x, i);
    return i;
}

int main(int argc, char** argv) {
    int cle;
    if(argc == 1) {
        printf("entree la cle: ");
        scanf("%d", &cle);
    } else {
        cle = atoi(argv[1]);
    }
    int resultat = mystere(cle);
    printf("resultat = %d\n", resultat);

    return 0;
}
