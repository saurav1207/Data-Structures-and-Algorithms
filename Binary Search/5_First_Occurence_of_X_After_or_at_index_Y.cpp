#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    // freopen("input.txt", "r" ,stdin);
    // freopen("output.txt", "w" ,stdout);

    ll n; cin>>n;

    vector<ll> arr(n, 0);
    for(ll i=0;i<n;i++) cin>>arr[i];

    map<ll,vector<ll>> occ;
    for(ll i=0;i<n;i++){
        occ[arr[i]].push_back(i);
    }  

    ll q; cin>>q;
    while(q--){
        ll x, y; cin>>x>>y;
        ll lo = 0, hi = ((ll)occ[x].size())-1;
        ll ans = -1;
        while(lo<=hi){
            ll mid = (lo+hi)/2;
            if(occ[x][mid]<y){
                lo = mid+1;
            }
            else{
                ans = occ[x][mid];
                hi = mid-1;
            }
        }
        cout<<ans<<endl;
    }
}

/*
8
2 5 3 2 1 3 5 2
3 --> queries
2 5
3 7
5 9

*/