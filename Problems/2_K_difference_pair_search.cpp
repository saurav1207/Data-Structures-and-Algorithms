// given an array of integers of length pairing (a,b) a-b >= k
// max no of pair which you can form such in each pair the diff is greater than equal to k


#include<bits/stdc++.h>
using namespace std;

#define ll long long int
int main(){
    // freopen("input.txt", "r" ,stdin);
    // freopen("output.txt", "w" ,stdout);

    ll n, k; cin>>n>>k;
    vector<ll> arr(n, 0);
    for(ll i=0;i<n;i++) cin>>arr[i];
    sort(arr.begin(), arr.end());

    ll lo = 0, hi = n/2, ans = -1;
    while(lo<=hi){
        ll mid = (lo+hi)/2;

        ///mid pairs ban sakte hai ya nahi
        vector<ll> firstMid, lstMid;
        for(ll i=0;i<mid;i++) firstMid.push_back(arr[i]);
        for(ll i=n-mid;i<n;i++) lstMid.push_back(arr[i]);
        bool sabkaDifferenceKSeBadaHai = true;
        for(ll i=0;i<firstMid.size();i++){
            if(abs(firstMid[i]-lstMid[i])<k) sabkaDifferenceKSeBadaHai = false;
        }
        if(sabkaDifferenceKSeBadaHai){
            ans = mid;
            lo  =  mid+1;
        }
        else{
            hi = mid-1;
        }
    }
    cout<<ans<<endl;
}