#include <iostream>
#include <vector>
using namespace std;

class KQueues {
public:
    int n, k, freeSpot;
    int *arr, *front, *rear, *next;

    KQueues(int _n, int _k) : n(_n), k(_k), freeSpot(0) {
        arr = new int[n];
        next = new int[n];
        front = new int[k];
        rear = new int[k];

        for (int i = 0; i < k; i++) {
            front[i] = rear[i] = -1;
        }

        for (int i = 0; i < n - 1; i++) {
            next[i] = i + 1;
        }
        next[n - 1] = -1;
    }

    // Push x into qith Queue
    bool push(int x, int qi) {
        // Overflow
        if (freeSpot == -1) {
            return false;
        }

        int index = freeSpot;
        freeSpot = next[index];

        // if first element in qi
        if (front[qi] == -1) {
            front[qi] = index;
        } else {
            // link new element to the rear element of the queue
            next[rear[qi]] = index;
        }

        // Update rear
        rear[qi] = index;
        arr[index] = x;
        return true;
    }

    // Pop element from qith Queue
    int pop(int qi) {
        // Underflow
        if (front[qi] == -1) {
            return -1;
        }

        int index = front[qi];
        front[qi] = next[index];

        // update freespots
        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }
};

int main() {
    
    int k = 3;  // Number of queues
    int n = 10; // Total size of the array

    KQueues kq(n, k);

    kq.push(1, 0);
    kq.push(2, 1);
    kq.push(3, 2);

    cout << kq.pop(0) << endl; // Output: 1
    cout << kq.pop(1) << endl; // Output: 2
    cout << kq.pop(2) << endl; // Output: 3

    return 0;
}
