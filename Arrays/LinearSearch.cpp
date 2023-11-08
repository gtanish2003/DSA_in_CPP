// linear search code
#include <iostream>
using namespace std;
int main()
{
    int n, i, key;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of array: ";
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the key element: ";
    cin >> key;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            cout << "Element found at index " << i << endl;
            break;
        }
    }
    if (i == n)
    {
        cout << "Element not found" << endl;
    }
    return 0;
}