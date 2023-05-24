#include<iostream>
using namespace std;

int getsum(int *arr,int size){
    if (size==0)
    return 0;
    if (size==1)
    return arr[0];
   else{
    int remainingPartsum=getsum(arr+1,size-1);
    int sum=arr[0]+remainingPartsum;
    return sum;
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
    int ans=getsum(arr,n);
    cout<<"The sum of the elements in the array:"<<ans;
}