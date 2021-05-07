#include <cstring>
#include <iostream>
using namespace std;
const int N = 500 + 10;
int n, g[N][N], res, vis[N], mat[N];
struct node {
    int h;
    string a, b, c;
} t[N];
int find(int x) {
    for (int i = 1; i <= n; i++) {
        if (g[x][i] && !vis[i]) {
            vis[i] = 1;
            if (!mat[i] || find(mat[i])) {
                mat[i] = x;
                return 1;
            }
        }
    }
    return 0;
}
inline void solve() {
    cin >> n;
    memset(mat, 0, sizeof mat);
    memset(g, 0, sizeof g);
    res = 0;
    for (int i = 1; i <= n; i++) cin >> t[i].h >> t[i].a >> t[i].b >> t[i].c;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            if (t[j].a != t[i].a) {
                if (t[i].b == t[j].b && t[i].c != t[j].c &&
                    abs(t[i].h - t[j].h) <= 40)
                    g[i][j] = 1;
            }
    }
    for (int i = 1; i <= n; i++) memset(vis, 0, sizeof vis), res += find(i);
    cout << n - res / 2 << '\n';
}
signed main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}

//抄来的匈牙利算法