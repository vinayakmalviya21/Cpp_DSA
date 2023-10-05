#include <iostream>
using namespace std;

bool isPossibleSolution(int A[], int n, int k, long long mid)
{
    long long timeSum = 0;
    int c = 1;
    for (int i = 0; i < n; i++)
    {
        if (A[i] > mid)
        {
            return false;
        }
        if (timeSum + A[i] > mid)
        {
            c++;
            timeSum = A[i];
            if (c > k)
            {
                return false;
            }
        }
        else
        {
            timeSum += A[i];
        }
    }
    return true;
}

int main()
{

    // * Painter's Partition Problem
    // ! k painters requires 1 unit time to paint

    int n = 4; // No. of boards
    int A[] = {10, 20, 30, 40};
    int k = 2; // No. of painters

    long long start = 0;
    long long end = 0;
    for (int i = 0; i < n; i++)
    {
        end += A[i];
    }
    long long ans = -1;

    while (start <= end)
    {
        long long mid = start + (end - start) / 2;
        if (isPossibleSolution(A, n, k, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1; 
        }
    }

    cout << ans << endl;

    return 0;
}