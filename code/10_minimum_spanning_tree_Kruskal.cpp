#include <string.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

inline int min(int a, int b) { return a < b ? a : b; }
inline int max(int a, int b) { return a > b ? a : b; }

struct edge {
    int n1, n2;
    int weight;
};
bool cmp(edge n1, edge n2) { return n1.weight < n2.weight; }

vector<vector<int>> forest;
vector<vector<edge>> forestEdge;

int main() {
    int N, M;
    cin >> N >> M;
    if (M < N - 1) {
        cout << "impossible\n";
        return 0;
    }
    int* treeBelow = new int[N];
    memset(treeBelow, -1, sizeof(int) * N);
    edge* E = new edge[M];
    for (int i = 0; i < M; i++) {
        cin >> E[i].n1 >> E[i].n2 >> E[i].weight;
    }
    sort(E, E + M, cmp);
    for (int i = 0; i < M; i++) {
        if (treeBelow[E[i].n1] == -1 && treeBelow[E[i].n2] == -1) {
            vector<int> newTree;
            newTree.push_back(E[i].n1);
            newTree.push_back(E[i].n2);
            forest.push_back(newTree);
            treeBelow[E[i].n1] = forest.size() - 1;
            treeBelow[E[i].n2] = forest.size() - 1;
            vector<edge> newTreeEdge;
            newTreeEdge.push_back(E[i]);
            forestEdge.push_back(newTreeEdge);
        } else if (treeBelow[E[i].n1] == -1) {
            forest[treeBelow[E[i].n2]].push_back(E[i].n1);
            treeBelow[E[i].n1] = treeBelow[E[i].n2];
            forestEdge[treeBelow[E[i].n2]].push_back(E[i]);
        } else if (treeBelow[E[i].n2] == -1) {
            forest[treeBelow[E[i].n1]].push_back(E[i].n2);
            treeBelow[E[i].n2] = treeBelow[E[i].n1];
            forestEdge[treeBelow[E[i].n1]].push_back(E[i]);
        } else if (treeBelow[E[i].n1] != treeBelow[E[i].n2]) {
            int s = min(treeBelow[E[i].n1], treeBelow[E[i].n2]);
            int b = max(treeBelow[E[i].n1], treeBelow[E[i].n2]);
            for (int i = 0; i < forest[b].size(); i++) {
                treeBelow[forest[b][i]] = s;
                forest[s].push_back(forest[b][i]);
            }
            forest[b].clear();
            for (int i = 0; i < forestEdge[b].size(); i++) {
                forestEdge[s].push_back(forestEdge[b][i]);
            }
            forestEdge[s].push_back(E[i]);
            forestEdge[b].clear();
        }
    }
    if (forest[0].size() < N) {
        cout << "impossible\n";
        return 0;
    }
    long long int sum = 0;
    for (int i = 0; i < N - 1; i++) {
        sum += forestEdge[0][i].weight;
    }
    cout << sum << endl;
    return 0;
}