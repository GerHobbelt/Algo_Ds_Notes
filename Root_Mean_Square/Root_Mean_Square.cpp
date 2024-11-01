/*
ROOT MEAN SQUARE

Root Mean Square or RMS is known as quadratic mean of a given array.
It holds a lot of importance in mathematical calculations in various
domains like Physics and geometry.
*/

#include "generic.h"

using namespace std;

void RMS(int a[], int n, int index, int ans) {
    if (index == n) {
        ans = ans / n;
        cout << "RMS of array is : " << ans;
        return;
    }
    ans = ans + a[index] * a[index];
    RMS(a, n, index + 1, ans);
}

int main() {
    int n;
    cin >> n;
		vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    RMS(a, n, 0, 0);
}

/*
INPUT : n = 3
        a = [3, 15, 32]
OUTPUT :
RMS of array is : 419
*/
