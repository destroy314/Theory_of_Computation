#include <iostream>
using namespace std;

int main() {
    string T, P;
    cin >> T >> P;
    int *pi = new int[P.length() + 1];
    pi[1] = 0;
    int k = 0;
    for (int q = 2; q <= P.length(); q++) {
        while (k > 0 && P[k] != P[q - 1]) k = pi[k];
        if (P[k] == P[q - 1]) k++;
        pi[q] = k;
    }
    int q = 0;
    for (int i = 1; i <= T.length(); i++) {
        while (q > 0 && P[q] != T[i - 1]) q = pi[q];
        if (P[q] == T[i - 1]) q++;
        if (q == P.length()) {
            cout << i - P.length() << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}