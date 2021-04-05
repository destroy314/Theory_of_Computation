#include <iostream>
using namespace std;
const int mod = 9973;

struct matrix {
    int a = 0, b = 0, c = 0, d = 0;
};

matrix multiply(matrix m1, matrix m2) {
    matrix ans;
    ans.a = (m1.a * m2.a % mod + m1.b * m2.c % mod) % mod;
    ans.b = (m1.a * m2.b % mod + m1.b * m2.d % mod) % mod;
    ans.c = (m1.c * m2.a % mod + m1.d * m2.c % mod) % mod;
    ans.d = (m1.c * m2.b % mod + m1.d * m2.d % mod) % mod;
    return ans;
}

matrix quickpow(int k) {
    matrix ans, a;
    ans.a = ans.b = ans.c = ans.d = 1;
    a.a = 4;
    a.b = 1;
    a.c = -1;
    a.d = 0;
    while (k) {
        if (k & 1) {
            ans = multiply(ans, a);
        }
        a = multiply(a, a);
        k >>= 1;
    }
    return ans;
}

int main() {
    int k;
    while (cin >> k && k != -1) {
        if (k == 0) {
            cout << 1 << endl;
            continue;
        }
        if (k % 2) {
            cout << 0 << endl;
            continue;
        }
        matrix mat = quickpow(k / 2);
        cout << (mat.c + mod) % mod << endl;
    }
    return 0;
}