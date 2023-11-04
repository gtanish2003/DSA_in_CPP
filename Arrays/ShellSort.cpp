#include <iostream>  
using namespace std;  
 void shellSort(int arr[], int n) {  
    // Calculate the gap sequence  
    for (int gap = n/2; gap > 0; gap /= 2) {  
        // Perform an insertion sort on each subarray  
        for (int i = gap; i< n; i++) {  
            int temp = arr[i];  
            int j;  
            for (j = i; j >= gap &&arr[j - gap] > temp; j -= gap) {  
arr[j] = arr[j - gap];  
            }  
arr[j] = temp;  
        }  
    }  
}  
  
int main() {  
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};  
    int n = sizeof(arr)/sizeof(arr[0]);  
shellSort(arr, n);  
cout<< "Sorted array: ";  
    for (int i = 0; i< n; i++) {  
cout<<arr[i] << " ";  
    }  
    return 0;  
}  