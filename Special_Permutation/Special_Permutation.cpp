/*
SPECIAL PERMUTATION

A Special Permutation is a permutation of n numbers such that there 
are at-least (n - k) indices where the value is equal to the index
of that number.
*/

#include "generic.h"

using namespace std;

int mod = 1000000007;

int nCr(int n, int r, int mod) {
    if (n < r) {
        return -1;
    }
    // We create a pascal triangle.
		vector<int> Pascal(r + 1);
    Pascal[0] = 1;
    for (int i = 1; i <= r; i++) {
        Pascal[i] = 0;
    }
    
    // We use the known formula nCr = (n-1)C(r) + (n-1)C(r-1) for computing the values.
    for (int i = 1; i <= n; i++) {
        int k = (i < r) ? (i) : (r); 
        // we know, nCr = nC(n-r). Thus, at any point we only need min
        for (int j = k; j > 0; j--) { 
            // of the two, so as to improve our computation time.
            Pascal[j] = (Pascal[j] + Pascal[j - 1]) % mod;
        }
    }
    return Pascal[r];
}

int dearrangement[10000];

int count(int number) {
    dearrangement[0] = 1;
    dearrangement[1] = 0;
    dearrangement[2] = 1;

    for (int i = 3; i <= number; i++) {
        dearrangement[i] = (i - 1) * 
        (dearrangement[i - 1] + dearrangement[i - 2]);
    }
    return dearrangement[number];
}

int special_permutation(int n, int k) {
    int ans = 0;
    for (int i = n - k; i <= n; i++) {
        ans += (nCr(n, i, mod) * count(n - i));
    }
    return ans;
}

int main() {
    int number;
    cin >> number;
    int k;
    cin >> k;
    int special = special_permutation(number, k);
    cout << "The number of special permutations is " << special;
}

/*
INPUT :
n = 7
k = 3
OUTPUT :
The number of special permutations is 92
*/
