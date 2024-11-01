#include "generic.h"

using namespace std;

void SieveOfEratosthenes(int n)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
	vector<bool> prime(n + 1);

    for(int p = 2; p*p <= n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if(prime[p] == true)
        {
            // Update all multiples of p
            for(int i = p*2; i <= n; i += p)
                prime[i] = false;
        }
    }

    // Print all prime numbers
    for(int p = 2; p <= n; p++)
       if(prime[p])
          cout << p << " ";
}

// Program to test above function
int main()
{
    int n = 30;
    cout << "Following are the prime numbers smaller than or equal to " << n << endl;
    SieveOfEratosthenes(n);
    return 0;
}

/*

Following are the prime numbers smaller than or equal to 30
2 3 5 7 11 13 17 19 23 29

*/
