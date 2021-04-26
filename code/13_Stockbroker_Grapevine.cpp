#include <iostream>
using namespace std;

int timeTo[101][101];
int shortestTime[101][101];
bool s[101];
int totalTime[101];

int main() {
    int num;
    while (cin >> num && num != 0) {
        for (int i = 1; i <= num; i++) {
            for (int j = 1; j <= num; j++) timeTo[i][j] = __INT_MAX__;
            int n, ind, t;
            cin >> n;
            for (int j = 0; j < n; j++) {
                cin >> ind >> t;
                timeTo[i][ind] = t;
            }
        }

        for (int i = 1; i <= num; i++) {
            for (int j = 1; j <= num; j++) {
                shortestTime[i][j] = timeTo[i][j];
                s[j] = false;
            }
            shortestTime[i][i] = 0;
            s[i] = true;
            for (int j = 1; j < num; j++) {
                int tmp = __INT_MAX__;
                int u = i;
                for (int k = 1; k <= num; k++) {
                    if (!s[k] && shortestTime[i][k] < tmp) {
                        tmp = shortestTime[i][k];
                        u = k;
                    }
                }
                if (tmp == __INT_MAX__) {
                    for (int k = 1; k <= num; k++)
                        shortestTime[i][k] = __INT_MAX__;
                    goto end;
                }
                s[u] = true;
                for (int k = 1; k <= num; k++) {
                    if (!s[k] && timeTo[u][k] != __INT_MAX__) {
                        int newDist = shortestTime[i][u] + timeTo[u][k];
                        if (newDist < shortestTime[i][k])
                            shortestTime[i][k] = newDist;
                    }
                }
            }
        end:;
        }

        for (int i = 1; i <= num; i++) {
            totalTime[i] = 0;
            for (int j = 1; j <= num; j++) {
                if (shortestTime[i][j] > totalTime[i])
                    totalTime[i] = shortestTime[i][j];
            }
        }
        int min = __INT_MAX__, argmin = 0;
        for (int i = 1; i <= num; i++) {
            if (totalTime[i] < min) {
                min = totalTime[i];
                argmin = i;
            }
        }
        if (min == __INT_MAX__) {
            cout << "disjoint" << endl;
            continue;
        }
        cout << argmin << ' ' << min << endl;
    }
    return 0;
}