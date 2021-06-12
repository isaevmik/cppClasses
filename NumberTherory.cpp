// Gcd
unsigned long long int gcd(unsigned long long int a,
                           unsigned long long int b) {
    while (b != 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

// Pow mod p
unsigned long long x, n, p;
unsigned long long binpow(unsigned long long a, unsigned long long n) {
    if (n == 0) {
        return 1;
    }
    if ((n % 2) == 1) {
        return (binpow(a, n - 1) * a) % p;
    }
    unsigned long long b = binpow(a, n / 2);
    return (b * b) % p;
}
