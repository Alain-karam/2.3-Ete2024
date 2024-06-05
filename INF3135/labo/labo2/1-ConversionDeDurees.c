#include <stdio.h>

void afficher_duree(unsigned int num_secondes) {
    int heures, minutes, secondes;

    heures = num_secondes / 3600;
    num_secondes %= 3600;
    minutes = num_secondes / 60;
    secondes = num_secondes % 60;

    printf("la duree est de : %d:%d:%d\n",heures,minutes,secondes);
}

int main() {
    unsigned int num_secondes;

    printf("Entree la duree en secondes: ");
    scanf("%u", &num_secondes);

    afficher_duree(num_secondes);

    return 0;
}