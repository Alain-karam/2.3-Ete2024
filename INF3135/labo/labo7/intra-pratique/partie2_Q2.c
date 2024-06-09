#include <stdio.h>
#include <stdlib.h>

char *repeter1(char c, int n) {
    int i;
    char *s;
    for (i = 0; i < n; ++i) {
        s[i] = c;
    }
    return s;
}

char *repeter2(char c, int n) {
    int i;
    char *s = (char*)malloc(n * sizeof(char));
    for (i = 0; i < n; ++i) {
        s[i] = c;
    }
    return s;
}

void repeter3(char c, int n, char *s) {
    int i;
    for (i = 0; i < n; ++i) {
        s[i] = c;
    }
}

int main() {
    //printf("%s\n", repeter1('*', 10));
    printf("%s\n", repeter2('*', 10));
    char s[10];
    repeter3('*', 10, s);
    printf("%s\n", s);
}
