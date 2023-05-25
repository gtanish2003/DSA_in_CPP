#include<iostream>
using namespace std;

int linearsearch(int *arr, int size, int key){
    if (arr[0]==key)
    return 1;

    else{
        linearsearch(arr+1,size-1,key);

    }
    return -1;

}

int main(){
    int arr[]={2,5,1,3,6,8};
    cout<<linearsearch(arr,6,2)<<endl;
    cout<<linearsearch(arr,6,0)<<endl;
}