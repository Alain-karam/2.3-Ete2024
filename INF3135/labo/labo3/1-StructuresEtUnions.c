#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define USAGE "\
Usage: %s a b c\n\
Résoud l'équation quadratique ax^2 + bx + c == 0.\n\
"


struct pair {
    double first;
    double second;
};

struct equation {
    double a;
    double b;
    double c;
};

struct solution {
    struct equation equation;
    unsigned int num_solutions;
    union {
        double one_solution;
        struct pair two_solutions;
    } solutions;
};

struct solution solve_equation(struct equation eq) {
    double delta = pow(eq.b,2) - 4.0 * eq.a * eq.c;

    struct solution sol;
    sol.equation = eq;

    if(delta < 0) {
        sol.num_solutions = 0;
    } else
    if(delta == 0) {
        sol.num_solutions = 1;
        sol.solutions.one_solution = (-eq.b) / (2 * eq.a);
    } else {
        sol.num_solutions = 2;
        sol.solutions.two_solutions.first = (-eq.b + sqrt(delta)) / (2 * eq.a);
        sol.solutions.two_solutions.second = (-eq.b - sqrt(delta)) / (2 * eq.a);
    }

    return sol;
}

void print_solution(struct solution sol) {
    printf("L'equation\n\t%.2lfx^2 %c %.2lfx %c %.2lf = 0\n",
        sol.equation.a,
        sol.equation.b >= 0 ? '+' : '-', fabs(sol.equation.b),
        sol.equation.c >= 0 ? '+' : '-', fabs(sol.equation.c));
    
    switch(sol.num_solutions) {
        case 0:
            printf("n'admet aucune solution\n");
            break;
        case 1:
            printf("admet une solution: %.2lf\n",
                sol.solutions.one_solution);
            break;
        case 2: 
            printf("admet deux solutions: %.2lf et %.2lf\n",
                sol.solutions.two_solutions.first,
                sol.solutions.two_solutions.second);
            break;
    }
}

int main(int argc, char** argv) {
    if(argc != 4) {
        fprintf(stderr, "Erreur: nombre d'arguments incorrect\n");
        fprintf(stderr, USAGE, argv[0]);
        return 1;
    } else {
        double a = atof(argv[1]);
        double b = atof(argv[2]);
        double c = atof(argv[3]);

        struct equation eq = { .a=a , .b=b , .c=c };
        struct solution sol = solve_equation(eq);
        print_solution(sol);
        return 0;
    }
}