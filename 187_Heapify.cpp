#include <iostream>
using namespace std;

void heapify(int arr[], int size, int i)
{
    int index = i;
    int leftIndex = 2 * index;
    int rightIndex = 2 * index + 1;

    int largest = index;

    if (leftIndex <= size && arr[largest] < arr[leftIndex])
    {
        largest = leftIndex;
    }

    if (rightIndex <= size && arr[largest] < arr[rightIndex])
    {
        largest = rightIndex;
    }

    if (largest != index)
    {
        swap(arr[index], arr[largest]);
        heapify(arr, size, largest); // Corrected the parameter here
    }
}

void buildHeap(int arr[], int n)
{
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }
}

int main()
{
    int arr[] = {-1, 12, 15, 13, 11, 14};
    int n = 5;

    buildHeap(arr, n);

    cout << "Printing heap: ";
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
