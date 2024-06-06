#include <stdio.h>

/**
 * Stocke dans la chaine de caractere `s` le caractere `c`
 * repete `n` fois.
 *
 * @param c          Le caractere a repeter
 * @param n          Le nombre de repetitions du caractere
 * @param s          La chaine qui contient le resultat
 * @param maxLength  La longueur de la chaine, incluant le
 *                   caractere final '\0'
 */
void repeter(char c, int n, char *s, int maxLength) {
    int i;
    for (i = 0; i < n && i < maxLength - 1; ++i) {
        s[i] = c;
    }
    s[i] = '\0';
}

int main() {
    char s[10];
    repeter('*', 10, s, 10);
    printf("%s\n", s);
}
