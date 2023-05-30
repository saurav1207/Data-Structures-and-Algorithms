// mid --> kitna distance dur rakhna chahta hu 
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool kyaMainSabkoMidDistanceKiPrivacyDeSaktaHu(vector<ll> &arr, ll mid,ll k){
    ll peechliCowKahaRakhi = arr[0];
    ll kitniCowRakhdi = 1;
    for(ll i=1;i<arr.size();i++){
        if(arr[i]-peechliCowKahaRakhi>=mid){
            peechliCowKahaRakhi = arr[i];
            kitniCowRakhdi++;
        }
        if(kitniCowRakhdi==k) return true;
    }
    return false;
}

int main(){

    ll n; cin>>n;

    vector<ll> arr(n,0);
    for(ll i=0;i<n;i++) cin>>arr[i];
    ll k; cin>>k;

    sort(arr.begin(), arr.end());

    ll lo = 0, hi = arr[n-1]-arr[0], ans = -1;
    // hi = arr[n-1]-arr[0] --> maximum possible distance that can exist between any two cows 
    while(lo<=hi){
        ll mid = (lo+hi)/2;
        if(kyaMainSabkoMidDistanceKiPrivacyDeSaktaHu(arr, mid, k)){
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
Example:
Input:
```
5
1 2 4 8 9
3
```

Output:
```
3
```

Explanation:
In this example, we have 5 cows located at positions 1, 2, 4, 8, and 9. The goal is to find the maximum distance that can be provided between the cows while maintaining privacy. We need to place 3 cows in total.

The code first sorts the array of cow positions in ascending order.

Then, it performs a binary search to find the maximum distance that can be maintained. The binary search iterates as follows:

- Initial `lo` = 0 and `hi` = arr[n-1] - arr[0] = 9 - 1 = 8.
- The mid-point is calculated as (0 + 8) / 2 = 4.
- The function `kyaMainSabkoMidDistanceKiPrivacyDeSaktaHu` is called with the current `mid` value of 4. It checks if it is possible to place 3 cows with a minimum distance of 4 between them.
- The function loops through the array of cow positions and checks if the distance between consecutive cows is greater than or equal to the current `mid` value. If so, it increments the count of placed cows.
- If the count of placed cows is equal to the required number of cows (`k`), the function returns `true`.
- In this case, with `mid` = 4, the function determines that it is possible to place 3 cows with a minimum distance of 4 between them.
- `lo` is updated to 4 (mid + 1).
- The next iteration sets `lo` = 4 and `hi` = 8.
- The mid-point is calculated as (4 + 8) / 2 = 6.
- The function is called again with `mid` = 6, and it returns false since it is not possible to place 3 cows with a minimum distance of 6 between them.
- `hi` is updated to 5 (mid - 1).
- The next iteration sets `lo` = 4 and `hi` = 5.
- The mid-point is calculated as (4 + 5) / 2 = 4.
- The function is called again with `mid` = 4, and it returns true, indicating that it is possible to place 3 cows with a minimum distance of 4 between them.
- `lo` is updated to 5 (mid + 1).
- Since `lo` is now greater than `hi`, the binary search ends.

The final value of `ans` is 4, representing the maximum distance that can be provided between the cows while maintaining privacy. Thus, the output of the code is `4`.
*/