#include<iostream>
using namespace std;

int main(){

    int arr[10]={10,2,3,16,3,7,23,65,12,14};
    int n=10;

    // Brute force approach
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if (arr[i]>arr[j]){
                count++;
            }
        }
    }
    cout<<"The count of inversions are:"<<count<<endl;
}
