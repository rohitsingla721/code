#include <iostream>
using namespace std;

// Standard insertion sort (counts shifts + insert)
int standardInsertionSort(int arr[], int n) {
    int count = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; // shift
            j--;
            count++;
        }
        arr[j + 1] = key; // insert
        count++;
    }
    return count;
}

// Min-swap insertion sort (counts actual adjacent swaps)
int minSwapInsertionSort(int arr[], int n) {
    int swaps = 0;
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && arr[j] < arr[j - 1]) {
            swap(arr[j], arr[j - 1]);
            swaps++;
            j--;
        }
    }
    return swaps;
}

int main() {
    int a[] = {4, 3, 2};
    int b[] = {4, 3, 2};
    int n = sizeof(a) / sizeof(a[0]);

    int standard_ops = standardInsertionSort(a, n);
    int swap_ops = minSwapInsertionSort(b, n);

    // Print results for standard insertion sort
    cout << "Standard sorted: ";
    for (int i = 0; i < n; i++) cout << a[i] <<endl;
    cout << "\nWrites (shifts + insertions): " << standard_ops << endl;

    // Print results for min-swap insertion sort
    cout << "Min-swap sorted: ";
    for (int i = 0; i < n; i++) cout << b[i] << " ";
    cout << "\nSwaps: " << swap_ops << endl;

    return 0;
}
