#include <bits/stdc++.h>
using namespace std;
int limit = 10000;
vector<bool> mark(limit + 1, true);
void sieve(int limit, vector<int> &prime)
{

    mark[0] = mark[1] = false;
    for (int i = 2; i < limit; i++)
    {
        if (mark[i])
        {
            for (int j = 2 * i; j < limit; j = j + i)
            {
                mark[j] = false;
            }
        }
    }
}

vector<int> generatePrimes(int n)
{
    vector<int> ds;
    for (int i = 2; i < n; i++)
    {
        if (mark[i])
        {
            ds.push_back(i);
        }
    }
    return ds;
}

int main()
{
    int l, r;
    cout << "Enter the lower and higher range:" << endl;
    cin >> l >> r;

    // STEP1: Generate all primes till sqrt(r)
    vector<int> primes = generatePrimes(sqrt(r));

    // STEP:2 Create a dummy array of size r-l+1 and make everyone as 1
    int dummy[r - l + 1];
    for (int i = 0; i < r - l + 1; i++)
    {
        dummy[i] = 1;
    }

    // SREP:3 For all primes amrks its multiples 0
    for (auto pr : primes)
    {
        int firstMultiple = (l / pr) * pr;
        if (firstMultiple < l)
        {
            firstMultiple += pr;
        }

        for (int j = max(firstMultiple, pr * pr); j <= r; j += pr)
        {
            dummy[j - l] = 0;
        }
    }

    // STEP:4 Get all the primes
    for (int i = l; i <= r; i++)
    {
        if (dummy[i - l] == 1)
        {
            cout << i << " ";
        }
    }
}
