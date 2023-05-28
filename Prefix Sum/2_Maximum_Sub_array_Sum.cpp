#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    ll n; 
    cout<<"Enter the size: ";
    cin>>n;

    vector<ll> arr(n+1, 0);
    cout<<"Enter the element of array: ";
    for(ll i=1;i<=n;i++) cin>>arr[i];

    vector<ll> pref(n+1, 0);
    for(ll i=1;i<=n;i++) pref[i]=pref[i-1]+arr[i];

    ll minPrefixSum = 0, ans = -1e18;

    // Printign the sub array 
    ll minPrefixSumKahaMila = 0, L = -1, R = -1;

    for(ll i=1;i<=n;i++){
        ll ispeKitnaMaximumHai = pref[i]-minPrefixSum;
        // ans = max(ans, ispeKitnaMaximumHai);
        if(ispeKitnaMaximumHai>ans){
            ans = ispeKitnaMaximumHai;
            L = minPrefixSumKahaMila + 1;
            R = i;
        }
        if(pref[i]<minPrefixSum){
            minPrefixSum = pref[i];
            minPrefixSumKahaMila = i;
        }
    }
    cout<<ans<<endl;
    for(ll i=L;i<=R;i++) cout<<arr[i]<<" ";
    cout<<endl;
}
