#include <iostream>
using namespace std;

int main() {
    int g[5][5] = {
        {0, 10, 0, 5, 0},
        {0, 0, 1, 2, 0},
        {0, 0, 0, 0, 4},
        {0, 3, 9, 0, 2},
        {7, 0, 6, 0, 0}
    };

    int n = 5, INF = 1e9;

    // Replace 0s (no edge) with INF, except for the diagonal
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && g[i][j] == 0) {
                g[i][j] = INF;
            }
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][k] + g[k][j] < g[i][j]) {
                    g[i][j] = g[i][k] + g[k][j];
                }
            }
        }
    }

    // Output shortest paths between all pairs (no if condition)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << i << " -> " << j << ": " << g[i][j] << "\n";
        }
    }

    return 0;
}
