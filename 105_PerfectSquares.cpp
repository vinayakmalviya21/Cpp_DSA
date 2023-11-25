#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int numSquaresHelper(int n) {
    if (n == 0) {
        return 1;
    }

    int ans = INT_MAX;
    int i = 1;
    int end = sqrt(n);

    while (i <= end) {  // Fix: Change while condition from i<end to i<=end
        int perfectSquare = i * i;
        int numberOfPerfectSquares = 1 + numSquaresHelper(n - perfectSquare);

        if (numberOfPerfectSquares < ans) {
            ans = numberOfPerfectSquares;
        }
        ++i;
    }
    return ans;
}

int numSquares(int n) {
    return numSquaresHelper(n) - 1;  // Fix: Subtract 1 to correct the count
}

int main() {
    // Perfect Squares

    // Given an integer n, return the least number of perfect square numbers that sum to n.
    // A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself.

    int n = 12;
    
    cout << numSquares(n);

    return 0;
}
