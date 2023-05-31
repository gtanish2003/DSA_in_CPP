#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the value of the n:"<<endl;
    cin>>n;
    for(int i=2;i<n;i++){
        if (n%i==0){
            cout<<"No is not prime"<<endl;
            break;
        }
    }
}