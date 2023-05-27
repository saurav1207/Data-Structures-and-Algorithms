// 1 2 3 1 3 4 agar yaaha koi pair exit 
// https://pastebin.com/z4eBwG1F


#include<bits/stdc++.h>
using namespace std;

void pairSum(){
    int n; cin>>n;
    vector<int> arr(n, 0);
    for(int i=0;i<n;i++) cin>>arr[i];
    int target; cin>>target;
 
    map<int, int> freq;
    for(int i=0;i<n;i++){
        if(freq.count(target-arr[i])){
            cout<<"YES"<<endl;
            return;
        }
        if(freq.count(arr[i])){
            freq[arr[i]]++;
        }
        else{
            freq[arr[i]]=1;
        }
    } 
    cout<<"NO"<<endl;
}


int main(){
    pairSum();
    return 0;
}