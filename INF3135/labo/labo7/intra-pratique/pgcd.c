int pgcd(int a, int b) {
    if (a == 0) return b;
    else if (b == 0) return a;
    else if (a < b) return pgcd(b, a);
    else return pgcd(a - b, b);
}
