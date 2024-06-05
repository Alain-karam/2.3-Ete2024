#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Conjonction
enum conj {
    AUC, // Aucune conjonction
    ET,  // et
    TU   // Trait d'union
};

// Function declarations
void afficher_unite(unsigned int u);
void afficher_dizaine(unsigned int d);
void afficher_10_a_19(unsigned int n);
void afficher_conjonction(enum conj c);
void afficher_0_a_69(unsigned int n);
void afficher_70_a_79(unsigned int n);
void afficher_80_a_89(unsigned int n);
void afficher_90_a_99(unsigned int n);
void afficher_centaines(unsigned int n);
void afficher_milliers(unsigned int n);
void afficher_nombre(unsigned int n);

int main(int argc, char **argv) {
    unsigned int max = 999999;
    if (argc == 2) {
        max = atoi(argv[1]);
    }
    for (unsigned int i = 0; i <= max; ++i) {
        afficher_nombre(i);
        printf("\n");
    }
    return 0;
}

// Function definitions

void afficher_unite(unsigned int u) {
    const char* unites[] = {"zéro", "un", "deux", "trois", "quatre", "cinq", "six", "sept", "huit", "neuf"};
    printf("%s", unites[u]);
}

void afficher_dizaine(unsigned int d) {
    const char* dizaines[] = {"", "dix", "vingt", "trente", "quarante", "cinquante", "soixante"};
    printf("%s", dizaines[d]);
}

void afficher_10_a_19(unsigned int n) {
    const char* entre_10_et_19[] = {"dix", "onze", "douze", "treize", "quatorze", "quinze", "seize", "dix-sept", "dix-huit", "dix-neuf"};
    printf("%s", entre_10_et_19[n - 10]);
}

void afficher_conjonction(enum conj c) {
    if (c == ET) {
        printf(" et ");
    } else if (c == TU) {
        printf("-");
    }
}

void afficher_0_a_69(unsigned int n) {
    if (n < 10) {
        afficher_unite(n);
    } else if (n < 20) {
        afficher_10_a_19(n);
    } else {
        unsigned int dizaines = n / 10;
        unsigned int unites = n % 10;
        afficher_dizaine(dizaines);
        if (unites == 1 && dizaines > 1) {
            afficher_conjonction(ET);
        } else if (unites > 0) {
            afficher_conjonction(TU);
        }
        if (unites > 0 || (unites == 0 && dizaines == 1)) {
            afficher_unite(unites);
        }
    }
}

void afficher_70_a_79(unsigned int n) {
    unsigned int unites = n - 70;
    afficher_dizaine(6); // soixante
    if (unites == 1) {
        afficher_conjonction(ET);
    } else {
        afficher_conjonction(TU);
    }
    afficher_10_a_19(unites + 10);
}

void afficher_80_a_89(unsigned int n) {
    unsigned int unites = n - 80;
    if (unites == 0) {
        printf("quatre-vingts");
    } else {
        printf("quatre-vingt-");
        afficher_unite(unites);
    }
}

void afficher_90_a_99(unsigned int n) {
    unsigned int unites = n - 90;
    printf("quatre-vingt-");
    afficher_10_a_19(unites + 10);
}

void afficher_centaines(unsigned int n) {
    unsigned int centaines = n / 100;
    unsigned int reste = n % 100;
    if (centaines > 1) {
        afficher_unite(centaines);
        printf(" cent");
        if (reste > 0) {
            printf(" ");
        }
    } else if (centaines == 1) {
        printf("cent");
        if (reste > 0) {
            printf(" ");
        }
    }
    if (reste > 0) {
        if (reste < 70) {
            afficher_0_a_69(reste);
        } else if (reste < 80) {
            afficher_70_a_79(reste);
        } else if (reste < 90) {
            afficher_80_a_89(reste);
        } else {
            afficher_90_a_99(reste);
        }
    }
}

void afficher_milliers(unsigned int n) {
    unsigned int milliers = n / 1000;
    unsigned int reste = n % 1000;
    if (milliers > 1) {
        afficher_centaines(milliers);
        printf(" mille");
        if (reste > 0) {
            printf(" ");
        }
    } else if (milliers == 1) {
        printf("mille");
        if (reste > 0) {
            printf(" ");
        }
    }
    if (reste > 0) {
        afficher_centaines(reste);
    }
}

void afficher_nombre(unsigned int n) {
    if (n < 1000) {
        afficher_centaines(n);
    } else {
        afficher_milliers(n);
    }
}
