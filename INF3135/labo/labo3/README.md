# Labo 3: Programmation en C (suite)

## 1 - Structures et unions (60 minutes)

Dans cette question, vous devez écrire un programme nommé `quadratique.c` qui
permet de résoudre une équation du second degré de la forme 

```math
ax^2 + bx + c = 0
```

où $`a`$, $`b`$ et $`c`$ sont des nombres réels et $`x`$ est une variable
réelle inconnue. Le nombre de solutions réelles est entièrement déterminé par
le signe du *discriminant* $`\Delta = b^2 - 4ac`$ ($`\Delta`$ est la lettre
grecque majuscule prononcée « delta »):

- Si $`\Delta > 0`$, alors il existe deux solutions, qui sont
    ```math
    \frac{-b - \sqrt{\Delta}}{2a} \quad \text{et} \quad \frac{-b + \sqrt{\Delta}}{2a};
    ```

- Si $`\Delta = 0`$, alors il existe une solution, qui est $`-b / 2a`$;
- Si $`\Delta < 0`$, alors il n'existe aucune solution.

Pour représenter la situation en C, on déclare les types suivants:

```c
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

```

À noter que le contenu du champ `solutions` n'importe pas lorsque $`\Delta
< 0`$.

### A. Résolution d'une équation quadratique

Implémentez une fonction

```c
struct solution solve_equation(struct equation eq);
```

qui prend en argument une équation quadratique et qui retourne une instance de
type `struct solution` représentant toutes les solutions (aucune, une ou deux)
de l'équation $`ax^2 + bx + c = 0`$.

*Remarques*:

* La fonction `sqrt` (voir `man sqrt` pour plus d'informations) est disponible
  dans la bibliothèque standard `math.h`
* Lors de l'édition des liens, vous devez ajouter l'option `-lm` pour lier
  votre programme avec la bibliothèque `math`
* La position de l'option `-lm` est importante lorsque vous entrez la commande
  de compilation

### B. Affichage de la solution sur `stdout`

Implémentez une fonction

```c
void print_solution(struct solution sol);
```

qui affiche sur la sortie standard les solutions stockées dans `sol` avec
2 décimales de précision.

On s'attend à un affichage de la forme suivante:

```text
# Aucune solution, par exemple avec (a,b,c) = (1,1,1)
L'équation
  1.00x^2 + 1.00x + 1.00 == 0
n'admet aucune solution

# Une solution, par exemple avec (a,b,c) = (1,-2,1)
L'équation
  1.00x^2 - 2.00x + 1.00 == 0
admet une solution: 1.00

# Une solution, par exemple avec (a,b,c) = (1,-2,-4)
L'équation
  1.00x^2 - 2.00x - 4.00 == 0
admet deux solutions: 3.24 et -1.24
```

*Remarque*:

La fonction `fabs` (voir `man fabs`) pourrait vous être utile si vous souhaitez
embellir l'affichage des équations, par exemple, pour afficher
`1.00x^2 - 2.00x + 1.00 == 0` plutôt que `1.00x^2 + -2.00x + 1.00 == 0`.

### C. Récupération des arguments

Modifiez le programme `quadratique.c` de telle sorte qu'il accepte les
coefficients $`a`$, $`b`$ et $`c`$ comme arguments de la fonction `main` et
qu'il affiche sur la sortie standard si l'équation n'admet aucune solution, en
admet une ou en admet deux.

Vous n'avez pas à valider si les arguments sont bien des nombres flottants
(pour cela, il faut utiliser les pointeurs que nous n'avons pas encore vus),
mais vous devez afficher un message d'erreur (sur `stderr`) si le nombre
d'arguments fournis est incorrect et rappeler à l'utilisateur comment utiliser
le programme. Ainsi, on souhaite avoir le comportement suivant:

```text
$ ./quadratique 1 1 1
L'équation
  1.00x^2 + 1.00x + 1.00 == 0
n'admet aucune solution
$ ./quadratique 1 -2 1
L'équation
  1.00x^2 - 2.00x + 1.00 == 0
admet une solution: 1.00
$ ./quadratique 1 -2 -4
L'équation
  1.00x^2 - 2.00x - 4.00 == 0
admet deux solutions: 3.24 et -1.24
$ ./quadratique 1
Erreur: nombre d'arguments incorrect
Usage: ./quadratique a b c
Résoud l'équation quadratique ax^2 + bx + c == 0.
```

*Remarque*:

La fonction `atof` vous sera utile pour convertir une chaîne de caractères en
double (voir `man atof` pour plus d'informations)

### D. Documentation et cadre de tests

Rédigez un court fichier `README.md` respectant le format Markdown et décrivant
brièvement le fonctionnement du programme `quadratique`.

Ensuite, proposez un jeu de six tests qui vous convainquent que votre programme
fonctionne correctement. Ajoutez-les au fichier `README` afin d'illustrer des
exemples de commandes lancées et de résultats obtenus (en les plaçant dans des
blocs de code entre ` ```sh ` et ` ``` ` par exemple).

## 2 - Compilation et Makefile (30 minutes)

Ajoutez un fichier `Makefile` permettant de faciliter la compilation du
programme développé à la question précédente. Il doit respecter les contraintes
suivantes:

* La compilation (`quadratique.c` vers `quadratique.o`) et l'édition des liens
  (`quadratique.o` vers `quadratique`) sont traitées séparément
* La compilation se fait avec les options `-Wall`, `-Wextra` et `-std=c11`
* L'édition des liens se fait avec l'option `-lm`
* Lorsqu'on entre `make`, l'exécutable `quadratique` est produit sans
  avertissement
* Lorsqu'on entre `make clean`, le fichier `quadratique.o` et l'exécutable
  `quadratique` sont supprimés, s'ils existent
* Lorsqu'on entre `make exec`, l'exécutable est recompilé seulement si
  nécessaire, puis ensuite exécuté
* La cible spéciale `.PHONY` est utilisée au moins une fois

## 3 - Variable statique (40 minutes)

Considérez le fichier [static.c](static.c) disponible dans ce répertoire et en
particulier les deux fonctions

```c
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
void aimer_cycle(void);

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
void aimer_palindrome(void);
```

Sans modifier leur signature, réimplémentez-les de façon à obtenir le
comportement suivant:

```sh
$ gcc -o static static.c
$ ./static
Cycle:
00: un peu
01: beaucoup
02: passionnément
03: à la folie
04: pas du tout
05: un peu
06: beaucoup
07: passionnément
08: à la folie
09: pas du tout
10: un peu
11: beaucoup
12: passionnément
13: à la folie
14: pas du tout
15: un peu
16: beaucoup
17: passionnément
18: à la folie
19: pas du tout
Palindrome:
00: un peu
01: beaucoup
02: passionnément
03: à la folie
04: pas du tout
05: à la folie
06: passionnément
07: beaucoup
08: un peu
09: beaucoup
10: passionnément
11: à la folie
12: pas du tout
13: à la folie
14: passionnément
15: beaucoup
16: un peu
17: beaucoup
18: passionnément
19: à la folie

```

*Remarques*:

* Vous devez utiliser au moins une variable statique par fonction
* Une variable statique suffit pour la fonction `aimer_cycle`
* Quant à la fonction `aimer_palindrome`, deux variables statiques sont
  nécessaires
