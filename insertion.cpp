#include <iostream>
using namespace std;


void insertionSortMinSwaps(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int j = i;


        while (j > 0 && arr[j] < arr[j - 1]) {
  
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;

            j--; 
        }
    }
}


int main() {
    int arr[] = {5, 3, 1, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);


    insertionSortMinSwaps(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
