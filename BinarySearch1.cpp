#include<iostream>
using namespace std;

int binarysearch(int arr[3][4],int target){
    int start=0;
    int row=3;
    int col=4;
    int end=row*col-1;
    int mid=start+(end-start)/2;
    while(start<=end){
        int element=arr[mid/col][mid%col];
        if (element==target){
            return 1;

        }
        else if (element<target){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
  return 0;
}
int main(){
    int arr[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int ans=binarysearch(arr,20);
    cout<<ans;
}