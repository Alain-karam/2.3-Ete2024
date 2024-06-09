#include <stdio.h>
#include <stdlib.h>

struct pair {
    int x;
    int y;
};

int pgcd(int x, int y) {
    int denominateur = 0;
    
    if(x == 0) {
        return denominateur = y;
    } else
    if(y == 0) {
        return denominateur = x;
    } else
    if(x > y) {
        x -= y;
    } 
    
    for(int i=1 ; i<=x ; ++i) {
        if(x%i == 0 && y%i == 0) {
            denominateur = i;
        }
    }
    return denominateur;
}


int main(int argc, char **argv) {
    struct pair pair1;
    if(argc != 3) {
        printf("entrer la valeur de x : ");
        scanf("%d", &pair1.x);
        printf("entrer la valeur de y : ");
        scanf("%d", &pair1.y);
    } else {
        pair1.x = atoi(argv[1]);
        pair1.y = atoi(argv[2]);
        printf("la valeur de x : %d\nla valeur de y : %d\n", pair1.x, pair1.y);
    }

    int result = pgcd(pair1.x,pair1.y);
    printf("Le PGCD de %d et %d est %d\n", pair1.x, pair1.y, result);
    return 0;
}