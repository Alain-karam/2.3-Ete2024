setup() {
    gcc -o 1-StructuresEtUnions 1-StructuresEtUnions.c -lm
    gcc -o 2-Static 2-Static.c
}

@test "1-StructuresEtUnions sans argument" {
    run ./1-StructuresEtUnions
    [ "$status" -eq 1 ]
    [ "${lines[0]}" = "Erreur: nombre d'arguments incorrect" ]
    [ "${lines[1]}" = "Usage: ./1-StructuresEtUnions a b c" ]
    [ "${lines[2]}" = "Résoud l'équation quadratique ax^2 + bx + c == 0." ]
}

@test "1-StructuresEtUnions avec 0 solution" {
    run ./1-StructuresEtUnions 1 1 1
    [ "$status" -eq 0 ]
    [ "${lines[0]}" = "L'equation" ]
    [ "$(echo ${lines[1]} | sed 's/^[ \t]*//;s/[ \t]*$//')" = "1.00x^2 + 1.00x + 1.00 = 0" ]
    [ "${lines[2]}" = "n'admet aucune solution" ]
}

@test "1-StructuresEtUnions avec 1 solution" {
    run ./1-StructuresEtUnions 1 2 1
    [ "$status" -eq 0 ]
    [ "${lines[0]}" = "L'equation" ]
    [ "$(echo ${lines[1]} | sed 's/^[ \t]*//;s/[ \t]*$//')" = "1.00x^2 + 2.00x + 1.00 = 0" ]
    [ "${lines[2]}" = "admet une solution: -1.00" ]
}

@test "1-StructuresEtUnions avec 2 solutions" {
    run ./1-StructuresEtUnions -1 -1 1
    [ "$status" -eq 0 ]
    [ "${lines[0]}" = "L'equation" ]
    [ "$(echo ${lines[1]} | sed 's/^[ \t]*//;s/[ \t]*$//')" = "-1.00x^2 - 1.00x + 1.00 = 0" ]
    [ "${lines[2]}" = "admet deux solutions: -1.62 et 0.62" ]
}

@test "2-Static" {
    expected_output="Cycle:
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
19: à la folie"


    run ./2-Static
    [ "$output" = "$expected_output" ]
}

teardown() {
    rm -f 1-StructuresEtUnions
    rm -f 2-Static
}
