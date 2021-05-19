#include <iostream>
#include <random>
using namespace std;
typedef __uint128_t ufl;  // unsigned fucking long

ufl pow_mod(ufl a, ufl b, ufl n) {
    ufl res = 1;
    a = a % n;
    while (b > 0) {
        if (b & 1) {
            res = res * a % n;
        }
        b = b >> 1;
        a = a * a % n;
    }
    return res;
}

bool withness(ufl a, ufl n) {
    int u = 0;
    ufl t;
    ufl tmp = 1;
    while (true) {
        u++;
        tmp *= 2;
        if ((n - 1) % tmp != 0) continue;
        t = (n - 1) / tmp;
        if (t & 1) break;
    }
    ufl x = pow_mod(a, t, n);
    for (int i = 1; i <= u; i++) {
        ufl y = pow_mod(x, 2, n);
        if (y == 1 && x != 1 && x != n - 1) return true;
        x = y;
    }
    if (x != 1)
        return true;
    else
        return false;
}

ufl gcd(ufl a, ufl b) {
    if (a < b)
        return gcd(b, a);
    else if (a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}

bool isPrime(ufl n) {
    independent_bits_engine<default_random_engine, 64, unsigned long long>
        engine;
    if (!(n & 1)) return false;
    if (n <= 3) return true;
    for (int j = 1; j <= 50; j++) {
        ufl a = (ufl)engine() % (n - 1) + 1;
        if (gcd(a, n) > 1 || withness(a, n)) return false;
    }
    return true;
}

int main() {
    unsigned long long n;
    cin >> n;
    if (isPrime((ufl)n))
        cout << "Prime" << endl;
    else
        cout << "Composite" << endl;
    return 0;
}