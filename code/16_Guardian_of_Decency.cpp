#include <cstring>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

const int MAXN = 502;

int r[MAXN][MAXN];  //残余网络
struct stu {
    int h;
    char g;
    string m, s;
} S[MAXN];

int before[MAXN];

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        for (int j = 0; j < N + 2; j++) memset(r[j], 0, sizeof(int) * (N + 2));
        for (int j = 0; j < N; j++) cin >> S[j].h >> S[j].g >> S[j].m >> S[j].s;
        for (int j = 0; j < N; j++) {
            if (S[j].g == 'F') continue;
            for (int k = 0; k < N; k++) {
                if (S[k].g == 'F' && abs(S[j].h - S[k].h) <= 40 &&
                    S[j].m == S[k].m && S[j].s != S[k].s)
                    r[j][k] = 1;
            }
        }
        int s = N;
        int t = N + 1;
        for (int j = 0; j < N; j++) {
            if (S[j].g == 'M') {
                r[s][j] = 1;
            } else {
                r[j][t] = 1;
            }
        }
        int maxflow = 0;
        while (true) {
            memset(before, -1, sizeof(int) * (N + 2));
            before[s] = -2;
            queue<int> bfs;
            bfs.push(s);
            while (!bfs.empty()) {
                int v = bfs.front();
                bfs.pop();
                for (int k = N + 1; k >= 0; k--) {
                    if (r[v][k] == 1 && before[k] == -1) {
                        before[k] = v;
                        bfs.push(k);
                        if (k == t) goto end;
                    }
                }
            }
        end:;
            if (before[t] == -1) break;
            maxflow++;
            int q = t;
            int p = before[q];
            while (true) {
                r[p][q] = 0;
                r[q][p] = 1;
                if (before[p] == -2) break;
                q = p;
                p = before[q];
            }
        }
        cout << N - maxflow << endl;
    }
    return 0;
}

//此程序在用例2TLE