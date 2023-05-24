#include<iostream>
using namespace std;

int fib(int n){
    if (n==0)
    return 0;

    if (n==1)
    return 1;

    int ans=fib(n-2)+fib(n-1);
    return ans;

}

int main(){
    int n;
    cout<<"Enter the value of n:"<<endl;
    cin>>n;
    cout<<"The fibonacci of n is :"<<fib(n);
}