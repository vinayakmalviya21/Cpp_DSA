#include <iostream>
using namespace std;

class Heap{
    public:
    int arr[101];
    int size;

    Heap(){
        size = 0;
    }

    void insert(int value){
        // Value insert karo end me
        size = size+1;
        int index = size;
        arr[index] = value;

        // Iss value ko place at right position
        while(index>1){
            int parentIndex = index/2;
            if (arr[index]>arr[parentIndex])
            {
                swap(arr[index],arr[parentIndex]);
                index = parentIndex;
            }
            else{
                break;
            }
        }
    }

    int remove(){
        int ans = arr[1];
        // Replace root node value with last node data
        arr[1] = arr[size];
        size--;

        // Place root node ka data on its correct position
        int index=1;
        while (index<size)
        {
            int left = 2*index;
            int right = 2*index+1;

            int largest = index;

            if(left<size && arr[largest]<arr[left]){
                largest = left;
            }

            if(right<size && arr[largest]<arr[right]){
                largest = right;
            }

            if(largest == index){
                // Value is at correct position
                break;
            }
            else{
                swap(arr[index],arr[largest]);
                index = largest;
            }
        }
        return ans;
    }
};

int main()
{

    // * Heaps - 1
    // ! Data structure which is (complete binary tree and that holds a heap property).

    // ! Complete Binary tree is all levels are completely filled except last one and filling is done from Left to Right.

    // Create a heap object
    Heap h;
    h.arr[0]=-1;
    h.arr[1]=100;
    h.arr[2]=50;
    h.arr[3]=60;
    h.arr[4]=40;
    h.arr[5]=45;
    h.size=5;

    cout << "Printing heap before insertion: ";
    for (int i = 1; i <= h.size; i++) {
        cout << h.arr[i] << " ";
    }
    cout << endl;

    // * Insertion

    // Insert elements into the heap
    h.insert(110);

    cout << "Printing heap after insertion: ";
    for (int i = 1; i <= h.size; i++) {
        cout << h.arr[i] << " ";
    }
    cout << endl;


    // * Deletion

    cout << "Heap before deletion: ";
    for (int i = 1; i <= h.size; i++) {
        cout << h.arr[i] << " ";
    }
    cout << endl;

    // Delete an element from the heap
    int deletedElement = h.remove();
    cout << "Deleted element: " << deletedElement << endl;

    cout << "Heap after deletion: ";
    for (int i = 1; i <= h.size; i++) {
        cout << h.arr[i] << " ";
    }
    cout << endl;

    return 0;
}