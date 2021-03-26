#include <math.h>

#include <algorithm>
#include <iostream>
using namespace std;

typedef struct point {
    double x, y;
} POINT;
POINT* T = new POINT[100001];

bool xLess(POINT a, POINT b) { return a.x < b.x; }
bool yLess(POINT a, POINT b) { return a.y < b.y; }

double distance(POINT a, POINT b) {
    double d = pow(pow(a.x - b.x, 2) + pow(a.y - b.y, 2), 0.5);
    return d;
}

double closestDistance(POINT* X, POINT* Y, int p, int q) {
    if (q - p == 0) return __FLT_MAX__;
    if (q - p == 1) {
        sort(Y + p, Y + q + 1, yLess);
        return distance(X[p], X[q]);
    }
    int mid = (p + q) / 2;
    double d1 = closestDistance(X, Y, p, mid);  //完成后Y[p,mid]按y坐标从小到大
    double d2 = closestDistance(X, Y, mid + 1, q);
    double d = d1 < d2 ? d1 : d2;
    int m = p, n = mid + 1, k = q;
    while (m <= mid && n <= q) {
        if (Y[m].y <= Y[n].y)
            T[k++] = Y[m++];
        else
            T[k++] = Y[n++];
    }
    while (m <= mid) {
        T[k++] = Y[m++];
    }
    while (n <= q) {
        T[k++] = Y[n++];
    }
    POINT* band = new POINT[k - q];
    int l = 0;
    for (int i = p; i <= q; i++) {
        Y[i] = T[i];  // T中合并的结果拷贝回Y
        if (fabs(Y[i].x - X[mid].x) <= d)
            band[l++] = Y[i];  //条带内点加入band中
    }
    for (int i = 0; i < l; i++) {  //从小到大扫描band
        for (int j = i + 1; j < l && band[j].y - band[i].y <= d; j++) {
            if (distance(band[i], band[j]) < d) d = distance(band[i], band[j]);
        }
    }
    delete[] band;
    return d;
}

int main() {
    cout.precision(2);
    int N;
    cin >> N;
    while (N != 0) {
        POINT* X = new POINT[N];
        for (int i = 0; i < N; i++) {
            cin >> X[i].x >> X[i].y;
        }
        sort(X, X + N, xLess);
        POINT* Y = new POINT[N];
        for (int i = 0; i < N; i++) {
            Y[i] = X[i];
        }
        cout << fixed << closestDistance(X, Y, 0, N - 1) / 2 << endl;
        cin >> N;
    }
    return 0;
}