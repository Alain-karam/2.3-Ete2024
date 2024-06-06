#include <stdio.h>

int main() {
    char s[10] = "+--+--+++";
    int i;

    for (i = 0; i < 7; ++i) {
        if (s[i] != s[i+1]) {
            s[i+2] = s[i];
        }
    }
    printf("%s\n", s);
    return 0;
}
