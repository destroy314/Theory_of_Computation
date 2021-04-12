#include <iostream>
using namespace std;

int main() {
    int n, h;
    int f[26], d[26], t[25];
    int fCopy[26];
    int timeSpend[26][26];
    int totalTime[26];
    int fish[26];
    cin >> n;
    while (n != 0) {
        cin >> h;
        for (int i = 1; i <= n; i++) {
            cin >> f[i];
            totalTime[i] = 0;
            fish[i] = 0;
            for (int j = 1; j <= n; j++) {
                timeSpend[i][j] = 0;
            }
        }
        for (int i = 1; i <= n; i++) {
            cin >> d[i];
        }
        for (int i = 1; i < n; i++) {
            cin >> t[i];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                fCopy[j] = f[j];
            }
            for (int j = 1; j < i; j++) {
                totalTime[i] += t[j] * 5;
            }
            if (totalTime[i] >= h * 60) {
                fish[i] = 0;
                continue;
            }
            do {
                int argmax = i;
                for (int j = i; j > 0; j--) {
                    if (fCopy[j] >= fCopy[argmax]) argmax = j;
                }
                fish[i] += fCopy[argmax];
                timeSpend[i][argmax] += 5;
                totalTime[i] += 5;
                fCopy[argmax] -= d[argmax];
                if (fCopy[argmax] < 0) fCopy[argmax] = 0;
            } while (totalTime[i] < h * 60);
        }
        int argmax = 1;
        for (int i = 1; i <= n; i++) {
            if (fish[i] > fish[argmax])
                argmax = i;
            else if (fish[i] == fish[argmax]) {
                for (int j = 1; j <= i; j++) {
                    if (timeSpend[i][j] > timeSpend[argmax][j]) {
                        argmax = i;
                        break;
                    } else if (timeSpend[i][j] < timeSpend[argmax][j]) {
                        break;
                    }
                }
            }
        }
        cout << timeSpend[argmax][1];
        for (int i = 2; i <= n; i++) {
            cout << ", " << timeSpend[argmax][i];
        }
        cout << endl << "Number of fish expected: " << fish[argmax] << endl;
        cin >> n;
        if (n != 0) cout << endl;
    }
    return 0;
}