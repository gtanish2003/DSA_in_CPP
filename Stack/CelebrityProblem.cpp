#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool knows(vector<vector<int>> &M, int a, int b, int n)
{
    if (M[a][b] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int celebrity(vector<vector<int>> &M, int n)
{
    stack<int> s;

    // step-1.Put all elements in the stack
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    // step-2.  Get two lements  and comapre them
    while (s.size() > 1)
    {
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if (knows(M, a, b, n))
        {
            s.push(b);
        }
        else
        {
            s.push(a);
        }
    }

    // step-3. single element in stack is potential celebrity
    // so lets verify it with the two condition given in the question

    int candidate = s.top();

    // rowcheck
    bool rowCheck = false;
    int zeroCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (M[candidate][i] == 0)
        {
            zeroCount++;
        }
    }

    if (zeroCount == n)
    {
        rowCheck = true;
    }

    // columns check

    bool colCheck = false;
    int oneCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (M[i][candidate] == 1)
        {
            oneCount++;
        }
    }

    if (oneCount == n - 1)
    {
        colCheck = true;
    }

    if (rowCheck == true && colCheck == true)
    {
        return candidate;
    }
    else
    {
        return -1;
    }
}