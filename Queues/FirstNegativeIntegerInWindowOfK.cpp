#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> PrintFirstNegativeInteger(int a[], int n, int k)
{
    deque<int> dq;
    vector<int> ans;

    // process first window of k size
    for (int i = 0; i < k; i++)
    {
        if (a[i] < 0)
        {
            dq.push_back(i);
        }
    }

    // store answer of first k sized window
    if (dq.size() > 0)
    {
        ans.push_back(a[dq.front()]);
    }
    else
    {
        ans.push_back(0);
    }

    // process for remaining elements
    for (int i = k; i < n; i++)
    {
        // removal
        if (!dq.empty() && i - dq.front() >= k)
        {
            dq.pop_front();
        }

        // addition
        if (a[i] < 0)
        {
            dq.push_back(i);
        }

        // ans store
        if (dq.size() > 0)
        {
            ans.push_back(a[dq.front()]);
        }
        else
        {
            ans.push_back(0);
        }

        return ans;
    }
}


/*





OPTIMIZED APPROACH




// C++ code for First negative integer
// in every window of size k
#include <iostream>
using namespace std;

void printFirstNegativeInteger(int arr[], int k, int n)
{
	int firstNegativeIndex = 0;
	int firstNegativeElement;

	for (int i = k - 1; i < n; i++) {

		// skip out of window and positive elements
		while ((firstNegativeIndex < i)
			&& (firstNegativeIndex <= i - k
				|| arr[firstNegativeIndex] >= 0)) {
			firstNegativeIndex++;
		}

		// check if a negative element is found, otherwise
		// use 0
		if (arr[firstNegativeIndex] < 0) {
			firstNegativeElement = arr[firstNegativeIndex];
		}
		else {
			firstNegativeElement = 0;
		}
		cout << firstNegativeElement << " ";
	}
}

// Driver code
int main()
{
	int arr[] = { 12, -1, -7, 8, -15, 30, 16, 28 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 3;
	printFirstNegativeInteger(arr, k, n);
}
*/
