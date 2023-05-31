#include<iostream>
#include<map>
using namespace std;

int main(){
    int n;
    cin>>n;
    map<int ,int>mp;
    int maxi=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        mp[x]++;
        if (mp[x]>mp[maxi])
        maxi=x;
    }
   cout<<maxi<<endl;
}