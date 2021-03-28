#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int *price = new int[n + 1];
    int *bestPrice = new int[n + 1];
    int *split = new int[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> price[i];
        split[i] = i;
        bestPrice[i] = price[i];
        for (int j = i - 1; j > 0; j--) {
            if (price[j] + bestPrice[i - j] > bestPrice[i]) {
                bestPrice[i] = price[j] + bestPrice[i - j];
                split[i] = j;
            }
        }
    }
    cout << bestPrice[n] << endl;
    int *ans = new int[n];
    int i = n, j = 0;
    while (i > 0) {
        ans[j++] = split[i];
        i -= split[i];
    }
    sort(ans, ans + j);
    cout << ans[--j];
    while (j > 0) {
        cout << ' ' << ans[--j];
    }
    cout << endl;
    return 0;
}