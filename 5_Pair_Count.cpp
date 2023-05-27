// 9KwSqqkF

#include<bits/stdc++.h>
using namespace std;

void pairCount(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    vector<int>arr(n,0);
    cout<<"Enter the elements of array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int target;
    cout<<"Enter the target: ";
    cin>>target;


    map<int,int> freq;
    int pairCount=0;

    for(int i=0; i<n; i++){
        if(freq.count(target - arr[i])){
            pairCount+=freq[target-arr[i]];
        }
        freq[arr[i]]++;
    }
    cout<<pairCount<<endl;
}
int main(){
    pairCount();
    return 0;
}