#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool kyaMlengthKiSubarrayExistKartiHaiJiskaSumLessThanEqualToKHai(vector<ll> &arr, vector<ll> &pref, ll n, ll k, ll mid){
    ll sp = 1, ep = mid;
    while(ep<=n){
        ll sum = pref[ep]-pref[sp-1];
        if(sum<=k) return true;
        sp++;
        ep++;
    }
    return false;
}

int main(){
    // freopen("input.txt", "r" ,stdin);
    // freopen("output.txt", "w" ,stdout);

    ll n; cin>>n;

    vector<ll> arr(n+1, 0);
    for(ll i=1;i<=n;i++) cin>>arr[i];

    vector<ll> pref(n+1, 0);
    for(ll i=1;i<=n;i++) pref[i]=pref[i-1]+arr[i];

    ll k; 
    cin>>k;

    ll lo = 0, hi = n, ans = -1;
    while(lo<=hi){
        ll mid = (lo+hi)/2;
        if(kyaMlengthKiSubarrayExistKartiHaiJiskaSumLessThanEqualToKHai(arr, pref, n, k, mid)){
            ans = mid;
            lo = mid+1;
        }
        else{
            hi = mid-1;
        }
    }
    cout<<ans<<endl;
}

/*
Input:
7
1 2 3 4 5 6 7
10

Output:
3


Explanation:
In this example, we have an array of size 7 with elements `1 2 3 4 5 6 7`. The target sum is 10.

The code first calculates the prefix sums of the array: `0 1 3 6 10 15 21 28`. 

Next, it performs a binary search to find the maximum length of a subarray whose sum is less than or equal to 10.

The binary search iterates as follows:
- Initial `lo` = 0 and `hi` = 7.
- The mid-point is calculated as (0 + 7) / 2 = 3.
- The function `kyaMlengthKiSubarrayExistKartiHaiJiskaSumLessThanEqualToKHai` is called with the current `mid` value of 3. It checks if there exists a subarray of length 3 with a sum less than or equal to 10.
- Since such a subarray exists (`1 + 2 + 3 = 6`), `ans` is updated to 3, and `lo` is updated to 4 (mid + 1).
- The next iteration sets `lo` = 4 and `hi` = 7.
- The mid-point is calculated as (4 + 7) / 2 = 5.
- The function is called again with `mid` = 5, and it returns false since there is no subarray of length 5 with a sum less than or equal to 10.
- `hi` is updated to 4 (mid - 1).
- Since `lo` is now greater than `hi`, the binary search ends.

The final value of `ans` is 3, which represents the maximum length of a subarray whose sum is less than or equal to 10.

Thus, the output of the code is `3`.

*/