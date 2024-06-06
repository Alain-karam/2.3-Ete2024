#include <stdio.h>
#include <stdlib.h>

// Fonction pour convertir un entier en binaire et le stocker dans une chaîne de caractères
void toBinary(int x, char *output, int *size) {
    int bitIndex = 0;
    while (x > 0 || bitIndex % 4 != 0) {
        output[bitIndex++] = (x & 1) ? '1' : '0';
        x >>= 1;
    }
    while (bitIndex % 4 != 0) {
        output[bitIndex++] = '0';
    }
    for (int i = 0; i < bitIndex / 2; i++) {
        char temp = output[i];
        output[i] = output[bitIndex - i - 1];
        output[bitIndex - i - 1] = temp;
    }
    output[bitIndex] = '\0';
    *size = bitIndex;
}

// Fonction pour formater la chaîne binaire avec des espaces tous les 4 bits
void formatBinary(char *input, char *output, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (i > 0 && i % 4 == 0) {
            output[count++] = ' ';
        }
        output[count++] = input[i];
    }
    output[count] = '\0';
}

int main(int argc, char** argv) {
    int num;
    if (argc == 1) {
        printf("entrer le nombre en decimal: ");
        scanf("%d", &num);
    } else {
        num = atoi(argv[1]);
    }
    
    char binary[33];
    char formattedBinary[41];
    int size;

    toBinary(num, binary, &size);
    formatBinary(binary, formattedBinary, size);

    printf("%s\n", formattedBinary);
    printf("%s\n", binary);

    return 0;
}
