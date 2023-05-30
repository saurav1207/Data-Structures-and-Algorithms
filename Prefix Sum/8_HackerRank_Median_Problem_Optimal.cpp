#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    // freopen("input.txt", "r" ,stdin);
    // freopen("output.txt", "w" ,stdout);

    ll n; cin>>n;

    vector<ll> arr(n+1, 0);
    for(ll i=1;i<=n;i++) cin>>arr[i];

    ll k; cin>>k;

    // Finding Median 
    for(ll i=1;i<=n;i++){
        if(arr[i]>arr[k]) arr[i]=1;
        else if(arr[i]==arr[k]) arr[i]=0;
        else arr[i]=-1;    
    }

    // Prefixsum --> O(1) per query
    vector<ll> pref(n+2, 0);
    for(ll i=1;i<=n;i++) pref[i]=pref[i-1]+arr[i];

    // Optimality Logic
    map<ll,ll> hmOdd, hmEven;
    for(ll i=0;i<=k;i+=2) hmEven[pref[i]]++;
    for(ll i=1;i<=k;i+=2) hmOdd[pref[i]]++;
   
    ll ans = 0;

    for(ll ep = k; ep <= n; ep++){
        ll mekoKyaChaaei = pref[ep];
        if(ep%2==0) ans+=hmOdd[mekoKyaChaaei];
        else ans+=hmEven[mekoKyaChaaei];
    }
    cout<<ans<<endl;
}

// Time Complexity - O(n).log(n)