#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value of the n:" << endl;
    cin >> n;

    int count = 0;
    vector<bool> primes(n + 1, true);
    primes[0] = primes[1] = false;

    for (int i = 2; i < n; i++)
    {
        if (primes[i])
        {
            count++;

            for (int j = 2 * i; j < n; j = j + i)
            {
                primes[j] = 0;
            }
        }
    }
    cout<<"The value of count is :"<<count<<endl;
}