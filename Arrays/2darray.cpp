#include<iostream>
using namespace std;
int main(){
    int arr[3][3];
    cout<<"Enter the elements in the 2-d array :"<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
           cin>>arr[i][j];
        }
    }
     cout<<"Displaying the 2-d array:"<<endl;
     for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
           cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    int target;
    cout<<"Enter the target value to be searched:"<<endl;
    cin>>target;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if (arr[i][j]==target){
                cout<<"Element is found"<<endl;
            }
        }
    }



    
}
