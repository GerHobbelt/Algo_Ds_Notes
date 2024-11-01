/*
    LONGEST INCREASING SUBARRAY

    The task is to find a subarray from a given array having the maximum length
    such that the elements of the subarray are in ascending order.
*/

#include "generic.h"

using namespace std;

/*
    Approach : If the current element is greater than the last element, we 
               update the length variable, so as to keep a counter of the 
               maximum numbers in the current longest increasing subarray.
               The mx variable keeps the track of the maximum length across
               all increasing subarrays found.
               The max_index denotes the starting index of the longest 
               increasing subarray found.
               We reset the length to 1 whenever the current element is found
               to be lesser than the previous element.
*/

int mx = 0;
int ln = 1;
int max_index = 0;

void solve(int a[], int n) {
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            ln++;
            continue;
        }
        if (mx < ln) {
            mx = ln;
            max_index = i - mx;
        }
        ln = 1;
    }
    if (mx < ln) {
        mx = ln;
        max_index = n - mx;
    }
    for (int i = max_index; i < mx + max_index; i++) {
        cout << a[i] << " ";
    }
}

int main() {
    int num;
    cin >> num;
		vector<int> arr(num);
    for (int i = 0; i < num; i++) {
        cin >> arr[i];
    }
    solve(arr, num);
    return 0;
}

/*
    Input: array : {1,14,2,1,7,11,16,18,4,6}
    Output: 1 7 11 16 18 
    Verification: 1 7 11 16 18 is the longest increasing subarray of the 
                  given array with length 5.
*/
