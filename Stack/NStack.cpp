#include <iostream>
#include <stack>
using namespace std;

class Nstack
{
public:
    int *arr;
    int *top;
    int *next;

    int n, s;
    int freespot;

    Nstack(int n, int s)
    {
        this->n = n;
        this->s = s;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        // top ko initialize kar do
        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }

        // next ko initialize kar do
        for (int i = 0; i < s; i++)
        {
            next[i] = i + 1;
        }
        // update last index of next array
        next[s - 1] = -1;

        // initialoze freespot
        freespot = 0;
    }

    bool push(int x, int m)
    {
        // check for overflow
        if (freespot == -1)
        {
            return false;
        }

        // find index
        int index = freespot;
        // update freespot
        freespot = next[index];
        // insertelement
        arr[index] = x;
        // update next
        next[index] = top[m - 1];
        // update top
        top[m - 1] = index;

        return true;
    }

    int pop(int m)
    {
        // check for undrflow
        if (top[m - 1] == -1)
        {
            return -1;
        }

        int index = top[m - 1];
        top[m - 1] = next[index];
        next[index] = freespot;
        freespot = index;

        return arr[index];
    }
};