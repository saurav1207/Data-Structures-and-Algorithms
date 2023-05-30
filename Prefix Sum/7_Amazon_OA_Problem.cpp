#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){

    ll numberOfBulbs, noOfPositions;
    cin>>numberOfBulbs>>noOfPositions;

    vector<ll> pos(numberOfBulbs, 0), power(numberOfBulbs, 0);
    for(ll i=0;i<numberOfBulbs;i++) cin>>pos[i];
    for(ll i=0;i<numberOfBulbs;i++) cin>>power[i];

    vector<ll> arr(noOfPositions+2, 0);
    for(ll i=0;i<numberOfBulbs;i++){
        ll L = max(1ll, pos[i]-power[i]);
        ll R = min(noOfPositions, pos[i]+power[i]);
        arr[L]+=1;
        arr[R+1]-=1;
    }

    vector<ll> pref(noOfPositions+2, 0);
    ll noOfZeroes = 0;
    for(ll i=1;i<=noOfPositions;i++){
        pref[i]=pref[i-1]+arr[i];
        if(pref[i]==0) noOfZeroes++;
        cout<<pref[i]<<" ";
    }
    cout<<endl;
    cout<<noOfZeroes<<endl;
}
/*
4  
12
1 5 7 8
1 2 1 1
1 1 1 1 1 2 3 2 1 0 0 0 
3
*/