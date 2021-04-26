#include <iostream>
#include <queue>
using namespace std;

const int MAX = 1001;
int cowsRel[MAX][MAX];

int main() {
    int dis[MAX];
    queue<int> Q;
    bool inQ[MAX];
    int vis[MAX];
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cowsRel[i][j] = __INT_MAX__ / 2;
        }
        dis[i] = __INT_MAX__ / 2;
        inQ[i] = false;
        vis[i] = 0;
    }
    for (int i = 2; i < MAX; i++) {
        cowsRel[i][i - 1] = 0;
    }
    int N, ML, MD;
    cin >> N >> ML >> MD;
    int A, B, D;
    for (int i = 0; i < ML; i++) {
        cin >> A >> B >> D;
        cowsRel[A][B] = D;
    }
    for (int i = 0; i < MD; i++) {
        cin >> A >> B >> D;
        cowsRel[B][A] = -D;
    }
    dis[1] = 0;
    inQ[1] = true;
    Q.push(1);
    while (!Q.empty()) {
        int t = Q.front();
        Q.pop();
        if (++vis[t] == N) {
            cout << -1 << endl;
            return 0;
        }
        inQ[t] = false;
        for (int i = 1; i <= N; i++) {
            if (dis[i] > dis[t] + cowsRel[t][i]) {
                dis[i] = dis[t] + cowsRel[t][i];
                if (!inQ[i]) {
                    Q.push(i);
                    inQ[i] = true;
                }
            }
        }
    }
    if (dis[N] == __INT_MAX__ / 2)
        cout << -2 << endl;
    else
        cout << dis[N] << endl;
    return 0;
}

//对于有一个未知数确定的差分约束系统，通过最短路径算法求出来的一组解当中所有未知数都取最大值。
//与书中不同，这里没有使用额外节点0。
//如果使用额外节点，dis[0]确定，要求最长列，也就是要让解取最小值，需要使用最长路径算法。