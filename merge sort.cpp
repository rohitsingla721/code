#include <iostream>
using namespace std;

void merge(int a[], int l, int m, int r) {
    int i = l, j = m + 1, b[100], k = 0;
    
    while (i <= m && j <= r) {
        if (a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }

    while (i <= m) b[k++] = a[i++];
    while (j <= r) b[k++] = a[j++];

    for (int x = 0; x < k; x++)
        a[l + x] = b[x];
}

void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main() {
    int a[] = {5, 2, 4, 1, 3};
    int n = 5;
    
    mergeSort(a, 0, n - 1);
    
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
