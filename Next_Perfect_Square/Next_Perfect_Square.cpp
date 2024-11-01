/*
NEXT PERFECT SQUARE

A perfect square is a number which can be expressed as a product of 
two equal numbers. The task is to find the first such number greater 
than the given number.
*/

#include "generic.h"

using namespace std;

int main() {
    float n;
    cout << "Enter N: ";
    cin >> n;
    int x = floor(sqrt(n)) + 1;
    cout << "The next perfect square is " << (x * x) << endl;
}

/*
    INPUT : n = 1091
    OUTPUT: The next perfect square is 1156
    VERIFICATION : 1156 = 34 * 34
                   Hence it is a perfect square.
*/
