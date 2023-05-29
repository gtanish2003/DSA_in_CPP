#include<iostream>
using namespace std;

void bubblesort(int *arr,int n){
    //Base Case
    if (n==0 || n==1)
    return;


    //Processing

    for (int i=0;i<n-1;i++){
        if (arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);

        }
    }
    //Recursive Call
     bubblesort(arr,n-1);


}

int main(){
    int arr[10];
    int n;
    cout<<"Enter the size of the array:"<<endl;
    cin>>n;
    cout<<"Enter the elements in the array:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    bubblesort(arr,n);

    cout<<"Your array after sorting is:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}