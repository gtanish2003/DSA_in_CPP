#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cout << "Enter the number of rows and cols :" << endl;
    cin >> n >> m;

    int arr[10][10];

    cout << "Enter the elements in the array:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << " Wave print array is :" << endl;
    for (int j = 0; j < m; j++)
    {
        if (j % 2 != 0)
        {
            for (int i = n - 1; i >= 0; i--)
            {
                cout << arr[i][j] << " ";
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                cout << arr[i][j] << " ";
            }
        }
    }
}