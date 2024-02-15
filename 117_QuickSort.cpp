#include <iostream>
#include <algorithm>
using namespace std;

void quickSort(int arr[], int start, int end) {
    if (start >= end) return;

    int i = start - 1;
    int j = start;
    int pivot = end;

    while (j < pivot) {
        if (arr[j] < arr[pivot]) {
            ++i;
            swap(arr[i], arr[j]);
        }
        ++j;
    }
    ++i;
    swap(arr[i], arr[pivot]);
    quickSort(arr, start, i - 1);
    quickSort(arr, i + 1, end);
}

int main() {
    // Quick Sort

    int arr[] = {4, 1, 3, 9, 7};
    int n = sizeof(arr) / sizeof(arr[0]); // Get the size of the array
    int start = 0;
    int end = n - 1;

    quickSort(arr, start, end);

    for (int k = 0; k < n; k++) {
        cout << arr[k] << " ";
    }
    cout << endl;

    return 0;
}
