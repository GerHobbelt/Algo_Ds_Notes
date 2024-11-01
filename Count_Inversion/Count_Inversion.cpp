// Count inversion using merge sort

#include "generic.h"

using namespace std;

//merge two sorted arrays such that resultant array is also sorted
int merge(int array[], int aux[], int low, int mid, int high)
{
    int x = low, y = mid, z = low, count = 0;

    // checking till left and right half of merge sort
    while ((x <= mid-1) && (y <= high)) 
    {
        if (array[x] <= array[y]) 
        {
            aux[z++] = array[x++];
        }
        else
        {
            aux[z++] = array[y++];
            count += mid-x;
        }
    }

    // Copy remaining elements
    while (x <= mid-1)
    {
        aux[z++] = array[x++];
    }
    
    while (y <= high) 
    {
        aux[z++] = array[y++];
    }

    // Sorting the original array with the help of aux array
    for (int i = low; i <= high; i++)
    {
        array[i] = aux[i];
    }
    return count;
}

//merge sort to find inversion count
int mergeSort(int array[], int aux[], int low, int high) 
{
    int count = 0;
    if (high > low)
    {
        int mid = (low + high) / 2;

        // merge sort on Left half of the array
        count = mergeSort(array, aux, low, mid);
        // merge sort on Right half of the array
        count += mergeSort(array, aux, mid + 1, high);
        // Merge the two half
        count += merge(array, aux, low, mid + 1, high);
    }
    return count;
}

//wrapper function that returns number of inversions
int inversions_count(int array[], int n) 
{
	vector<int> aux(n);
    return mergeSort(array, aux, 0, n-1);
}

int main ()
{       
    int n;
    cin >> n;
		vector<int> arr(n);
    for(int i = 0; i < n; i++)
    cin >> arr[i];
    cout << (inversions_count(arr, n)) << endl;
    return 0;
}

/* Sample input 
5
1 20 6 4 5

Sample Output
5 */
