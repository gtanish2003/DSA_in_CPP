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
    string str="Tanish Gupta";
    int i=0;
    int j=str.length()-1;
    stringreversal(str,i,j);
    cout<<str<<endl;
}