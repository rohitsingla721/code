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

    int d[5];             
    int v[5] = {};        
    int n = 5;            
    int INF = 1e9;        

    // Step 1: Initialize distances
    for (int i = 0; i < n; i++)
        d[i] = INF;       
    d[0] = 0;             

 
    for (int i = 0; i < n; i++) {
        int u = -1;       

      
        for (int j = 0; j < n; j++)
            if (!v[j] && (u == -1 || d[j] < d[u]))
                u = j;

        v[u] = 1;        

      
        for (int j = 0; j < n; j++)
            if (g[u][j] && d[u] + g[u][j] < d[j])
                d[j] = d[u] + g[u][j];
    }

  
    for (int i = 0; i < n; i++)
        cout << "Shortest distance from 0 to " << i << " = " << d[i] << endl;
    return 0;
}
