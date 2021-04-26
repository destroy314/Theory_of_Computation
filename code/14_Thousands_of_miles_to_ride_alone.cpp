#include <iostream>
using namespace std;

struct road {
    int to;
    road* next;
};

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        int N;
        cin >> N;
        road** map = new road*[N + 1];
        for (int j = 1; j <= N; j++) map[j] = NULL;
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                int t;
                cin >> t;
                if (t == 1) {
                    road* r = new road;
                    r->to = k;
                    r->next = map[j];
                    map[j] = r;
                }
            }
        }
        float* gates = new float[N + 1];
        gates[1] = 1;
        gates[N] = 1;
        for (int j = 2; j <= N - 1; j++) {
            cin >> gates[j];
        }
        bool* s = new bool[N + 1];
        float* maxPossible = new float[N + 1];
        for (int j = 1; j <= N; j++) {
            s[j] = false;
            maxPossible[j] = 0;
        }
        s[1] = true;
        maxPossible[1] = 1;
        road* p = map[1];
        while (p != NULL) {
            maxPossible[p->to] = gates[p->to];
            p = p->next;
        }
        for (int j = 1; j < N; j++) {
            float tmpPossible = 0;
            int u = 1;
            for (int k = 2; k <= N; k++) {
                if (!s[k] && maxPossible[k] > tmpPossible) {
                    tmpPossible = maxPossible[k];
                    u = k;
                }
            }
            if (tmpPossible < 0.0001) {
                cout << "Case " << i << ": Cannot reach!" << endl;
                goto end;
            }
            s[u] = true;
            if (u == N) {
                break;
            }
            road* q = map[u];
            while (q != NULL) {
                if (s[q->to]) {
                    q = q->next;
                    continue;
                }
                float newPossible = maxPossible[u] * gates[q->to];
                if (newPossible > maxPossible[q->to])
                    maxPossible[q->to] = newPossible;
                q = q->next;
            }
        }
        if (maxPossible[N] < 0.0001) {
            cout << "Case " << i << ": Cannot reach!" << endl;
            continue;
        }
        cout.precision(4);
        cout << fixed << "Case " << i << ": " << maxPossible[N] << endl;
    end:;
    }
    return 0;
}