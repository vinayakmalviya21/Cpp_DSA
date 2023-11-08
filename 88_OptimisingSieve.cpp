// * Optimising Sieve of Eratosthenes

// The Sieve of Eratosthenes method is easy to use. We need to cancel all the multiples of each prime number beginning with 2 (including the number 1, which is not a prime or composite) and encircle the rest of the numbers.

#include <bits/stdc++.h>
using namespace std;

vector<bool> Sieve(int n)
{
    // Create a sieve array of N size telling isPrime
    vector<bool> sieve(n + 1, true);
    sieve[0] = sieve[1] = false;

    // for(int i=2;i<=n;i++){

    for(int i=2;i<=sqrt(n);i++) // Optimisation 2
    {
        if (sieve[i] == true)
        {

            // int j=i*2;

            int j = i * i; // Optimisation 1:
            // First unmarked no. would be i*i,as others have been marked by 2 to (i-1)

            while (j <= n)
            {
                sieve[j] = false;
                j += i;
            }
        }
    }
    return sieve;
}

int main()
{

    vector<bool> sieve = Sieve(25);
    for (int i = 0; i <= 25; i++)
    {
        if (sieve[i])
        {
            cout << i << " ";
        }
    }

    return 0;
}