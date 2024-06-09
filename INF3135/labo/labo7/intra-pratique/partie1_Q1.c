#include <stdio.h>

#define MATRIX_SIZE 10

struct matrix {
    double data[MATRIX_SIZE][MATRIX_SIZE];
};

void initialize_matrix(struct matrix *m, double v) {
    for(int i = 0; i < MATRIX_SIZE; i++) {
        for(int j = 0; j < MATRIX_SIZE; j++) {
            m->data[i][j] = v;
        }
    }
}

void print_matrix(struct matrix *m) {
    for(int i = 0; i < MATRIX_SIZE; i++) {
        for(int j = 0; j < MATRIX_SIZE; j++) {
            printf("%lf ", m->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    struct matrix m;
    double v = 5.0;
    initialize_matrix(&m, v);
    print_matrix(&m);

    return 0;
}
