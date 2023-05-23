#include<iostream>
using namespace std;

int modularexponentiation(int x,int n,int m){
    int res=1;
    while(n>0){

        x=(x%m * x%m)%m;
        n=n>>1;
        if (n&1){
            res=(res*x%m)%m;
        }
    }
    return res;
}

int main(){
    int x,n,m;
    cout<<"Enter x,n and m:"<<endl;
    cin>>x>>n>>m;
    cout<<"The answer is :"<<modularexponentiation(x,n,m)<<endl;
}