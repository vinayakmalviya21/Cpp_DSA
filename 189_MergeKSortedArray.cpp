#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ! A structure to hold the element value, its corresponding array index, and its index within the array
struct HeapNode {
    int value;
    int arrayIndex;
    int elementIndex;

    HeapNode(int v, int ai, int ei) : value(v), arrayIndex(ai), elementIndex(ei) {}

    // ! Overloading the comparison operator for min-heap
    bool operator>(const HeapNode& other) const {
        return value > other.value;
    }
};


// ! Function to merge K sorted arrays
vector<int> mergeKSortedArrays(int arr[][4], int k, int n) {
    vector<int> result;
    priority_queue<HeapNode, vector<HeapNode>, greater<HeapNode>> minHeap;

    // ! Insert the first element from each array into the heap
    for (int i = 0; i < k; ++i) {
        if (n > 0) { // Ensure the array is not empty
            minHeap.push(HeapNode(arr[i][0], i, 0));
        }
    }

    // ! Merge step
    while (!minHeap.empty()) {
        // ! Pop the smallest element from the heap
        HeapNode node = minHeap.top();
        minHeap.pop();

        // ! Insert the popped element into the merged array
        result.push_back(node.value);

        // ! Replace the popped element with the next element from the same array
        int nextIndex = node.elementIndex + 1;
        if (nextIndex < n) { // Ensure index is within array bounds
            minHeap.push(HeapNode(arr[node.arrayIndex][nextIndex], node.arrayIndex, nextIndex));
        }
    }
    return result;
}

int main() {

    // * Merge K-sorted arrays

    int arr[][4] = {
        {2, 4, 6, 8},
        {1, 3, 5, 7},
        {8, 9, 10, 11}
    };
    int k = 3; // Number of arrays
    int n = 4; // Size of each array

    vector<int> mergedArray = mergeKSortedArrays(arr, k, n);

    // Print the merged array
    cout << "Merged Array: ";
    for (int num : mergedArray) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
