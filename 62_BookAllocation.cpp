#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

bool isPossibleSolution(int A[], int N, int M, int sol) {
    int pageSum = 0;
    int c = 1;
    for(int i = 0; i < N; i++) {
        if(A[i] > sol) {
            return false;
        }
        if(pageSum + A[i] > sol) {
            c++;
            pageSum = A[i];
            if(c > M) {
                return false;
            }
        }
        else {
            pageSum += A[i];
        }
    }
    return true;
}

int main() {

    // Book Allocation Problem

    int N = 4;  // no. of books
    int A[] = {12, 34, 67, 90};  // no. of pages of each ith book
    int M = 2; // no. of students

    if(M > N) {
        cout << -1 << endl;
        return 0;
    }

    int s = 0;
    int e = accumulate(A, A + N, 0); // Corrected line

    int ans = -1;

    while(s <= e) {
        int mid = (s + e) / 2;
        if(isPossibleSolution(A, N, M, mid)) {
            ans = mid;
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
    cout << ans << endl;

    return 0;
}

