#include <algorithm>
#include <iostream>
using namespace std;

struct task {
    int d, w;
};

bool cmp(task a, task b) { return a.w > b.w; }

int main() {
    int n;
    cin >> n;
    task* t = new task[n];
    for (int i = 0; i < n; i++) {
        cin >> t[i].d;
    }
    for (int i = 0; i < n; i++) {
        cin >> t[i].w;
    }
    sort(t, t + n, cmp);
    int* maxEmptyPos = new int[n + 1];
    for (int i = 1; i <= n; i++) {
        maxEmptyPos[i] = i;
    }
    int w = 0;
    for (int i = 0; i < n; i++) {
        int p = maxEmptyPos[t[i].d];
        while (p != maxEmptyPos[p] && p != 0) {
            p = maxEmptyPos[p];
        }
        if (p != 0) {
            maxEmptyPos[p] -= 1;
            maxEmptyPos[t[i].d] = maxEmptyPos[p];
            continue;
        }
        w += t[i].w;
        maxEmptyPos[t[i].d] = 0;
    }
    cout << w << endl;
    return 0;
}