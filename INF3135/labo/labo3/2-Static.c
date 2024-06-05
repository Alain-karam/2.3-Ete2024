#include <stdio.h>
#include <stdbool.h>

void aimer(unsigned int i) {
    switch (i) {
        case 0: printf("un peu\n");        break;
        case 1: printf("beaucoup\n");      break;
        case 2: printf("passionnément\n"); break;
        case 3: printf("à la folie\n");    break;
        case 4: printf("pas du tout\n");   break;
    }
}

/**
 * Affiche quatre phrases de façon cyclique.
 *
 * Les phrases affichées sont
 *
 * * un peu
 * * beaucoup
 * * passionnément
 * * à la folie
 * * pas du tout
 */
void aimer_cycle(void) {
    static unsigned int i;
    aimer(i);
    i = (i + 1) % 5;
}

/**
 * Affiche quatre phrases de façon palindromique.
 *
 * Les phrases affichées sont
 *
 * * un peu
 * * beaucoup
 * * passionnément
 * * à la folie
 * * pas du tout
 */
void aimer_palindrome(void) {
    static unsigned int i;
    static int d = 1;
    aimer(i);
    if (i == 4 && d == 1) {
        d = -1;
    } else if (i == 0 && d == -1) {
        d = 1;
    }
    i += d;
}

int main(void) {
    printf("Cycle:\n");
    for (unsigned int i = 0; i < 20; ++i) {
        printf("%.2d: ", i);
        aimer_cycle();
    }
    printf("Palindrome:\n");
    for (unsigned int i = 0; i < 20; ++i) {
        printf("%.2d: ", i);
        aimer_palindrome();
    }
    printf("\n");
    return 0;
}
