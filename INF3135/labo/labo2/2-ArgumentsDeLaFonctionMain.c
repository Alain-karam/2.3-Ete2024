#include <stdio.h>
#include <string.h>

int main (int argc, char** argv){

    if (argc != 2){
        fprintf(stderr, "le programme prend exactement un argument\n");
        return 1;
    } else {
        int longueur = strlen(argv[1]);
        printf("\"%s\" est de longueur : %d \n", argv[1], longueur);
    }
    return 0;
}