#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

int get_year(char s[]);
bool is_valid_year(char s[]);

int get_year(char s[]) {
    if (!is_valid_year(s)) {
        return -1;
    }

    char year[5];
    strncpy(year, s, 4);
    year[4] = '\0';

    return atoi(year);
}

bool is_valid_year(char s[]) {
    for (int i = 0; i < 4; i++) {
        if (!isdigit(s[i])) {
            return false;
        }
    }
    return true;
}

int main(void) {
    char *date = "2023-03-06";
    printf("Result : %d\n", get_year(date));

    return 0;
}
