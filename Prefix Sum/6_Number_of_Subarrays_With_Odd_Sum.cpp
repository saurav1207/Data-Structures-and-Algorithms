#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int numOfSubarrays(vector<int>& arr) {
    ll n = arr.size();
    vector<ll> pref(n, 0);
    pref[0] = arr[0];

    for (ll i = 1; i < n; i++)
        pref[i] = pref[i - 1] + arr[i];

    ll oddCnt = 0, evenCnt = 1, ans = 0;
    for (int i = 0; i < n; i++) {
        if (pref[i] % 2 == 0) {
            // even value hai, odd subtract karna hai
            ans += oddCnt;
            evenCnt++;
        }
        else {
            // odd value hai, even subtract karna
            ans += evenCnt;
            oddCnt++;
        }
    }
    ll MOD = 1e9 + 7;
    return ans % MOD;
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << numOfSubarrays(arr);
    return 0;
}
