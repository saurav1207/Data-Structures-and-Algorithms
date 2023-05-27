#include<bits/stdc++.h>
using namespace std;

// 6M1cH7VF

#define ll long long int
void prefixSumIntro(){
    int n; cin>>n;
    vector<int> arr(n+1, 0);
    for(int i=1;i<=n;i++) cin>>arr[i];
 
    vector<ll> pref(n+1, 0);
    for(ll i=1;i<=n;i++){
        pref[i]=pref[i-1]+arr[i];
    }
 
    ll q; cin>>q;
    for(ll i=0;i<q;i++){
        ll l, r; cin>>l>>r;
        cout<<pref[r]-pref[l-1]<<endl;
    }
}

int main(){
    prefixSumIntro();
    return 0;
}

/*
7

1 2 2 -3 4 3 2 4

1 2
3 4




*/