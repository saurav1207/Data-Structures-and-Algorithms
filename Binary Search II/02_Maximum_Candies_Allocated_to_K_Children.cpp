#include<bits/stdc++.h>
#define ll long long int 
using namespace std;

void candiesAllocate(){
    ll n; cin>>n;

    vector<ll>arr(n,0);
    for(ll i=0; i<n; i++) cin>>arr[i];

    ll k; cin>>k;

    ll lo = 1, hi = 1e15, ans = 0;
    while(lo <= hi){
        ll mid = (lo + hi)/2;

        ll totalKitniPilesBanaSaktaHuJismeMidCandiesHo = 0;

        for(auto itr : arr){
            totalKitniPilesBanaSaktaHuJismeMidCandiesHo += (itr/mid);
        }
        if(totalKitniPilesBanaSaktaHuJismeMidCandiesHo>=k){
            ans = mid;
            lo = mid+1;
        }
        else{
            hi = mid - 1;
        }
    }
    cout<<ans;
}
int main(){
    candiesAllocate();
    return 0;
}