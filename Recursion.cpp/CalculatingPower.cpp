#include<iostream>
using namespace std;

int power(int a,int b){

    //Base Case
    if (b==0)
    return 1;
    if (a==1)
    return 1;

    //Recursive Call

    int ans=power(a,b/2);
    if (b%2==0){
        return ans*ans;
    }
    else{
        return a*ans*ans;
    }


}

int main(){
    int a,b;
    cout<<"Enter the values of a and b:"<<endl;
    cin>>a>>b;
    cout<<"The answer is "<<power(a,b)<<endl;
    
}