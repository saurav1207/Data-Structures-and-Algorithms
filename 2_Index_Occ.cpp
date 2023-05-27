/*
https://pastebin.com/5W8Xs8f5
nsutianrahman@gmail.com
*/


#include<bits/stdc++.h>
using namespace std;

int main(){
    map<int,int> mp;

    int a[]={1,3,2,4,5,1,2,5};
    int n=sizeof(a)/sizeof(int);

    for(int i=0; i<n; i++){
        if(!mp.count(a[i])){
            mp[a[i]]=i;
        }
    }

    for(auto itr: mp){
        cout<<itr.first<<" "<<itr.second<<endl;
    }
}