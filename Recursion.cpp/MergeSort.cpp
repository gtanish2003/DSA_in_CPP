#include <iostream>
using namespace std;

void merge(int *arr, int s, int e)
{
    int mid = s + (e - s) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *arr1 = new int[len1];
    int *arr2 = new int[len2];

    // Copy Values
    int k = s;
    for (int i = 0; i < len1; i++)
    {
        arr1[i] = arr[k++];
    }

    k = mid + 1;

    for (int i = 0; i < len2; i++)
    {
        arr2[i] = arr[k++];
    }

    // Merge two sorted arrays

    int i = 0;
    int j = 0;
    k = s;

    while (i < len1 && j < len2)
    {
        if (arr1[i] < arr2[j])
        {
            arr[k++] = arr1[i++];
        }
        else
        {
            arr[k++] = arr2[j++];
        }
    }

    while (i < len1)
    {
        arr[k++] = arr1[i++];
    }

    while (j < len2)
    {
        arr[k++] = arr2[j++];
    }
}

void mergesort(int *arr, int s, int e)
{
    int mid = s + (e - s) / 2;

    // Base condition
    if (s >= e)
        return;
    // Recursive call
    mergesort(arr, s, mid);
    mergesort(arr, mid + 1, e);

    merge(arr, s, e);
}

int main()
{
    int n;
    cout << "Enter the value of n:" << endl;
    cin >> n;
    int arr[10];

    cout << "Enter the elements in the array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    mergesort(arr, 0, n - 1);

    cout << "Array after sorting is :" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " " << endl;
    }
}
