
#include<bits/stdc++.h>
#define ll long long int 
using namespace std;

void kokoEatingBananas(){
    ll n; cin>>n;

    vector<ll>arr(n,0);
    for(ll i=0; i<n; i++) cin>>arr[i];

    ll h; cin>>h; // guard

    ll lo = 1, hi = 1e18, ans = 0;
    // ceil(x/y)=(x+y-1)/y;

    while(lo<=hi){
        ll mid = (lo+hi)/2;
        ll kitneGhanteLagenge = 0;
        for(auto itr : arr){
            kitneGhanteLagenge+=(itr+mid-1)/mid;
            // ceil(x/y)=(x+y-1)/y;
        }
        if(kitneGhanteLagenge>h){
            lo = mid+1;
        }
        else{
            ans = mid;
            hi = mid-1;
        }
    }
    cout<<ans;
}

int main(){
    kokoEatingBananas();
    return 0;
}
