#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<int> cable;

bool cutable(int length) {
    long long int cutnum = 0;
    for (int i = 0; i < N; i++) {
        cutnum += (cable[i] / length);
    }
    return cutnum >= K;
}

int find(int start, int end) {
    if (start + 1 == end) return start;
    int mid = (start + end) / 2;
    if (cutable(mid))
        return find(mid, end);
    else
        return find(start, mid);
}

int main() {
    long long int sum = 0;
    int max = 0;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        float f;
        int t;
        cin >> f;
        t = (int)(f * 100 + 0.5);
        cable.push_back(t);
        sum += t;
        if (max < t) max = t;
    }
    int maxcount = 0;
    for (int i = 0; i < N; i++) {
        if (cable[i] == max) maxcount++;
    }
    if (sum < K) {
        cout << "0.00" << endl;
        return 0;
    }
    cout.precision(2);
    if (K <= maxcount) {
        cout << fixed << ((float)max) / 100 << endl;
        return 0;
    }
    cout << fixed << ((float)find(1, max)) / 100 << endl;
    return 0;
}