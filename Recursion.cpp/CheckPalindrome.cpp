#include<iostream>
using namespace std;

void stringreversal(string &str,int i,int j){
    if (i>j)
    return ;

    swap(str[i],str[j]);
    i++;
    j--;
    stringreversal(str,i,j);
    

}

int main(){
    string str;
    cout<<"Enter the string to check whethet it is an palindrome or not"<<endl;
    cin>>str;
    string copy=str;

    int i=0;
    int j=str.length()-1;
    stringreversal(str,i,j);
    if (copy==str){
        cout<<"Yes it is a paindrome!!"<<endl;

    }
    else{
        cout<<"Not a paindrome!!"<<endl;
    }
}