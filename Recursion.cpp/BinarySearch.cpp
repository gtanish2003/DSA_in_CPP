#include <iostream>
using namespace std;

int binarysearch(int *arr, int s, int e, int key)
{
    if (s > e)
        return -1;

    int mid = s + (e - s) / 2;

    if (arr[mid] == key)
        return 1;

    if (arr[mid] > key)
        return (binarysearch(arr, s, mid - 1, key));

    if (arr[mid] < key)
        return (binarysearch(arr, mid + 1, e, key));

        return 1;
}

int main(){
    int arr[]={2,3,4,5,6,7,8,9};
    cout<<binarysearch(arr,0,8,5)<<endl;
    cout<<binarysearch(arr,0,8,90)<<endl;
}