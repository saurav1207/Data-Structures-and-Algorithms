#include <bits/stdc++.h>
#define ll long long int 
using namespace std;

void lenOfLongSubarr(){
    ll n; cin >> n;

    vector<ll> arr(n + 1, 0);
    for (ll i = 1; i <= n; i++) cin >> arr[i];

    vector<ll> pref(n + 1, 0);
    for (ll i = 1; i <= n; i++){
        pref[i] = pref[i - 1] + arr[i];
    }

    ll K; cin >> K; // sum that we want to find 

    ll maxLength = 0;
    unordered_map<ll, ll> prefixSum; 

    for (ll i = 1; i <= n; i++){
        ll currentSum = pref[i];
        ll targetSum = currentSum - K;

        if (prefixSum.find(targetSum) != prefixSum.end()){
            maxLength = max(maxLength, i - prefixSum[targetSum]);
        }

        if (prefixSum.find(currentSum) == prefixSum.end()){
            prefixSum[currentSum] = i;
        }
    }

    cout << maxLength << endl;
}

int main(){
    lenOfLongSubarr();
    return 0;
}
