#include <iostream>
using namespace std;
const int MAX = 101;

int n;

int max(int a, int b) { return a > b ? a : b; }

void out(int s[MAX][MAX], int i, int j) {
    if (i == j) {
        cout << 'A' << i;
        return;
    }
    cout << '(';
    out(s, i, s[i][j]);
    out(s, s[i][j] + 1, j);
    cout << ')';
    return;
}

int main() {
    int q[MAX], m[MAX][MAX], s[MAX][MAX];
    cin >> n;
    for (int i = 0; i <= n; i++) {
        cin >> q[i];
        m[i][i] = 0;
    }
    for (int r = 1; r <= n - 1; r++) {
        for (int i = 1; i <= n - r; i++) {
            int j = i + r;
            s[i][j] = i;
            m[i][j] = m[i][i] + m[i + 1][j] + q[i - 1] * q[i] * q[j];
            for (int k = i + 1; k <= j - 1; k++) {
                int n = m[i][k] + m[k + 1][j] + q[i - 1] * q[k] * q[j];
                if (n < m[i][j]) {
                    m[i][j] = n;
                    s[i][j] = k;
                }
            }
        }
    }
    cout << m[1][n] << endl;
    if (n == 1) cout << '(';
    out(s, 1, n);
    if (n == 1) cout << ')';
    cout << endl;
    return 0;
}