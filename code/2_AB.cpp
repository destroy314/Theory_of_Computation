#include <iostream>
#include <string>

#include "math.h"
using namespace std;

bool allzero(string X) {
    for (int i = 0; i < X.length(); i++) {
        if (X[i] != '0') return false;
    }
    return true;
}

string pow10(string X, int n) { return X + string(n, '0'); }

string align(string X, int n) { return string(n - X.length(), '0') + X; }

int pow2length(int l) {
    int i;
    for (i = 0;; i++) {
        if (pow(2, i) >= l) return pow(2, i);
    }
}

string removeZero(string X) {
    int i;
    for (i = 0; i < X.length(); i++) {
        if (X[i] != '0') break;
    }
    return X.substr(i);
}

bool bigger(string X, string Y) {
    X = removeZero(X);
    Y = removeZero(Y);
    int xl = X.length(), yl = Y.length();
    if (xl != yl) return xl > yl;
    for (int i = 0; i < xl; i++) {
        if (X[i] > Y[i])
            return true;
        else if (X[i] < Y[i])
            return false;
    }
    return false;
}

string add(string X, string Y) {
    int xl = X.length(), yl = Y.length();
    int ansl = (xl > yl ? xl : yl) + 1;
    X = align(X, ansl);
    Y = align(Y, ansl);
    string ans = string(ansl, '0');
    for (int i = ansl - 1; i >= 0; i--) {
        int t = X[i] - '0' + Y[i] - '0' + ans[i] - '0';
        if (t >= 10) {
            t -= 10;
            ans[i - 1] = '1';
        }
        ans[i] = t + '0';
    }
    return removeZero(ans);
}

string sub(string X, string Y, int& sym) {
    string H, S;
    if (bigger(X, Y)) {
        H = X;
        S = Y;
        sym = 1;
    } else {
        H = Y;
        S = X, sym = -1;
    }
    int ansl = H.length() > S.length() ? H.length() : S.length();
    H = align(H, ansl);
    S = align(S, ansl);
    string ans = string(ansl, '0');
    for (int i = ansl - 1; i >= 0; i--) {
        int t = H[i] - S[i] + ans[i] - '0';
        if (t < 0) {
            t += 10;
            ans[i - 1] = -1 + '0';
        }
        ans[i] = t + '0';
    }
    return ans;
}

string time(string X, string Y) {
    int n = X.length();
    if (n == 1) return to_string(stoi(X) * stoi(Y));
    if (allzero(X) || allzero(Y)) return "0";
    string m1, m2;
    string A = X.substr(0, n / 2), B = X.substr(n / 2);
    string C = Y.substr(0, n / 2), D = Y.substr(n / 2);
    string AC = time(A, C), BD = time(B, D);
    m1 = pow10(AC, n);
    int s1 = 1, s2 = 1;
    string A_B = sub(A, B, s1), D_C = sub(D, C, s2);
    string A_BD_C = time(A_B, D_C);
    int s = s1 * s2;
    m2 = add(AC, BD);
    if (s == 1) {
        m2 = add(m2, A_BD_C);
    } else {
        int t = 0;
        m2 = sub(m2, A_BD_C, t);
    }
    m2 = pow10(m2, n / 2);
    string ans = add(m1, m2);
    ans = add(ans, BD);
    return align(ans, pow2length(ans.length()));
}

int main() {
    string X, Y;
    cin >> X >> Y;
    int l1 = pow2length(X.length()), l2 = pow2length(Y.length());
    int lmax = l1 > l2 ? l1 : l2;
    X = align(X, lmax);
    Y = align(Y, lmax);
    cout << removeZero(time(X, Y)) << endl;
    return 0;
}