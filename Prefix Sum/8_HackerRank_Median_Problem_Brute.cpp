#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){

    ll n; cin>>n;

    vector<ll> arr(n+1, 0);
    for(ll i=1;i<=n;i++) cin>>arr[i];

    ll k; cin>>k;

    for(ll i=1;i<=n;i++){
        if(arr[i]>arr[k]) arr[i]=1;
        else if(arr[i]==arr[k]) arr[i]=0;
        else arr[i]=-1;    
    }

    vector<ll> pref(n+2, 0);
    for(ll i=1;i<=n;i++) pref[i]=pref[i-1]+arr[i];

    ll ans = 0;
    for(ll ep = k; ep <= n; ep++){
        ll mekoKyaChaaei = pref[ep];
        ll sp;
        if(ep%2==0) sp = 1;
        else sp = 0;
        while(sp<=k){
            if(pref[sp]==mekoKyaChaaei) ans++;
            sp+=2;
        }
    }
    cout<<ans<<endl;
}
/*
6
5 3 1 4 7 7
4

output - 4
*/