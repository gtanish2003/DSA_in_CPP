#include<iostream>
using namespace std;

bool issorted(int *arr ,int size){
    if (size==0||size==1){
        return true;
    }
    if (arr[0]>arr[1]){
        return false;

    }
    else{
        bool reaminingPart=issorted(arr+1,size-1);
        return reaminingPart;

    }
}

int main(){
    int arr[10];
    int n;
    cout<<"Enter the value of n:"<<endl;
    cin>>n;
    cout<<"Enter the elements in the array:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];

    }
    cout<<issorted(arr,n);
}