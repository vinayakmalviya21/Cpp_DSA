#include <iostream>
using namespace std;

// ! Factorial
// int factorial(int n)
// {

//     if (n == 1)
//     {
//         return 1;
//     }

//     int ans = n * factorial(n - 1);
//     return ans;
// }

// ! Counting
// void printCounting(int n)
// {
//     if (n == 0)
//     {
//         return;
//     }

//     cout << n << " ";

//     printCounting(n - 1);
// }

// ! Fibonacci series
int fib(int n)
{
    if (n == 1)
    {
        return 0;
    }

    if (n == 2)
    {
        return 1;
    }
    int ans = fib(n - 1) + fib(n - 2);
    return ans;
}

int main()
{
    // * Recursion -> when function call itself

    int n;
    cout << "Enter value of n: ";
    cin >> n;

    // ! Factorial
    // int ans = factorial(n);
    // cout << "Answer is: " << ans;

    // ! Counting
    // printCounting(n);

    // ! Fibonacci series
    int ans = fib(n);
    cout << n << "th term is: " << ans << endl;

    return 0;
}