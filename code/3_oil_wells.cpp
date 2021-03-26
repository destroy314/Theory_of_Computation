#include <algorithm>
#include <iostream>
using namespace std;

int ow[200001];

void swap(int a, int b) {
    int t = ow[a];
    ow[a] = ow[b];
    ow[b] = t;
    return;
}

int partition(int p, int q, int mid) {
    while (1) {
        while (1) {
            if (ow[q] >= mid && p < q) q--;
            if (ow[p] <= mid && p < q) p++;
            if ((ow[q] < mid && ow[p] > mid) || p == q) break;
        }
        if (p < q)
            swap(p, q);
        else
            return p;
    }
}

int select(int p, int q, int k) {
    if (q - p < 75) {
        sort(ow + p, ow + q + 1);
        return ow[p + k - 1];
    }
    for (int i = 0; i <= (q - p - 4) / 5; i++) {
        sort(ow + p + i * 5, ow + p + i * 5 + 4);
        swap(p + i * 5 + 2, p + i);
    }
    int smid = select(p, p + (q - p - 4) / 5, (q - p - 4) / 10);
    int i = partition(p, q, smid), j = i - p + 1;
    if (k <= j)
        return select(p, i, k);
    else
        return select(i + 1, q, k - j);
}

int main() {
    int x, y, n = 0;
    char c;
    while (cin >> x) {
        cin >> c >> y;
        ow[n++] = y;
    }
    cout << select(0, n - 1, (n + 1) / 2) << endl;
    return 0;
}