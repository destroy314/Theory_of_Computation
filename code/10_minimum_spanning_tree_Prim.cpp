#include <algorithm>
#include <iostream>
using namespace std;

struct node {
    int key;
    bool inQ;
}

int main() {
    int N, M;
    cin >> N >> M;
    auto cmp = [](node x, node y) { return x.key > y.key; };
    int* Q = new node[N];
    int Qlength = N;
    for (int i = 0; i < N; i++) {
        Q[i].key = INT_MAX
    }
    int** weight = new int*[N];
    for (int i = 0; i < N; i++) {
        weight[i] = new int[N];
        for (int j = 0; j < N; j++) {
            weight[i][j] = INT_MAX;
        }
    }
    int L, K, P;
    for (int i = 0; i < M; i++) {
        cin >> L >> K >> P;
        weight[L][K] = P;
    }
    long long int sum = 0;
    Q[0].key = 0;

    while (Qlength != 0) {
        pop_heap(Q, Q + Qlength, cmp);
        int u = Q[Qlength--];
        sum += u.key;
        for (int i = 0; i < N; i++) {
            if (weight[i][u] < key[i]) {
                key[i] = weight[i][u];
                // Q[Qlength++] = i;
                push_heap(Q, Q + Qlength, cmp)
            }
        }
        for (int i = 0; i < N; i++) {
            if (weight[u][i] < key[i]) {
                key[i] = weight[i][u];
                // Q[Qlength++] = i;
                push_heap(Q, Q + Qlengt, cmp)
            }
        }
    }

    return 0;
}

//此程序未完成