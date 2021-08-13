#include <bits/stdc++.h>
using namespace std;

int LinearSearch(int arr[], int n, int item)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == item)
            return i;
    }
    return -1;
}

int main()
{
    int arr[] = {1, 3, 5, 6, 7, 2, 5, 76, 2, 4, 2, 6, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    int foundAt = LinearSearch(arr, size, 6);
    cout << "Element 6 found at " << foundAt;
}