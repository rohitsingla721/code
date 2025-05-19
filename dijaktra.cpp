#include <iostream>
using namespace std;

int main() {
    // Graph represented as an adjacency matrix (5 nodes)
    int g[5][5] = {
        {0, 10, 0, 5, 0},
        {0, 0, 1, 2, 0},
        {0, 0, 0, 0, 4},
        {0, 3, 9, 0, 2},
        {7, 0, 6, 0, 0}
    };

    int d[5];             // Stores shortest distances from node 0
    int v[5] = {};        // Tracks if a node is visited (0 = no, 1 = yes)
    int n = 5;            // Number of nodes
    int INF = 1e9;        // A large number to represent infinity

    // Step 1: Initialize distances
    for (int i = 0; i < n; i++) {
        d[i] = INF;       // Start with all distances as infinity
    }
    d[0] = 0;             // Distance to self (node 0) is 0

    // Step 2: Main loop to find shortest path
    for (int i = 0; i < n; i++) {
        int u = -1;       // u will be the next node with smallest distance

        // Find the unvisited node with the smallest distance
        for (int j = 0; j < n; j++) {
            if (!v[j] && (u == -1 || d[j] < d[u])) {
                u = j;
            }
        }

        v[u] = 1;         // Mark node u as visited

        // Update distances to neighbors of node u
        for (int j = 0; j < n; j++) {
            if (g[u][j] && d[u] + g[u][j] < d[j]) {
                d[j] = d[u] + g[u][j];
            }
        }
    }

    // Step 3: Print shortest distances from node 0
    for (int i = 0; i < n; i++) {
        cout << "Shortest distance from 0 to " << i << " = " << d[i] << endl;
    }

    return 0;
}
