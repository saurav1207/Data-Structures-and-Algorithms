#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void countSubarraysWithTargetSum() {
    ll n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<ll> arr(n + 1, 0);
    cout << "Enter the elements of the array: ";
    for (ll i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    ll targetSum;
    cout << "Enter the target sum: ";
    cin >> targetSum;

    vector<ll> pref(n + 1, 0);
    for (ll i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + arr[i];
    }

    map<ll, ll> mp;
    mp[0] = 1;
    ll count = 0;
    for (ll i = 1; i <= n; i++) {
        if (mp.count(pref[i] - targetSum)) {
            count += mp[pref[i] - targetSum];
        }
        mp[pref[i]]++;
    }
    cout << "Total number of subarrays whose sum is equal to the target sum: " << count << endl;
}

int main() {
    countSubarraysWithTargetSum();
    return 0;
}