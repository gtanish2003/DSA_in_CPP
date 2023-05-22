#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int row = arr.size();
    int col = arr[0].size();
    int count = 0;
    int total = row * col;
    // Index initialization

    int startingRow = 0;
    int endingRow = row - 1;
    int startingColumn = 0;
    int endingColumn = col - 1;

    // Main logic
    while (count < total)
    {
        // Printing starting Row
        for (int index = startingColumn; count < total && index <= endingColumn; index++)
        {
            cout << arr[startingRow][index];
            count++;
        }
        startingRow++;
        // Print last column
        for (int index = startingRow; count < total && index <= endingRow; index++)
        {
            cout << arr[index][endingColumn];
            count++;
        }
        endingColumn--;
        // Print last Row
        for (int index = endingColumn; count < total && index >= startingColumn; index--)
        {
            cout << arr[endingRow][index];
            count++;
        }
        endingRow--;
        // Print starting column
        for (int index = endingRow; count < total && index >= startingRow; index--)
        {
            cout << arr[index][startingColumn];
            count++;
        }
        startingColumn++;
    }
}