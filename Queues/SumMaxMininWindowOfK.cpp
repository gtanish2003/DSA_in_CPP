#include <iostream>
#include <queue>
#include<vector>
using namespace std;

/*
// C++ program to find sum of all minimum and maximum
// elements Of Sub-array Size k.
#include<bits/stdc++.h>
using namespace std;

// Returns sum of min and max element of all subarrays
// of size k
int SumOfKsubArray(int arr[] , int n , int k)
{
	int sum = 0; // Initialize result

	// The queue will store indexes of useful elements
	// in every window
	// In deque 'G' we maintain decreasing order of
	// values from front to rear
	// In deque 'S' we maintain increasing order of
	// values from front to rear
	deque< int > S(k), G(k);

	// Process first window of size K
	int i = 0;
	for (i = 0; i < k; i++)
	{
		// Remove all previous greater elements
		// that are useless.
		while ( (!S.empty()) && arr[S.back()] >= arr[i])
			S.pop_back(); // Remove from rear

		// Remove all previous smaller that are elements
		// are useless.
		while ( (!G.empty()) && arr[G.back()] <= arr[i])
			G.pop_back(); // Remove from rear

		// Add current element at rear of both deque
		G.push_back(i);
		S.push_back(i);
	}

	// Process rest of the Array elements
	for ( ; i < n; i++ )
	{
		// Element at the front of the deque 'G' & 'S'
		// is the largest and smallest
		// element of previous window respectively
		sum += arr[S.front()] + arr[G.front()];

		// Remove all elements which are out of this
		// window
		while ( !S.empty() && S.front() <= i - k)
			S.pop_front();
		while ( !G.empty() && G.front() <= i - k)
			G.pop_front();

		// remove all previous greater element that are
		// useless
		while ( (!S.empty()) && arr[S.back()] >= arr[i])
			S.pop_back(); // Remove from rear

		// remove all previous smaller that are elements
		// are useless
		while ( (!G.empty()) && arr[G.back()] <= arr[i])
			G.pop_back(); // Remove from rear

		// Add current element at rear of both deque
		G.push_back(i);
		S.push_back(i);
	}

	// Sum of minimum and maximum element of last window
	sum += arr[S.front()] + arr[G.front()];

	return sum;
}

// Driver program to test above functions
int main()
{
	int arr[] = {2, 5, -1, 7, -3, -1, -2} ;
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 3;
	cout << SumOfKsubArray(arr, n, k) ;
	return 0;
}


*/





int solve(vector<int>v,int k){
    deque<int>d_max,d_min;
    int result=0;

    for(int i=0;i<v.size();i++){
        if (!d_max.empty()  &&  d_max.front()==i-k){
            d_max.pop_front();
        }

        if (!d_min.empty()   &&  d_min.front()==i-k){
            d_min.pop_front();
        }

        while(!d_max.empty()  &&   v[i]>v[d_max.back()]){
            d_max.pop_back();
        }

        while(!d_min.empty()   &&  v[i]<v[d_min.back()]){
            d_min.pop_back();
        }


        d_max.push_back(i);
        d_min.push_back(i);

        if (i>=k-1){
            cout<<"min="<<v[d_min.front()]<<" "<<"max="<<v[d_max.front()]<<" ";
            result+=v[d_max.front()]+v[d_min.front()];
        }
        cout<<endl;
    }

    return result;
}

int main(){
    vector<int>v={2,5,-1,7,-3,-1,-2};
    int k=4;
    cout<<"The final answer is"<<solve(v,k)<<endl;
}