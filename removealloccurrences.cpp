#include<iostream>
#include<string>
using namespace std;

int main(){
    string str;
    cout<<"Enter the input string"<<endl;
    getline(cin,str);
    string part;
    cout<<"Enter the part of the string to be removed"<<endl;
    getline(cin,part);
    while(str.length()!=0  &&  str.find(part)<str.length()){
        str.erase(str.find(part),part.length());
    }

    cout<<str;
}
