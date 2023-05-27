// https://pastebin.com/6ke8QHz9

#include<bits/stdc++.h>
using namespace std;

int main(){
    // int a[] ={1,2,3,4,1,1,2};
    // int n=sizeof(a)/sizeof(int);
    int n;
    cin>>n;

    vector<int>a(n,0);
    cout<<"Enter the elements: ";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    map<int, int> mp;
    for(int i=0; i<n; i++){
        if(mp.count(a[i])){
            mp[a[i]]++;
        }else{
            mp[a[i]]=1;
        }
    }

    for(auto itr: mp){
        cout<<itr.first<<" has a frequency of: "<<itr.second<<endl;
    }
}