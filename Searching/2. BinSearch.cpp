#include <bits/stdc++.h>
using namespace std;

int BinarySearchREC(int arr[], int l, int r, int item)
{
    int mid = (l + r + 1) / 2;
    if (l <= r)
    {
        if (arr[mid] == item)
            return mid;

        if (arr[mid] > item)
            return BinarySearchREC(arr, l, mid - 1, item);

        if (arr[mid] < item)
            return BinarySearchREC(arr, mid + 1, r, item);
    }
    return -1;
}
int BinarySearchITER(int arr[], int l, int r, int item)
{

    while (l <= r)
    {
        int mid = (l + r + 1) / 2;
        if (arr[mid] == item)
            return mid;

        if (arr[mid] > item)
        {
            r = mid - 1;
        }

        if (arr[mid] < item)
        {
            l = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 5, 5, 7, 9, 10, 11, 12, 14, 15, 16};
    int size = sizeof(arr) / sizeof(arr[0]);
    int ele = 1;
    int foundAt = BinarySearchITER(arr, 0, size - 1, ele);
    cout << "Element " << ele << " found at index:" << foundAt;
}