// Given an array of integers, find the number of pairs (a, b) which sums up to given number K.

#include<bits/stdc++.h>
#define ll long long int 
using namespace std;

void nestedLoop(){
    ll n; cin >> n;

    vector<ll> arr(n); 
    for(ll i = 0; i < n; i++) cin >> arr[i];

    ll target; cin >> target;

    ll count = 0;
    for(ll i = 0; i < n; i++){
        for(ll j = i + 1; j < n; j++){
            if(arr[i] + arr[j] == target){
                count++;
            }
        }
    }
    cout << count;
}

void twoPointer(){
       ll n;
    cin >> n;

    vector<ll> arr(n, 0);
    for (ll i = 0; i < n; i++) cin >> arr[i];

    ll target;
    cin >> target;

    sort(arr.begin(), arr.end());

    ll lo = 0, hi = n - 1, count = 0;
    while (lo < hi) {
        if (arr[lo] + arr[hi] == target) {
            count++;
            lo++;
            hi--;
        } else if (arr[lo] + arr[hi] < target) {
            lo++;
        } else {
            hi--;
        }
    }
    cout << count;
}
int main(){
    // nestedLoop();
    twoPointer();
    return 0;
}
