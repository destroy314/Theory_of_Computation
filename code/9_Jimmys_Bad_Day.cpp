#include <string.h>

#include <iostream>
using namespace std;
const int MAX = 301;

int N;
int costi[MAX][MAX], costj[MAX][MAX];
int cwTimeTo[MAX], acwTimeTo[MAX];
int timeGapTo[MAX];

int min(int a, int b) { return a < b ? a : b; }

int main() {
    int m, t;
    while (cin >> N && N != 0) {
        int totalTime = 0;
        int weightIn[MAX][MAX];
        memset(weightIn, 0, sizeof(int) * MAX * MAX);
        for (int i = 0; i < N; i++) {
            cin >> m >> t;
            timeGapTo[i + 1] = t;
            totalTime += t;
            cwTimeTo[i + 1] = totalTime;
            for (int j = 0; j <= i; j++) {
                for (int k = i; k <= N; k++) {
                    weightIn[j][k] += m;
                }
            }
            costi[i][i] = 0;
            costj[i][i] = 0;
        }
        costi[N][N] = 0;
        costj[N][N] = 0;
        acwTimeTo[N] = 0;
        int aTotalTime = 0;
        for (int i = N - 1; i >= 0; i--) {
            aTotalTime += cwTimeTo[i + 1] - cwTimeTo[i];
            acwTimeTo[i] = aTotalTime;
        }

        for (int d = 1; d <= N; d++) {
            for (int i = 0; i + d <= N; i++) {
                int j = i + d;
                costi[i][j] =
                    min(costi[i + 1][j] + timeGapTo[i + 1] * weightIn[i + 1][j],
                        costj[i + 1][j] +
                            (cwTimeTo[i] + acwTimeTo[j]) * weightIn[i + 1][j]);

                costj[i][j] =
                    min(costj[i][j - 1] + timeGapTo[j] * weightIn[i][j - 1],
                        costi[i][j - 1] +
                            (cwTimeTo[i] + acwTimeTo[j]) * weightIn[i][j - 1]);
            }
        }
        cout << min(costi[0][N - 1], costj[1][N]) << endl;
    }
    return 0;
}