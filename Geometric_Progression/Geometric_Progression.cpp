/*
        GEOMETRIC PROGRESSION

        Any sequence of elements where the quotient between any two
        consecutive elements is equal is termed to be in G.P.
        The nth term of an G.P. is defined as (a * r^(n-1))
        where a is the first element of the G.P.
        r is the common ratio of the G.P.
*/

#include "generic.h"

using namespace std;

int sumOfGP (int a, int r, int n) 
{ 
    int sum = 0; 
    for (int i = 0; i < n; i++) 
    { 
        sum = sum + a; 
        a = a * r; 
    } 
    return sum; 
}

int main() {
    cout << "Enter the First Term of G.P.";
    int a;
    cin >> a;
    cout << "Enter the common ratio";
    int r;
    cin >> r;
    cout << "Enter N (The index of term to find)";
    int n;
    cin >> n;
    cout << "The term at index " << n << " is " << (a * pow(r, n - 1));
    cout << "\nSum is: " << sumOfGP(a, r, n);
}

/*
    INPUT : a = 5
            r = 2
            n = 7
    OUTPUT : The term at index 7 is 320
             Sum is: 635
    VERIFICATION : The G.P. would be 5,10,20,40,80,160,320...
*/
